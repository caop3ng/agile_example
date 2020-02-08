#include "TemperatureObserver.h"
#include "MonitoringScreen.h"

void TemperatureObserver::update(double temp)
{
  ms_->displayTemp(temp);
}