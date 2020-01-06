#include "ServiceCharge.h"

ServiceCharge::ServiceCharge(Date dt, double amount)
  : itsDate(dt),
  itsAmount(amount)
{
}

Date ServiceCharge::GetDate() const
{
  return itsDate;
}

double ServiceCharge::GetAmount() const
{
  return itsAmount;
}
