#pragma once
#include <string>
#include "Date.h"
#include "HiLoData.h"

class HiLoDataImp;
class StationToolkit;
class PersistentImp;

class HiLoDataProxy : public HiLoData
{
public:
  HiLoDataProxy(StationToolkit*, HiLoDataImp*);
  bool CurrentReading(double current, long time);
  void NewDay(double initial, long time);
  double GetHighValue() const;
  long GetHighTime() const;
  double GetLowValue() const;
  long GetLowTime() const;
private:

  std::string CalcStorageKey(Date dt);
  void store();

  HiLoDataImp* hdi_{};
  PersistentImp* pi_{};
  std::string storage_key_;
};
