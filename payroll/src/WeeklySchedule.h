#pragma once
#include "PaymentSchedule.h"

class WeeklySchedule :
  public PaymentSchedule
{
public:
  bool IsPayDate(Date) const;
};

