#pragma once
#include "MonitoringScreen.h"

class TestScreen : public MonitoringScreen
{
public:
  TestScreen(Observable* obs_temp, Observable* obs_bp, Observable* obs_trend);

  void displayTemp(double) final;
  void displayPressure(double) final;
  void displayPressureTrend(double) final;
};