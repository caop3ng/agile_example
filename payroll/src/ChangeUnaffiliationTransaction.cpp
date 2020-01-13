#include "ChangeUnaffiliationTransaction.h"
#include "Employee.h"

#include "UnionAffiliation.h"
#include "PayrollDatabase.h"
#include "NoAffiliation.h"

extern PayrollDatabase GpayrollDatabase;

ChangeUnaffiliationTransaction::ChangeUnaffiliationTransaction(int empId)
  : ChangeAffiliationTransaction(empId)
{

}

ChangeUnaffiliationTransaction::~ChangeUnaffiliationTransaction()
{
}

Affiliation* ChangeUnaffiliationTransaction::GetAffiliation()
{
  return new NoAffiliation();
}

void ChangeUnaffiliationTransaction::RecordMembership(Employee* e)
{
  auto af = e->GetAffiliation();
  if (auto uf = dynamic_cast<UnionAffiliation*>(af))
  {
    int memberId = uf->GetMemberId();
    GpayrollDatabase.RemoveUnionMember(memberId);
  }
}