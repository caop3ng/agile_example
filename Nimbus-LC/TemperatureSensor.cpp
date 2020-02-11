#include "TemperatureSensor.h"
#include "Observer.h"
#include "AlarmClock.h"
#include "TemperatureAlarmListener.h"
#include "TemperatureSensorImp.h"
#include "StationToolkit.h"

TemperatureSensor::TemperatureSensor(AlarmClock* ac, StationToolkit* st)
{
  tsi_ = st->MakeTemperature();

  ac->wakeEvery(500, new TemperatureAlarmListener(this));
}

void TemperatureSensor::check()
{
  double val = read();

  if (val != last_reading_)
  {
    last_reading_ = val;
    NotifyObservers(last_reading_);
  }
}

double TemperatureSensor::read()
{
  return tsi_->read();
}

void TemperatureSensor::NotifyObservers(double temp)
{
  for (const auto& obs : observers_)
  {
    obs->update(temp);
  }
}