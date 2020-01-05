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

  double GetHourlyRate() const;
  void AddTimeCard(TimeCard*);
  TimeCard* GetTimeCard(Date dt) const;

private:
  double itsHourlyRate{ -1 };
  std::vector<TimeCard*> itsTimeCards;
};