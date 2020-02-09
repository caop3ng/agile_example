#pragma once
#include "WeatherStationComponent.h"

class Observer;
class TemperatureSensor;
class BrometricPressureSensor;
class StationToolkit;
class AlarmClock;

class WeatherStation : public WeatherStationComponent
{
public:
  WeatherStation(StationToolkit* st);
  void AddTempObserver(Observer*) final;
  void AddBPObserver(Observer*) final;

private:
  AlarmClock* ac_;
  TemperatureSensor* ts_;
  BrometricPressureSensor* bps_;
};