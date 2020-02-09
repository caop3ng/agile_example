#include "TestScreen.h"
#include <iostream>

using namespace std;

TestScreen::TestScreen(Observable* obs_temp, Observable* obs_bp, Observable* obs_trend)
  : MonitoringScreen(obs_temp, obs_bp, obs_trend)
{
}

void TestScreen::displayTemp(double t)
{
  cout << "Temp: " << t << endl;
}

void TestScreen::displayPressure(double pres)
{
  cout << "Pressure: " << pres << endl;
}

void TestScreen::displayPressureTrend(double)
{

}