#include "ChangeNameTransaction.h"
#include "Employee.h"

ChangeNameTransaction::ChangeNameTransaction(int empId, std::string name)
  : ChangeEmployeeTransaction(empId),
  itsName(name)
{
}

void ChangeNameTransaction::Change(Employee& e)
{
  e.SetName(itsName);
}