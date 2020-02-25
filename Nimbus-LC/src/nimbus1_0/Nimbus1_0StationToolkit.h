#pragma once
#include "../api/StationToolkit.h"

class TemperatureSensorImp;
class BrometricPressureSensorImp;
class AlarmClockImp;
class PersistentImp;

class Nimbus1_0StationToolkit : public StationToolkit
{
public:
  TemperatureSensorImp* MakeTemperature() final;
  BrometricPressureSensorImp* MakeBrometricPressure() final;
  AlarmClockImp* MakeAlarmClock() final;
  PersistentImp* MakePersistentImp() final;

private:
  TemperatureSensorImp* tsi_{};
  BrometricPressureSensorImp* bps_{};
  AlarmClockImp* ac_{};
  PersistentImp* pi_{};
};
