#pragma once

#include "PaymentClassification.h"
#include "../util/Date.h"
#include <vector>

class TimeCard;

class HourlyClassification : public PaymentClassification
{
public:
  HourlyClassification(double hourlyRate);
  ~HourlyClassification();

  double CalculatePay(Paycheck&) const;

  double GetHourlyRate() const;
  void AddTimeCard(TimeCard*);
  TimeCard* GetTimeCard(Date dt) const;

private:

  bool IsInPayPeriod(TimeCard* tc, const Date& payPeriod) const;
  double CalculatePayForTimeCard(TimeCard* tc) const;

  double itsHourlyRate{ -1 };
  std::vector<TimeCard*> itsTimeCards;
};