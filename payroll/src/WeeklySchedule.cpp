#include "WeeklySchedule.h"

bool WeeklySchedule::IsPayDate(Date dt) const
{
  return dt.GetDayOfWeek() == Date::friday;
}

Date WeeklySchedule::GetPayPeriodStartDate(const Date& endDate) const
{
  return endDate - 5;
}