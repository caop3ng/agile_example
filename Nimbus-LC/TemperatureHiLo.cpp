#include "TemperatureHiLo.h"
#include "AlarmClock.h"
#include "StationToolkit.h"
#include "DataToolkit.h"
#include "WeatherStation.h"
#include "HiLoData.h"
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