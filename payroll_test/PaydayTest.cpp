#include <gtest/gtest.h>

#include "all_hearder.h"

TEST(PyadayTest, PaySingleSalariedEmployee)
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

TEST(PyadayTest, PaySingleSalariedEmployeeOnWrongDate)
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

TEST(PyadayTest, PaySingleHourlyEmployeeNoTimeCards)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);
  PaydayTransaction pt(payDate);
  pt.Execute();

  ValidatePaycheck(pt, empId, payDate, 0.0);
}

TEST(PyadayTest, PaySingleHourlyEmployeeOneTimeCard)
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

TEST(PyadayTest, PaySingleHourlyEmployeeOvertimeOneTimeCard)
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

TEST(PyadayTest, PaySingleHourlyEmployeeOnWrongDate)
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

TEST(PyadayTest, PaySingleHourlyEmployeeTwoTimeCards)
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

TEST(PyadayTest, PaySingleHourlyEmployeeWithTimeCardsSpanningTwoPayPeriods)
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