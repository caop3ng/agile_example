#include "HiLoDataProxy.h"
#include "HiLoDataImp.h"
#include "StationToolkit.h"
#include "PersistentImp.h"
#include "Date.h"

HiLoDataProxy::HiLoDataProxy(StationToolkit* st, HiLoDataImp* hdi)
  : hdi_(hdi)
{
  pi_ = st->MakePersistentImp();
}

bool HiLoDataProxy::CurrentReading(double current, long time)
{
  bool change = hdi_->CurrentReading(current, time);
  if (change)
  {
    store();
  }

  return change;
}

void HiLoDataProxy::NewDay(double initial, long time)
{
  store();
  hdi_->NewDay(initial, time);
  CalcStorageKey(Date());
  store();
}

void HiLoDataProxy::store()
{
  try
  {
    pi_->store(storage_key_, hdi_);
  }
  catch (...)
  {
    // log
  }
}

std::string HiLoDataProxy::CalcStorageKey(Date dt)
{
  return std::string();
}

double HiLoDataProxy::GetHighValue() const
{
  return hdi_->GetHighValue();
}

long HiLoDataProxy::GetHighTime() const
{
  return hdi_->GetHighTime();
}

double HiLoDataProxy::GetLowValue() const
{
  return hdi_->GetLowValue();
}

long HiLoDataProxy::GetLowTime() const
{
  return hdi_->GetLowTime();
}