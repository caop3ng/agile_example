#include "PaymentClassification.h"

bool PaymentClassification::IsInPayPeriod(const Date& theDate, const Paycheck& pc) const
{
  auto start = pc.GetPayPeriodStartDate();
  auto end = pc.GetPayPeriodEndDate();

  return (start <= theDate && theDate <= end);
}