#pragma once
#include "Transaction.h"
#include "../util/Date.h"

class SalesReceiptTransaction :
  public Transaction
{
public:
  SalesReceiptTransaction(Date dt, double amount, int empid);

  void Execute();

private:
  Date itsDate;
  double itsAmount{ -1 };
  int itsEmpid{ -1 };
};

