#pragma once
#include "Observable.h"

class AlarmClock;
class BrometricPressureSensorImp;
class StationToolkit;

class BrometricPressureSensor : public Observable
{
public:
  BrometricPressureSensor(AlarmClock*, StationToolkit* st);
  void check();
  void NotifyObservers(double);

private:
  double last_reading_{ 0 };
  BrometricPressureSensorImp* bpsi_{};
};