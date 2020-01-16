#include "HourlyClassification.h"
#include "TimeCard.h"

#include <algorithm>

HourlyClassification::HourlyClassification(double hourlyRate)
  : itsHourlyRate(hourlyRate)
{
}

HourlyClassification::~HourlyClassification()
{

}

double HourlyClassification::CalculatePay(Paycheck& pc) const
{
  double sum = 0;
  Date payPeriod = pc.GetPayDate();

  for (auto tc : itsTimeCards)
  {
    if (IsInPayPeriod(tc, payPeriod))
    {
      sum += CalculatePayForTimeCard(tc);
    }
  }

  return sum;
}

double HourlyClassification::CalculatePayForTimeCard(TimeCard* tc) const
{
  double hours = tc->GetHours();
  double overtime = std::max(0.0, hours - 8);
  double straightTime = hours - overtime;
  return straightTime * itsHourlyRate + overtime * itsHourlyRate * 1.5;
}

bool HourlyClassification::IsInPayPeriod(TimeCard* tc, const Date& payPeriod) const
{
  Date payPeriodEndDate = payPeriod;
  Date payPeriodStartDate = payPeriod - 5;
  Date timeCardDate = tc->GetDate();

  return (timeCardDate >= payPeriodStartDate)
    && (timeCardDate <= payPeriodEndDate);
}

double HourlyClassification::GetHourlyRate() const
{
  return itsHourlyRate;
}

void HourlyClassification::AddTimeCard(TimeCard* tc)
{
  itsTimeCards.push_back(tc);
}

TimeCard* HourlyClassification::GetTimeCard(Date dt) const
{
  for (const auto& tc : itsTimeCards)
  {
    if (tc->GetDate() == dt)
    {
      return tc;
    }
  }

  return nullptr;
}