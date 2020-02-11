#pragma once
#include "DataToolkit.h"

class StationToolkit;

class DataToolkitImp : public DataToolkit
{
public:
  DataToolkitImp(StationToolkit*);
  HiLoData* GetTempHiloData();

private:
  StationToolkit* st_{};
};
