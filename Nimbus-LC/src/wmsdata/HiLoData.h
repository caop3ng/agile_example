#pragma once

class HiLoData
{
public:
  virtual bool CurrentReading(double current, long time) = 0;
  virtual void NewDay(double initial, long time) = 0;
  virtual double GetHighValue() const = 0;
  virtual long GetHighTime() const = 0;
  virtual double GetLowValue() const = 0;
  virtual long GetLowTime() const = 0;
};
