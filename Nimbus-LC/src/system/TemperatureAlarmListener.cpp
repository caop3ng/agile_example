#include "TemperatureAlarmListener.h"
#include "TemperatureSensor.h"

TemperatureAlarmListener::TemperatureAlarmListener(TemperatureSensor* ts)
  : ts_(ts)
{
}

void TemperatureAlarmListener::weakup()
{
  ts_->check();
}