#pragma once

class WeatherStationComponent;

class MonitoringScreen
{
public:

  MonitoringScreen(WeatherStationComponent* wsc);
  virtual void displayTemp(double) = 0;
  virtual void displayPressure(double) = 0;
  virtual void displayPressureTrend(double) = 0;
};
