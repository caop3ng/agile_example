#pragma once
#include "PaymentSchedule.h"

class MonthlySchedule :
  public PaymentSchedule
{
public:
  bool IsPayDate(Date) const;
};

