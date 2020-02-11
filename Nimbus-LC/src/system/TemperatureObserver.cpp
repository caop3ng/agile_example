#include "TemperatureObserver.h"
#include "../ui/MonitoringScreen.h"

TemperatureObserver::TemperatureObserver(MonitoringScreen* ms)
  : ms_(ms)
{

}

void TemperatureObserver::update(double temp)
{
  ms_->displayTemp(temp);
}