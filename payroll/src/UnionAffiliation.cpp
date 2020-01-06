#include "UnionAffiliation.h"
#include "ServiceCharge.h"

UnionAffiliation::UnionAffiliation(int memberId, double dues)
  : itsMemberId(memberId),
  itsDues(dues)
{
}

double UnionAffiliation::GetFee(Date dt) const
{
  return 0;
}

void UnionAffiliation::AddServiceCharge(ServiceCharge* sc)
{
  itsServiceCharges.push_back(sc);
}

ServiceCharge* UnionAffiliation::GetServiceCharge(Date dt) const
{
  for (const auto& sc : itsServiceCharges)
  {
    if (sc->GetDate().Equal(dt))
    {
      return sc;
    }
  }

  return nullptr;
}