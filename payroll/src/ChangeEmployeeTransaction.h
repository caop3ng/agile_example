#pragma once
#include "Transaction.h"

class Employee;

class ChangeEmployeeTransaction :
  public Transaction
{
public:
  ChangeEmployeeTransaction(int empId);
  virtual ~ChangeEmployeeTransaction() {}

  void Execute();

protected:
  virtual void Change(Employee&) = 0;

private:
  int itsEmpId{ -1 };
};

