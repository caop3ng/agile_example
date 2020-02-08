#pragma once

#include <string>
#include <map>

#include "../util/Date.h"
#include "Transaction.h"

class Paycheck;

class PaydayTransaction :
  public Transaction
{
public:
  PaydayTransaction(Date payDate);

  void Execute();

  Paycheck* GetPaycheck(int empId) const;

protected:
  Date itsPayDate;
  std::map<int, Paycheck*> itsPaychecks;
};

