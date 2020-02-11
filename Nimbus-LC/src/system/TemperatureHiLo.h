#pragma once
#include "Observer.h"
#include "AlarmListener.h"

class AlarmClock;
class StationToolkit;
class DataToolkit;
class HiLoData;
class TemperatureSensor;

class TemperatureHiLo: public Observer, public AlarmListener
{
public:
  TemperatureHiLo(AlarmClock*, StationToolkit*, TemperatureSensor* ts, DataToolkit*);

  void update(double);

  void weakup();

private:
  HiLoData* hd_{};
  TemperatureSensor* ts_{};
};
