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
  void wakeEveryDay(AlarmListener*);

private:
  AlarmClockImp* aci_;

  struct Listener
  {
    int ms;
    int tic_count;
    AlarmListener* al;
  };

  std::vector<Listener> ms_listeners_;
  std::vector<AlarmListener*> day_listeners_;
  std::mutex m_;
};