#include <gtest/gtest.h>

#include "Employee.h"
#include "AddCommissionedEmployee.h"
#include "PayrollDatabase.h"
#include "HoldMethod.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"

extern PayrollDatabase GpayrollDatabase;

TEST(Payroll, AddCommissionedEmployee)
{
  int empId = 2;
  AddCommissionedEmployee t(empId, "qqq", "home", 1000, 0.2);
  t.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);
  EXPECT_EQ(e->GetName(), "qqq");

  auto pc = e->GetClassification();
  auto cc = dynamic_cast<CommissionedClassification*>(pc);
  EXPECT_TRUE(cc != nullptr);
  EXPECT_EQ(cc->GetSalary(), 1000);
  EXPECT_EQ(cc->GetCommissionRate(), 0.2);

  auto ps = e->GetSchedule();
  EXPECT_TRUE(dynamic_cast<BiweeklySchedule*>(ps) != nullptr);

  auto pm = e->GetMethod();
  EXPECT_TRUE(dynamic_cast<HoldMethod*>(pm) != nullptr);
}