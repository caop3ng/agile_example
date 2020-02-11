#include <iostream>
#include "MonitoringScreen.h"
#include "../system/TemperatureObserver.h"
#include "../system/BrometricPressureObserver.h"
#include "../system/WeatherStation.h"
#include "../ws_component/WeatherStationComponent.h"

using namespace std;

MonitoringScreen::MonitoringScreen(WeatherStationComponent* wsc)
{
  wsc->AddTempObserver(new TemperatureObserver(this));
  wsc->AddBPObserver(new BrometricPressureObserver(this));
}

void MonitoringScreen::displayTemp(double t)
{
  cout << "Temp: " << t << endl;
}

void MonitoringScreen::displayPressure(double pres)
{
  cout << "Pressure: " << pres << endl;
}