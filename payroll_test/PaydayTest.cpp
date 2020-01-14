#include <gtest/gtest.h>

#include "all_hearder.h"

TEST(Payroll, PaySingleSalariedEmployee)
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

TEST(Payroll, PaySingleSalariedEmployeeOnWrongDate)
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
  EXPECT_EQ(pc->GetPayPeriodEndDate() == payDate);
  EXPECT_EQ(pc->GetGrossPay(), pay);
  //EXPECT_EQ(pc->GetField("Disposition") == "Hold");
  EXPECT_EQ(pc->GetDeduction(), 0);
  EXPECT_EQ(pc->GetNetPay(), pay);
}

TEST(Payroll, PaySingleHourlyEmployeeNoTimeCards)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  Date payDate(11, 9, 2001);
  PaydayTransaction pt(payDate);
  pt.Execute();

  ValidatePaycheck(pt, empId, payDate, 0.0);
}