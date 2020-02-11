#include "AlarmClock.h"
#include "../api/AlarmClockImp.h"
#include "AlarmListener.h"
#include "../api/StationToolkit.h"
#include <time.h>

using namespace std;

AlarmClock::AlarmClock(StationToolkit* st)
{
  aci_ = st->MakeAlarmClock();
  aci_->regist(this);
}

void AlarmClock::tic()
{
  std::lock_guard<mutex> lk(m_);

  for (auto& l : ms_listeners_)
  {
    l.tic_count++;
    if (l.tic_count * 10 > l.ms)
    {
      l.tic_count = 0;
      l.al->weakup();
    }
  }

  time_t t = time(0);
  tm temp;
  localtime_s(&temp, &t);

  //

  if (temp.tm_hour == 0
    && temp.tm_min == 0
    && temp.tm_sec == 0)
  {
    for (auto& l : day_listeners_)
    {
      //l->weakup();
    }
  }
}

void AlarmClock::wakeEvery(int ms, AlarmListener* al)
{
  std::lock_guard<mutex> lk(m_);
  ms_listeners_.push_back({ ms, 0, al });
}

void AlarmClock::wakeEveryDay(AlarmListener* al)
{
  std::lock_guard<mutex> lk(m_);
  day_listeners_.push_back(al);
}