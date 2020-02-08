#pragma once

#include "../util/Date.h"
#include "Paycheck.h"

class Affiliation
{
public:
  ~Affiliation() {}

  virtual double GetFee(Date dt) const = 0;
  virtual double CalculateDeduction(Paycheck&) const = 0;
};

