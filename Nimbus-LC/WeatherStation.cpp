#include "WeatherStation.h"
#include "StationToolkit.h"
#include "TemperatureSensor.h"
#include "BrometricPressureSensor.h"
#include "AlarmClock.h"
#include "TemperatureHiLo.h"

WeatherStation::WeatherStation(StationToolkit* st, DataToolkit* dt)
{
  ac_ = new AlarmClock(st);
  ts_ = new TemperatureSensor(ac_, st);
  bps_ = new BrometricPressureSensor(ac_, st);
  th_ = new TemperatureHiLo(ac_, st, ts_, dt);
}

void WeatherStation::AddTempObserver(Observer* o)
{
  ts_->AddObserver(o);
}

void WeatherStation::AddBPObserver(Observer* o)
{
  bps_->AddObserver(o);
}