#include "MonthlySchedule.h"


namespace
{
  bool IsLastDayOfMonth(const Date& dt)
  {
    int m1 = dt.GetMonth();
    int m2 = (dt + 1).GetMonth();
    return (m1 != m2);
  }
}

bool MonthlySchedule::IsPayDate(Date dt) const
{
  return IsLastDayOfMonth(dt);
}

Date MonthlySchedule::GetPayPeriodStartDate(const Date& endDate) const
{
  return Date(endDate.GetMonth(), 1, endDate.GetYear());
}