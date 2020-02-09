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
#include "TestScreen.h"
#include "StationToolkit.h"
#include "Nimbus1_0StationToolkit.h"

int main()
{
  StationToolkit* st = new Nimbus1_0StationToolkit();

  AlarmClock* ac = new AlarmClock(st);
  TemperatureSensor ts(ac, st);
  BrometricPressureSensor bps(ac, st);
  TestScreen screen(&ts, &bps, nullptr);

  while (1)
  {
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}
