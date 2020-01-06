#include "ChangeEmployeeTransaction.h"
#include "PayrollDatabase.h"

extern PayrollDatabase GpayrollDatabase;

ChangeEmployeeTransaction::ChangeEmployeeTransaction(int empId)
  : itsEmpId(empId)
{
}

void ChangeEmployeeTransaction::Execute()
{
  auto e = GpayrollDatabase.GetEmployee(itsEmpId);
  if (e)
  {
    Change(*e);
  }
}
