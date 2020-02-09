#include "Nimbus1_0StationToolkit.h"
#include "Nimbus1_0TemperatureSensor.h"
#include "Nimbus1_0BrometricPressureSensor.h"
#include "Nimbus1_0AlarmClock.h"

TemperatureSensorImp* Nimbus1_0StationToolkit::MakeTemperature()
{
  return new Nimbus1_0TemperatureSensor();
}

BrometricPressureSensorImp* Nimbus1_0StationToolkit::MakeBrometricPressure()
{
  return new Nimbus1_0BrometricPressureSensor();
}

AlarmClockImp* Nimbus1_0StationToolkit::MakeAlarmClock()
{
  return new Nimbus1_0AlarmClock();
}