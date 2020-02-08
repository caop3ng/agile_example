#pragma once
#include "ChangeMethodTransaction.h"
#include <string>

class ChangeDirectTransaction :
  public ChangeMethodTransaction
{
public:
  ChangeDirectTransaction(int empId);
  ~ChangeDirectTransaction();

protected:

  PaymentMethod* GetMethod();
};

