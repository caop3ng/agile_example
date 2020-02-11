#pragma once

class ClockListener;

class AlarmClockImp
{
public:
  virtual void regist(ClockListener*) = 0;
};
