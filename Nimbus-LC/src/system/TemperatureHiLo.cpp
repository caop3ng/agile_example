#include "TemperatureHiLo.h"
#include "AlarmClock.h"
#include "../api/StationToolkit.h"
#include "../wmsdata/DataToolkit.h"
#include "WeatherStation.h"
#include "../wmsdata/HiLoData.h"
#include "TemperatureSensor.h"

TemperatureHiLo::TemperatureHiLo(AlarmClock* ac, StationToolkit* st, TemperatureSensor* ts, DataToolkit* dt)
  : ts_(ts)
{
  ac->wakeEveryDay(this);
  hd_ = dt->GetTempHiloData();
  ts_->AddObserver(this);
}

void TemperatureHiLo::update(double t)
{
  hd_->CurrentReading(t, time(0));
}

void TemperatureHiLo::weakup()
{
  auto v = ts_->read();
  hd_->NewDay(v, time(0));
}