#include "Date.h"

Date::Date(int month, int day, int year)
  : itsMonth(month),
  itsDay(day),
  itsYear(year)
{

}

bool Date::Equal(Date& other) const
{
  return (this->itsDay == other.itsDay
    && this->itsMonth == other.itsMonth
    && this->itsYear == other.itsYear);
}