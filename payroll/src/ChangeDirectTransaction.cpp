#include "ChangeDirectTransaction.h"
#include "DirectMethod.h"

ChangeDirectTransaction::ChangeDirectTransaction(int empId)
  : ChangeMethodTransaction(empId)
{
}

ChangeDirectTransaction::~ChangeDirectTransaction()
{
}


PaymentMethod* ChangeDirectTransaction::GetMethod()
{
  return new DirectMethod();
}