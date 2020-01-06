#pragma once

#include "../util/Date.h"

class ServiceCharge
{
public:
  ServiceCharge(Date dt, double amount);

  Date GetDate() const;
  double GetAmount() const;

private:
  Date itsDate;
  double itsAmount{ -1 };
};

