#include "BrometricPressureAlarmListener.h"
#include "BrometricPressureSensor.h"

BrometricPressureAlarmListener::BrometricPressureAlarmListener(BrometricPressureSensor* bps)
  : bps_(bps)
{
}

void BrometricPressureAlarmListener::weakup()
{
  bps_->check();
}