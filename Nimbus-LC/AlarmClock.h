#pragma once

class AlarmListener;

class AlarmClock
{
public:
  virtual void tic();
  void wakeEvery(int interval, AlarmListener*);

};