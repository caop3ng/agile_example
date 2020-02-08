#include "NoAffiliation.h"
#include "ServiceCharge.h"

NoAffiliation::NoAffiliation()
{
}

double NoAffiliation::GetFee(Date dt) const
{
  return 0;
}

double NoAffiliation::CalculateDeduction(Paycheck&) const
{
  return 0;
}

double NoAffiliation::GetDues() const
{
  return 0;
}