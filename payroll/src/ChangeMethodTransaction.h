#pragma once
#include "ChangeEmployeeTransaction.h"
#include <string>

class PaymentMethod;

class ChangeMethodTransaction :
  public ChangeEmployeeTransaction
{
public:
  ChangeMethodTransaction(int empId);
  ~ChangeMethodTransaction();

protected:
  void Change(Employee&);

  virtual PaymentMethod* GetMethod() = 0;
};

