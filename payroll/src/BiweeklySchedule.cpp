#include "BiweeklySchedule.h"

bool BiweeklySchedule::IsPayDate(Date dt) const
{
  Date firstPayableFriday(11, 9, 2001);
  int daysSinceFirstPayableFriday = dt - firstPayableFriday;

  return (daysSinceFirstPayableFriday % 14) == 0;
}