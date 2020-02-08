#include "TemperatureAlarmListener.h"
#include "TemperatureSensor.h"

void TemperatureAlarmListener::weakup()
{
  ts_->read();
}