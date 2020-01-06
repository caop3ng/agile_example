#pragma once

#include "../util/Date.h"

class Affiliation
{
public:
  ~Affiliation() {}

  virtual double GetFee(Date dt) const = 0;
};

