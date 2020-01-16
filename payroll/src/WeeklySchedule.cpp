#include "WeeklySchedule.h"

bool WeeklySchedule::IsPayDate(Date dt) const
{
  return dt.GetDayOfWeek() == Date::friday;
}
