#include "Nimbus1_0AlarmClock.h"
#include "Timer.h"

void Nimbus1_0AlarmClock::regist(ClockListener* cl)
{
  t_.reset(new Timer(10, cl));
  t_->start();
}