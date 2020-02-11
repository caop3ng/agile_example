#include "Timer.h"
#include <thread>
#include <chrono>
#include "ClockListener.h"

using namespace std;

Timer::Timer(int delay, ClockListener* cl)
  : delay_(delay), cl_(cl)
{
}

void Timer::start()
{
  stopped_ = false;
  t_ = thread(thread_fun, shared_from_this(), delay_);
}

void Timer::stop()
{
  stopped_ = true;
}

void Timer::thread_fun(std::shared_ptr<Timer> t, int delay)
{
  while (1)
  {
    if (t->stopped_)
    {
      break;
    }

    t->cl_->tic();

    this_thread::sleep_for(chrono::milliseconds(delay));
  }
}