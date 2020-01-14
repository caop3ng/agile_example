#pragma once

#include "Paycheck.h"

class PaymentMethod
{
public:
  virtual ~PaymentMethod()
  {
  }

  virtual void Pay(Paycheck&) const = 0;
};

