#include "HourlyClassification.h"
#include "TimeCard.h"

HourlyClassification::HourlyClassification(double hourlyRate)
  : itsHourlyRate(hourlyRate)
{
}

HourlyClassification::~HourlyClassification()
{

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
    if (tc->GetDate().Equal(dt))
    {
      return tc;
    }
  }

  return nullptr;
}