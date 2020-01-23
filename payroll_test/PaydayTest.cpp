#include <gtest/gtest.h>

#include "all_hearder.h"

TEST(PaydayTest, PaySingleSalariedEmployee)
{
  int empId = ++MAX_EMP_ID;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();

  Date payDate(11, 30, 2001);
  PaydayTransaction pt(payDate);
  pt.Execute();

  Paycheck* pc = pt.GetPaycheck(empId);
  EXPECT_NE(pc, nullptr);
  EXPECT_EQ(pc->GetPayDate(), payDate);
  EXPECT_EQ(pc->GetGrossPay(), 1000);
  //EXPECT_EQ(pc->GetField("Disposition"), "Hold");
  EXPECT_EQ(pc->GetDeduction(), 0);
  EXPECT_EQ(pc->GetNetPay(), 1000);
}

TEST(PaydayTest, PaySingleSalariedEmployeeOnWrongDate)
{
  int empId = ++MAX_EMP_ID;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();

  Date payDate(11, 29, 2001);
  PaydayTransaction pt(payDate);
  pt.Execute();

  Paycheck* pc = pt.GetPaycheck(empId);
  EXPECT_EQ(pc, nullptr);
}

void ValidatePaycheck(PaydayTransaction& pt, int empId, const Date& payDate, double pay)
{
  Paycheck* pc = pt.GetPaycheck(empId);
  EXPECT_NE(pc, nullptr);
  //EXPECT_EQ(pc->GetPayPeriodEndDate(), payDate);
  EXPECT_EQ(pc->GetGrossPay(), pay);
  //EXPECT_EQ(pc->GetField("Disposition") == "Hold");
  EXPECT_EQ(pc->GetDeduction(), 0);
  EXPECT_EQ(pc->GetNetPay(), pay);
}

TEST(PaydayTest, PaySingleHourlyEmployeeNoTimeCards)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);
  PaydayTransaction pt(payDate);
  pt.Execute();

  ValidatePaycheck(pt, empId, payDate, 0.0);
}

TEST(PaydayTest, PaySingleHourlyEmployeeOneTimeCard)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);

  TimeCardTransaction tc(payDate, 2.0, empId);
  tc.Execute();

  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, 30.5);
}

TEST(PaydayTest, PaySingleHourlyEmployeeOvertimeOneTimeCard)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);

  TimeCardTransaction tc(payDate, 9.0, empId);
  tc.Execute();

  PaydayTransaction pt(payDate);
  pt.Execute();
  ValidatePaycheck(pt, empId, payDate, (8 + 1.5) * 15.25);
}

TEST(PaydayTest, PaySingleHourlyEmployeeOnWrongDate)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 8, 2001);

  TimeCardTransaction tc(payDate, 9.0, empId);
  tc.Execute();

  PaydayTransaction pt(payDate);
  pt.Execute();

  Paycheck* pc = pt.GetPaycheck(empId);
  EXPECT_EQ(pc, nullptr);
}

TEST(PaydayTest, PaySingleHourlyEmployeeTwoTimeCards)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);

  TimeCardTransaction tc(payDate, 2.0, empId);
  tc.Execute();

  TimeCardTransaction tc2(Date(11, 8, 2001), 5.0, empId);
  tc2.Execute();

  PaydayTransaction pt(payDate);
  pt.Execute();

  ValidatePaycheck(pt, empId, payDate, 7 * 15.25);
}

TEST(PaydayTest, PaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods)
{
  GpayrollDatabase.clear();

  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);
  Date dateInPreviousPayPeriod(11, 2, 2011);

  TimeCardTransaction tc(payDate, 2.0, empId);
  tc.Execute();

  TimeCardTransaction tc2(dateInPreviousPayPeriod, 5.0, empId);
  tc2.Execute();

  PaydayTransaction pt(payDate);
  pt.Execute();

  ValidatePaycheck(pt, empId, payDate, 2 * 15.25);
}

TEST(PaydayTest, PaySingleCommissionedEmployeeNoSalesReceipt)
{
  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "xxx", "home", 2000, 20.5);
  t.Execute();

  Date payDate(11, 9, 2001);
  PaydayTransaction pt(payDate);
  pt.Execute();

  auto pc = pt.GetPaycheck(empId);
  EXPECT_EQ(pc->GetGrossPay(), 2000);
}

TEST(PaydayTest, PaySingleCommissionedEmployeeOneSalesReceipt)
{
  GpayrollDatabase.clear();

  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "xxx", "home", 2000, 0.20);
  t.Execute();

  Date d1(1, 16, 2020);
  SalesReceiptTransaction srt(d1, 500, empId);
  srt.Execute();

  Date payDate(1, 24, 2020);
  PaydayTransaction pt(payDate);
  pt.Execute();

  auto pc = pt.GetPaycheck(empId);
  EXPECT_NE(pc, nullptr);
  EXPECT_EQ(pc->GetGrossPay(), 2000 + 500*0.20);
}

TEST(PaydayTest, PaySingleCommissionedEmployeeTwoSalesReceipt)
{
  GpayrollDatabase.clear();

  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "xxx", "home", 2000, 0.20);
  t.Execute();

  Date d1(1, 16, 2020);
  SalesReceiptTransaction srt(d1, 500, empId);
  srt.Execute();

  Date d2(1, 17, 2020);
  SalesReceiptTransaction srt2(d2, 1000, empId);
  srt2.Execute();

  Date payDate(1, 24, 2020);
  PaydayTransaction pt(payDate);
  pt.Execute();

  auto pc = pt.GetPaycheck(empId);
  EXPECT_NE(pc, nullptr);
  EXPECT_EQ(pc->GetGrossPay(), 2000 + (500 + 1000) * 0.20);
}

TEST(PaydayTest, PaySingleCommissionedEmployeeWrongPayDate)
{
  GpayrollDatabase.clear();

  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "xxx", "home", 2000, 0.20);
  t.Execute();

  Date d1(1, 16, 2020);
  SalesReceiptTransaction srt(d1, 500, empId);
  srt.Execute();

  Date payDate(1, 25, 2020);
  PaydayTransaction pt(payDate);
  pt.Execute();

  auto pc = pt.GetPaycheck(empId);
  EXPECT_EQ(pc, nullptr);
}