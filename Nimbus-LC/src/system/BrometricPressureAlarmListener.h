#pragma once
#include "AlarmListener.h"

class BrometricPressureSensor;

class BrometricPressureAlarmListener : public AlarmListener
{
public:
  BrometricPressureAlarmListener(BrometricPressureSensor*);
  void weakup();

private:
  BrometricPressureSensor* bps_{};
};
