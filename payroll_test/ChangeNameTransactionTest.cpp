#include <gtest/gtest.h>
#include "all_hearder.h"

#include "AddHourlyEmployee.h"
#include "ChangeNameTransaction.h"

TEST(Payroll, ChangeName)
{
  int empId = ++MAX_EMP_ID;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  ChangeNameTransaction cnt(empId, "Bob");
  cnt.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_NE(e, nullptr);
  EXPECT_EQ(e->GetName(), "Bob");
}