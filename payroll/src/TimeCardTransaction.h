#pragma once
#include "Transaction.h"
#include "../util/Date.h"

class TimeCardTransaction :
  public Transaction
{
public:
  TimeCardTransaction(Date dt, double hours, int empId);

  void Execute();

private:
  Date itsDate;
  double itsHours{ 0 };
  int itsEmpId{ -1 };
};

