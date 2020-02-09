#include "MonitoringScreen.h"
#include "Observable.h"
#include "TemperatureObserver.h"
#include "BrometricPressureObserver.h"

MonitoringScreen::MonitoringScreen(Observable* obs_temp, Observable* obs_bp, Observable* obs_trend)
{
  obs_temp->AddObserver(new TemperatureObserver(this));
  obs_bp->AddObserver(new BrometricPressureObserver(this));
}