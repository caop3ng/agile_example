#pragma once

#include "Observer.h"

class MonitoringScreen;

class TemperatureObserver : public Observer
{
public:
  TemperatureObserver(MonitoringScreen*);
  void update(double temp);

private:
  MonitoringScreen* ms_;
};
