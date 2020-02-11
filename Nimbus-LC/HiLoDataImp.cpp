#include "HiLoDataImp.h"

HiLoDataImp::HiLoDataImp(/*std::string type, Date* dt, double init, long initTime*/)
{
  //type_ = type;

  //try
  //{
  //  //HiLoData* t = nullptr;
  //  //high_time_ = t->GetHighTime();
  //  //high_value_ = t->GetHighValue();
  //  //low_time_ = t->GetLowTime();
  //  //low_value_ = t->GetLowValue();
  //  //CurrentReading(init, initTime);
  //}
  //catch (...)
  //{
  //  high_value_ = low_value_ = init;
  //  high_time_ = low_time_ = initTime;
  //}
}

bool HiLoDataImp::CurrentReading(double current, long time)
{
  if (current > high_value_)
  {
    high_value_ = current;
    high_time_ = time;
    return true;
  }
  else if (current < low_value_)
  {
    low_value_ = current;
    low_time_ = time;
    return true;
  }

  return false;
}

void HiLoDataImp::NewDay(double initial, long time)
{
  low_value_ = high_value_ = initial;
  low_time_ = high_time_ = time;
}

double HiLoDataImp::GetHighValue() const
{
  return high_value_;
}

long HiLoDataImp::GetHighTime() const
{
  return high_time_;
}

double HiLoDataImp::GetLowValue() const
{
  return low_value_;
}

long HiLoDataImp::GetLowTime() const
{
  return low_time_;
}

std::string HiLoDataImp::serialize()
{
  return std::string();
}