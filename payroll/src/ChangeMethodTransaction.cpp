#include "ChangeMethodTransaction.h"
#include "Employee.h"

ChangeMethodTransaction::ChangeMethodTransaction(int empId)
  : ChangeEmployeeTransaction(empId)
{
}

ChangeMethodTransaction::~ChangeMethodTransaction()
{
}

void ChangeMethodTransaction::Change(Employee& e)
{
  e.SetMethod(GetMethod());
}