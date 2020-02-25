#include "Nimbus1_0StationToolkit.h"
#include "Nimbus1_0TemperatureSensor.h"
#include "Nimbus1_0BrometricPressureSensor.h"
#include "Nimbus1_0AlarmClock.h"
#include "Nimbus1_0Persistent.h"

TemperatureSensorImp* Nimbus1_0StationToolkit::MakeTemperature()
{
  if (!tsi_)
  {
    tsi_ = new Nimbus1_0TemperatureSensor();
  }

  return tsi_;
}

BrometricPressureSensorImp* Nimbus1_0StationToolkit::MakeBrometricPressure()
{
  if (!bps_)
  {
    bps_ = new Nimbus1_0BrometricPressureSensor();
  }

  return bps_;
}

AlarmClockImp* Nimbus1_0StationToolkit::MakeAlarmClock()
{
  if (!ac_)
  {
    ac_ = new Nimbus1_0AlarmClock();
  }

  return ac_;
}

PersistentImp* Nimbus1_0StationToolkit::MakePersistentImp()
{
  if (!pi_)
  {
    pi_ = new Nimbus1_0PersistentImp();
  }

  return pi_;
}