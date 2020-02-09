#pragma once

#include "Observer.h"

class MonitoringScreen;

class BrometricPressureObserver : public Observer
{
public:
  BrometricPressureObserver(MonitoringScreen*);
  void update(double temp);

private:
  MonitoringScreen* ms_;
};
