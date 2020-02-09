// Nimbus-LC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

#include "AlarmClock.h"
#include "Nimbus1_0AlarmClock.h"
#include "TemperatureSensor.h"
#include "Nimbus1_0TemperatureSensor.h"
#include "BrometricPressureSensor.h"
#include "Nimbus1_0BrometricPressureSensor.h"
#include "StationToolkit.h"
#include "Nimbus1_0StationToolkit.h"
#include "WeatherStation.h"
#include "MonitoringScreen.h"

int main()
{
  StationToolkit* st = new Nimbus1_0StationToolkit();
  WeatherStationComponent* wsc = new WeatherStation(st);
  MonitoringScreen* ms = new MonitoringScreen(wsc);

  while (1)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
