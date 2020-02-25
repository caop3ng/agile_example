#pragma once
#include <thread>

class ClockListener;

class Timer : public std::enable_shared_from_this<Timer>
{
public:
  Timer(int delay, ClockListener* cl);
  void start();
  void stop();
private:

  static void thread_fun(std::shared_ptr<Timer>, int delay);

  int delay_{};
  ClockListener* cl_{};
  std::thread t_;
  bool stopped_{ false };
};