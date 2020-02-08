#include "ChangeMemberTransaction.h"
#include "Employee.h"

#include "UnionAffiliation.h"
#include "PayrollDatabase.h"

extern PayrollDatabase GpayrollDatabase;

ChangeMemberTransaction::ChangeMemberTransaction(int empId, int memberId, double dues)
  : ChangeAffiliationTransaction(empId),
  itsMemberId(memberId),
  itsDues(dues)
{

}

ChangeMemberTransaction::~ChangeMemberTransaction()
{

}

Affiliation* ChangeMemberTransaction::GetAffiliation()
{
  return new UnionAffiliation(itsMemberId, itsDues);
}

void ChangeMemberTransaction::RecordMembership(Employee* e)
{
  GpayrollDatabase.AddUnionMember(itsMemberId, e);
}