#pragma once
#include <vector>
#include <tuple>
#include <mutex>
#include "ClockListener.h"

class AlarmListener;
class AlarmClockImp;
class StationToolkit;

class AlarmClock : public ClockListener
{
public:
  AlarmClock(StationToolkit* st);
  void tic() final;
  void wakeEvery(int ms, AlarmListener*);

private:
  AlarmClockImp* aci_;

  struct Listener
  {
    int ms;
    int tic_count;
    AlarmListener* al;
  };

  std::vector<Listener> listeners_;
  std::mutex m_;
};