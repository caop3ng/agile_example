#include "BrometricPressureObserver.h"
#include "MonitoringScreen.h"

void BrometricPressureObserver::update(double temp)
{
  ms_->displayPressure(temp);
}