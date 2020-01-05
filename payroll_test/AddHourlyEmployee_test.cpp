#include <gtest/gtest.h>

#include "Employee.h"
#include "AddHourlyEmployee.h"
#include "PayrollDatabase.h"
#include "HoldMethod.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"

extern PayrollDatabase GpayrollDatabase;

TEST(Payroll, AddHourlyEmployee)
{
  int empId = 2;
  AddHourlyEmployee t(empId, "xxx", "home", 50);
  t.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);
  EXPECT_EQ(e->GetName(), "xxx");

  auto pc = e->GetClassification();
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  EXPECT_TRUE(hc != nullptr);
  EXPECT_EQ(hc->GetHourlyRate(), 50);

  auto ps = e->GetSchedule();
  EXPECT_TRUE(dynamic_cast<WeeklySchedule*>(ps) != nullptr);

  auto pm = e->GetMethod();
  EXPECT_TRUE(dynamic_cast<HoldMethod*>(pm) != nullptr);
}