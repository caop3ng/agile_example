#pragma once
#include "PaymentMethod.h"
class HoldMethod :
  public PaymentMethod
{
public:
  void Pay(Paycheck&) const;
};

