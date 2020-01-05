#pragma once
#include "Transaction.h"

class DeleteEmployeeTransaction :
  public Transaction
{
public:
  DeleteEmployeeTransaction(int empId);
  void Execute();

private:
  int itsEmpId{ -1 };
};

