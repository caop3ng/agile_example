#pragma once

#include "Observer.h"

class MonitoringScreen;

class TemperatureObserver : public Observer
{
public:
  void update(double temp);

private:
  MonitoringScreen* ms_;
};
