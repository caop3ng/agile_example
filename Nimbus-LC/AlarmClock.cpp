#include "AlarmClock.h"
#include "AlarmClockImp.h"
#include "AlarmListener.h"
#include "StationToolkit.h"

using namespace std;

AlarmClock::AlarmClock(StationToolkit* st)
{
  aci_ = st->MakeAlarmClock();
  aci_->regist(this);
}

void AlarmClock::tic()
{
  std::lock_guard<mutex> lk(m_);

  for (auto& l : listeners_)
  {
    l.tic_count++;
    if (l.tic_count * 10 > l.ms)
    {
      l.tic_count = 0;
      l.al->weakup();
    }
  }
}

void AlarmClock::wakeEvery(int ms, AlarmListener* al)
{
  std::lock_guard<mutex> lk(m_);
  listeners_.push_back({ ms, 0, al });
}