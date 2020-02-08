#pragma once

class Observable;

class MonitoringScreen
{
public:

  MonitoringScreen(Observable* obs_temp, Observable* obs_bp, Observable* obs_trend);
  virtual void displayTemp(double) = 0;
  virtual void displayPressure(double) = 0;
  virtual void displayPressureTrend(double) = 0;
};
