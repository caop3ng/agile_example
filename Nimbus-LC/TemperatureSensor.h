#pragma once

#include <vector>
#include "Observable.h"

class Observer;
class AlarmClock;
class TemperatureSensorImp;
class StationToolkit;

class TemperatureSensor : public Observable
{
public:
  TemperatureSensor(AlarmClock*, StationToolkit* st);

  void check();

  void NotifyObservers(double);

private:
  double last_reading_{ 0 };
  TemperatureSensorImp* tsi_;
};