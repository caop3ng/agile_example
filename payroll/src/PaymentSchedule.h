#pragma once

#include "../util/Date.h"

class PaymentSchedule
{
public:
  virtual ~PaymentSchedule() {}

  virtual bool IsPayDate(Date) const = 0;
  virtual Date GetPayPeriodStartDate(const Date&) const = 0;
};

