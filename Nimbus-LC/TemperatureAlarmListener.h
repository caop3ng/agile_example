#pragma once
#include "AlarmListener.h"

class TemperatureSensor;

class TemperatureAlarmListener : public AlarmListener
{
public:
  void weakup();

private:
  TemperatureSensor* ts_;
};