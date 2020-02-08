#include <gtest\gtest.h>
#include "all_hearder.h"

TEST(Payroll, ChangeUnionAffiliation)
{
  int empId = ++MAX_EMP_ID;
  int memberId = 7734;

  AddHourlyEmployee t(empId, "uuu", "home", 80);
  t.Execute();

  ChangeMemberTransaction cmt(empId, memberId, 99.42);
  cmt.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_NE(e, nullptr);
  
  auto af = e->GetAffiliation();
  EXPECT_NE(af, nullptr);

  auto uf = dynamic_cast<UnionAffiliation*>(af);
  EXPECT_NE(uf, nullptr);
  EXPECT_EQ(uf->GetDues(), 99.42);

  auto member = GpayrollDatabase.GetUnionMember(memberId);
  EXPECT_NE(member, nullptr);
  EXPECT_EQ(e, member);
}

TEST(Payroll, ChangeUnaffiliation)
{
  int empId = ++MAX_EMP_ID;
  int memberId = 7777;

  AddHourlyEmployee t(empId, "uuu", "home", 80);
  t.Execute();

  ChangeMemberTransaction cmt(empId, memberId, 99.42);
  cmt.Execute();

  auto e = GpayrollDatabase.GetEmployee(empId);
  EXPECT_NE(e, nullptr);

  auto member = GpayrollDatabase.GetUnionMember(memberId);
  EXPECT_NE(member, nullptr);
  EXPECT_EQ(e, member);

  ChangeUnaffiliationTransaction cut(empId);
  cut.Execute();

  auto nf = dynamic_cast<NoAffiliation*>(e->GetAffiliation());
  EXPECT_NE(nf, nullptr);

  auto m = GpayrollDatabase.GetUnionMember(memberId);
  EXPECT_EQ(m, nullptr);
}