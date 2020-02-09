#include "Nimbus1_0MonitorScreen.h"
#include <iostream>

using namespace std;

Nimbus1_0MonitorScreen::Nimbus1_0MonitorScreen(WeatherStationComponent* wsc)
  : MonitoringScreen(wsc)
{
}

void Nimbus1_0MonitorScreen::displayTemp(double t)
{
  cout << "Temp: " << t << endl;
}

void Nimbus1_0MonitorScreen::displayPressure(double pres)
{
  cout << "Pressure: " << pres << endl;
}

void Nimbus1_0MonitorScreen::displayPressureTrend(double)
{

}