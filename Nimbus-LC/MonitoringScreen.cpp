#include <iostream>
#include "MonitoringScreen.h"
#include "Observable.h"
#include "TemperatureObserver.h"
#include "BrometricPressureObserver.h"
#include "WeatherStation.h"
#include "WeatherStationComponent.h"

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