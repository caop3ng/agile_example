#include <gtest/gtest.h>

#include "AddCommissionedEmployee.h"
#include "PayrollDatabase.h"
#include "DeleteEmployeeTransaction.h"
#include "all_hearder.h"

extern PayrollDatabase GpayrollDatabase;

TEST(Payroll, DeleteEmployee)
{
  int empId = ++MAX_EMP_ID;
  AddCommissionedEmployee t(empId, "Lance", "Home", 2500, 3.2);
  t.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);

  DeleteEmployeeTransaction dt(empId);
  dt.Execute();

  e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_EQ(e, nullptr);
}