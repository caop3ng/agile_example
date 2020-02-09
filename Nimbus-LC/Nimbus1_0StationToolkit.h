#pragma once
#include "StationToolkit.h"

class Nimbus1_0StationToolkit : public StationToolkit
{
public:
  TemperatureSensorImp* MakeTemperature() final;
  BrometricPressureSensorImp* MakeBrometricPressure() final;
  AlarmClockImp* MakeAlarmClock() final;
};
