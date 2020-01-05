#include <gtest/gtest.h>
#include "all_hearder.h"

#include "AddHourlyEmployee.h"
#include "TimeCardTransaction.h"

TEST(Payroll, AddTimeCard)
{
  int empId = 4;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  TimeCardTransaction tct(Date(10, 31, 2001), 8.0, empId);
  tct.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);

  auto pc = e->GetClassification();
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  EXPECT_TRUE(hc != nullptr);

  auto tc = hc->GetTimeCard(Date(10, 31, 2001));
  EXPECT_TRUE(tc != nullptr);
  EXPECT_EQ(8.0, tc->GetHours());
}