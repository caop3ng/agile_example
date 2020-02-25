#pragma once

class WeatherStationComponent;

class MonitoringScreen
{
public:

  MonitoringScreen(WeatherStationComponent* wsc);
  void displayTemp(double);
  void displayPressure(double);
};
