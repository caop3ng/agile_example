#include "BrometricPressureObserver.h"
#include "../ui/MonitoringScreen.h"

BrometricPressureObserver::BrometricPressureObserver(MonitoringScreen* ms)
  : ms_(ms)
{

}

void BrometricPressureObserver::update(double temp)
{
  ms_->displayPressure(temp);
}