#include "UnionAffiliation.h"
#include "ServiceCharge.h"

namespace
{
  int NumberOfFridaysInPayPeriod(const Date& payPeriodStart, const Date& payPeriodEnd)
  {
    int fridays = 0;
    for (Date day = payPeriodStart; day <= payPeriodEnd; day++)
    {
      if (day.GetDayOfWeek() == Date::friday)
      {
        fridays++;
      }
    }

    return fridays;
  }
}

UnionAffiliation::UnionAffiliation(int memberId, double dues)
  : itsMemberId(memberId),
  itsDues(dues)
{
}

double UnionAffiliation::GetFee(Date dt) const
{
  return 0;
}

double UnionAffiliation::CalculateDeduction(Paycheck& pc) const
{
  int fridays = NumberOfFridaysInPayPeriod(pc.GetPayPeriodStartDate(), pc.GetPayPeriodEndDate());
  double totalDues = itsDues * fridays;
  double totalCharge = 0;
  for (auto& sc : itsServiceCharges)
  {
    if (Date::IsBetween(sc->GetDate(), pc.GetPayPeriodStartDate(), pc.GetPayPeriodEndDate()))
    {
      totalCharge += sc->GetAmount();
    }
  }

  return totalDues + totalCharge;
}

double UnionAffiliation::GetDues() const
{
  return itsDues;
}

int UnionAffiliation::GetMemberId() const
{
  return itsMemberId;
}

void UnionAffiliation::AddServiceCharge(ServiceCharge* sc)
{
  itsServiceCharges.push_back(sc);
}

ServiceCharge* UnionAffiliation::GetServiceCharge(Date dt) const
{
  for (const auto& sc : itsServiceCharges)
  {
    if (sc->GetDate() == dt)
    {
      return sc;
    }
  }

  return nullptr;
}