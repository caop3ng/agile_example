#include "TimeCard.h"

TimeCard::TimeCard(Date dt, double hours)
  : itsDate(dt),
  itsHours(hours)
{

}

Date TimeCard::GetDate() const
{
  return itsDate;
}

double TimeCard::GetHours() const
{
  return itsHours;
}