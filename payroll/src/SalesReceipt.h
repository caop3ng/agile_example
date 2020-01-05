#pragma once

#include "../util/Date.h"

class SalesReceipt
{
public:
  SalesReceipt(Date dt, double amount);

  double GetAmount() const;
  Date GetDate() const;

private:
  Date itsDate;
  double itsAmount{ -1 };
};

