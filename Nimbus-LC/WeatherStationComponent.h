#pragma once

class Observer;

class WeatherStationComponent
{
public:
  virtual void AddTempObserver(Observer*) = 0;
  virtual void AddBPObserver(Observer*) = 0;
};
