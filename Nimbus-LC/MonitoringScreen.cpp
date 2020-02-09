#include "MonitoringScreen.h"
#include "Observable.h"
#include "TemperatureObserver.h"
#include "BrometricPressureObserver.h"
#include "WeatherStation.h"
#include "WeatherStationComponent.h"

MonitoringScreen::MonitoringScreen(WeatherStationComponent* wsc)
{
  wsc->AddTempObserver(new TemperatureObserver(this));
  wsc->AddBPObserver(new BrometricPressureObserver(this));
}