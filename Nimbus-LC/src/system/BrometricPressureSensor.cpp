#include "BrometricPressureSensor.h"
#include "Observer.h"
#include "AlarmClock.h"
#include "../api/BrometricPressureSensorImp.h"
#include "BrometricPressureAlarmListener.h"
#include "../api/StationToolkit.h"

BrometricPressureSensor::BrometricPressureSensor(AlarmClock* ac, StationToolkit* st)
{
  bpsi_ = st->MakeBrometricPressure();

  ac->wakeEvery(1000, new BrometricPressureAlarmListener(this));
}

void BrometricPressureSensor::check()
{
  auto val = bpsi_->read();
  if (val != last_reading_)
  {
    last_reading_ = val;
    NotifyObservers(last_reading_);
  }
}

void BrometricPressureSensor::NotifyObservers(double pb)
{
  for (const auto& obs : observers_)
  {
    obs->update(pb);
  }
}