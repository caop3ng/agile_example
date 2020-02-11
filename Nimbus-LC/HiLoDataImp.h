#pragma once
#include <string>
#include "Serializable.h"
#include "HiLoData.h"

class Date;

class HiLoDataImp : public Serializable, public HiLoData
{
public:
  HiLoDataImp(/*std::string type, Date* dt, double init, long initTime*/);

  bool CurrentReading(double current, long time);
  void NewDay(double initial, long time);
  double GetHighValue() const;
  long GetHighTime() const;
  double GetLowValue() const;
  long GetLowTime() const;

  std::string serialize();
private:
  std::string type_;

  double low_value_{};
  long low_time_{};
  double high_value_{};
  long high_time_{};
};
