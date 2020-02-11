#include "DataToolkitImp.h"
#include "../wmsdata_imp/HiLoDataImp.h"
#include "HiLoDataProxy.h"

DataToolkitImp::DataToolkitImp(StationToolkit* st)
  : st_(st)
{
}

HiLoData* DataToolkitImp::GetTempHiloData()
{
  auto proxy = new HiLoDataProxy(st_, new HiLoDataImp());
  return proxy;
}