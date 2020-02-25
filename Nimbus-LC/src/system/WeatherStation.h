#pragma once
#include "../ws_component/WeatherStationComponent.h"

class Observer;
class TemperatureSensor;
class BrometricPressureSensor;
class StationToolkit;
class AlarmClock;
class TemperatureHiLo;
class DataToolkit;

class WeatherStation : public WeatherStationComponent
{
public:
  WeatherStation(StationToolkit* st, DataToolkit*);
  void AddTempObserver(Observer*) final;
  void AddBPObserver(Observer*) final;

private:
  AlarmClock* ac_{};
  TemperatureSensor* ts_{};
  BrometricPressureSensor* bps_{};
  TemperatureHiLo* th_{};
};