#pragma once
#include "PaymentSchedule.h"
class BiweeklySchedule :
  public PaymentSchedule
{
public:
  bool IsPayDate(Date) const;
  Date GetPayPeriodStartDate(const Date&) const;
};

