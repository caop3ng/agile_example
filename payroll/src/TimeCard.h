#pragma once

#include "../util/Date.h"

class TimeCard
{
public:
  TimeCard(Date dt, double hours);

  Date GetDate() const;
  double GetHours() const;

private:
  Date itsDate;
  double itsHours{ 0 };
};

