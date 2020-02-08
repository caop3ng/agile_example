#pragma once

#include <vector>
#include "Observable.h"

class Observer;
class AlarmClock;

class TemperatureSensor : public Observable
{
public:
  TemperatureSensor(AlarmClock*);

  virtual double read();

  void NotifyObservers(double);
};