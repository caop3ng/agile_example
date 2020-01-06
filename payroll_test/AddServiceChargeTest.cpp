#include <gtest/gtest.h>
#include "all_hearder.h"

#include "AddHourlyEmployee.h"
#include "UnionAffiliation.h"
#include "ServiceChargeTransaction.h"
#include "ServiceCharge.h"

TEST(Payroll, AddServiceCharge)
{
  int empId = 6;
  AddHourlyEmployee t(empId, "Bill", "Home", 15.25);
  t.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_TRUE(e != nullptr);

  int memberId = 86;
  UnionAffiliation* af = new UnionAffiliation(memberId, 12.5);
  e->SetAffiliation(af);

  GpayrollDatabase.AddUnionMember(memberId, e);

  ServiceChargeTransaction sct(memberId, Date(11, 1, 2001), 12.95);
  sct.Execute();

  auto sc = af->GetServiceCharge(Date(11, 1, 2001));
  EXPECT_NE(sc, nullptr);
  EXPECT_EQ(sc->GetAmount(), 12.95);
}