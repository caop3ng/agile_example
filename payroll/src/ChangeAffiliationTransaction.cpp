#include "ChangeAffiliationTransaction.h"
#include "Employee.h"

ChangeAffiliationTransaction::ChangeAffiliationTransaction(int empId)
  : ChangeEmployeeTransaction(empId)
{
}

ChangeAffiliationTransaction::~ChangeAffiliationTransaction()
{

}

void ChangeAffiliationTransaction::Change(Employee& e)
{
  RecordMembership(&e);
  e.SetAffiliation(GetAffiliation());
}
