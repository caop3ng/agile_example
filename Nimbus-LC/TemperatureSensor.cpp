#include "TemperatureSensor.h"
#include "Observer.h"
#include "AlarmClock.h"
#include "TemperatureAlarmListener.h"

TemperatureSensor::TemperatureSensor(AlarmClock* ac)
{
  ac->wakeEvery(50, new TemperatureAlarmListener());
}

double TemperatureSensor::read()
{
  double temp = 20.5;
  NotifyObservers(temp);
  return temp;
}

void TemperatureSensor::NotifyObservers(double temp)
{
  for (const auto& obs : observers_)
  {
    obs->update(temp);
  }
}