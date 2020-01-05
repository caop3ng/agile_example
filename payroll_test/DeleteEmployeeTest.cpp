#include <gtest/gtest.h>

#include "AddCommissionedEmployee.h"
#include "PayrollDatabase.h"
#include "DeleteEmployeeTransaction.h"

extern PayrollDatabase GpayrollDatabase;

TEST(Payroll, DeleteEmployee)
{
  int empId = 3;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);

  DeleteEmployeeTransaction dt(empId);
  dt.Execute();

  e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_EQ(e, nullptr);
}