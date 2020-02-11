// Nimbus-LC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

#include "api/StationToolkit.h"
#include "Nimbus1_0/Nimbus1_0StationToolkit.h"

#include "system/WeatherStation.h"
#include "ui/MonitoringScreen.h"
#include "persistence/DataToolkitImp.h"

int main()
{
  StationToolkit* st = new Nimbus1_0StationToolkit();
  DataToolkit* dt = new DataToolkitImp(st);
  WeatherStationComponent* wsc = new WeatherStation(st, dt);
  MonitoringScreen* ms = new MonitoringScreen(wsc);

  while (1)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
