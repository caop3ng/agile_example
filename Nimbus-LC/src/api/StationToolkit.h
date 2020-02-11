#pragma once

class TemperatureSensorImp;
class BrometricPressureSensorImp;
class AlarmClockImp;
class PersistentImp;

class StationToolkit
{
public:
  virtual TemperatureSensorImp* MakeTemperature() = 0;
  virtual BrometricPressureSensorImp* MakeBrometricPressure() = 0;
  virtual AlarmClockImp* MakeAlarmClock() = 0;
  virtual PersistentImp* MakePersistentImp() = 0;
};
