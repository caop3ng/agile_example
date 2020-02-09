#pragma once
#include "AlarmListener.h"

class TemperatureSensor;

class TemperatureAlarmListener : public AlarmListener
{
public:
  TemperatureAlarmListener(TemperatureSensor* ts);
  void weakup();

private:
  TemperatureSensor* ts_;
};