#pragma once

#include "Paycheck.h"

class PaymentClassification
{
public:
  virtual ~PaymentClassification() {}

  virtual double CalculatePay(Paycheck&) const = 0;
};
