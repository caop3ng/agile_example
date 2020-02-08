#pragma once
#include "PaymentMethod.h"
class DirectMethod :
  public PaymentMethod
{
public:
  void Pay(Paycheck&) const;
};

