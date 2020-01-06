#pragma once
#include "Transaction.h"

#include "../util/Date.h"

class ServiceChargeTransaction :
  public Transaction
{
public:
  ServiceChargeTransaction(int memberId, Date dt, double amount);
  void Execute();

private:
  int itsMemberId{ -1 };
  Date itsDate;
  double itsAmount{ -1 };
};

