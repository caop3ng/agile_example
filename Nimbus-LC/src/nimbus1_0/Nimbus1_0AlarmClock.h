#pragma once
#include <vector>
#include <memory>
#include "../api/AlarmClockImp.h"

class Timer;

class Nimbus1_0AlarmClock : public AlarmClockImp
{
public:
  void regist(ClockListener*);

  std::shared_ptr<Timer> t_;
};
