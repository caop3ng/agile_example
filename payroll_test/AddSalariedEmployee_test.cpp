#include <gtest/gtest.h>

#include "Employee.h"
#include "AddSalariedEmployee.h"
#include "PayrollDatabase.h"
#include "HoldMethod.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"

extern PayrollDatabase GpayrollDatabase;

TEST(Payroll, AddSalariedEmployee)
{
  int empId = 1;
  AddSalariedEmployee t(empId, "Bob", "Home", 1000.00);
  t.Execute();

  Employee* e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_EQ(e->GetName(), "Bob");

  PaymentClassification* pc = e->GetClassification();
  SalariedClassification* sc = dynamic_cast<SalariedClassification*>(pc);
  EXPECT_TRUE(sc != nullptr);

  EXPECT_EQ(1000, sc->GetSalary());
  PaymentSchedule* ps = e->GetSchedule();
  MonthlySchedule* ms = dynamic_cast<MonthlySchedule*>(ps);
  EXPECT_TRUE(ms != nullptr);

  PaymentMethod* pm = e->GetMethod();

  HoldMethod* hm = dynamic_cast<HoldMethod*>(pm);

  EXPECT_TRUE(hm != nullptr);
}