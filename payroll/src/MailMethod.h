#pragma once
#include "PaymentMethod.h"
class MailMethod :
  public PaymentMethod
{
public:
  void Pay(Paycheck&) const;
};

