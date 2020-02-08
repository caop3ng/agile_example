#include "BrometricPressureSensor.h"
#include "Observer.h"

void BrometricPressureSensor::read()
{
  auto bp = 100;
  NotifyObservers(bp);
}

void BrometricPressureSensor::NotifyObservers(double pb)
{
  for (const auto& obs : observers_)
  {
    obs->update(pb);
  }
}