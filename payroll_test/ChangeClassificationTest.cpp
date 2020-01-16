#include <gtest/gtest.h>

#include "all_hearder.h"

TEST(ChangeClassification, ChangeHourlyClassification)
{
  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();

  ChangeHourlyTransaction cht(empId, 27.52);
  cht.Execute();

  Employee* e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_NE(e, nullptr);

  auto pc = e->GetClassification();
  EXPECT_NE(e, nullptr);
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  EXPECT_NE(hc, nullptr);
  EXPECT_EQ(27.52, hc->GetHourlyRate());
  
  auto ps = e->GetSchedule();
  auto ws = dynamic_cast<WeeklySchedule*>(ps);
  EXPECT_NE(ws, nullptr);
}

TEST(ChangeClassification, ChangeSalariedClassification)
{
  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "PPP", "Home", 2500, 3.2);
  t.Execute();

  ChangeSalariedTransaction cst(empId, 10050.50);
  cst.Execute();

  Employee* e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_NE(e, nullptr);

  auto pc = e->GetClassification();
  EXPECT_NE(e, nullptr);
  auto sc = dynamic_cast<SalariedClassification*>(pc);
  EXPECT_NE(sc, nullptr);
  EXPECT_EQ(10050.5, sc->GetSalary());

  auto ps = e->GetSchedule();
  auto ms = dynamic_cast<MonthlySchedule*>(ps);
  EXPECT_NE(ms, nullptr);
}

TEST(ChangeClassification, ChangeCommissionedClassification)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "XXX", "Home", 20);
  t.Execute();

  ChangeCommissionedTransaction cst(empId, 10050.50, 30);
  cst.Execute();

  Employee* e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_NE(e, nullptr);

  auto pc = e->GetClassification();
  EXPECT_NE(e, nullptr);
  auto cc = dynamic_cast<CommissionedClassification*>(pc);
  EXPECT_NE(cc, nullptr);
  EXPECT_EQ(10050.5, cc->GetSalary());
  EXPECT_EQ(30, cc->GetCommissionRate());

  auto ps = e->GetSchedule();
  auto bs = dynamic_cast<BiweeklySchedule*>(ps);
  EXPECT_NE(bs, nullptr);
}
