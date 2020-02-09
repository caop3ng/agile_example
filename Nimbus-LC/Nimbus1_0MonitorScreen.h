#pragma once
#include "MonitoringScreen.h"

class Nimbus1_0MonitorScreen : public MonitoringScreen
{
public:
  Nimbus1_0MonitorScreen(WeatherStationComponent*);

  void displayTemp(double) final;
  void displayPressure(double) final;
  void displayPressureTrend(double) final;
};