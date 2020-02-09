#include "TemperatureObserver.h"
#include "MonitoringScreen.h"

TemperatureObserver::TemperatureObserver(MonitoringScreen* ms)
  : ms_(ms)
{

}

void TemperatureObserver::update(double temp)
{
  ms_->displayTemp(temp);
}