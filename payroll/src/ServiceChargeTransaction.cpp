#include <assert.h>

#include "ServiceChargeTransaction.h"
#include "PayrollDatabase.h"
#include "Employee.h"
#include "UnionAffiliation.h"
#include "ServiceCharge.h"

extern PayrollDatabase GpayrollDatabase;

ServiceChargeTransaction::ServiceChargeTransaction(int memberId, Date dt, double amount)
  : itsMemberId(memberId),
  itsDate(dt),
  itsAmount(amount)
{
}

void ServiceChargeTransaction::Execute()
{
  auto e = GpayrollDatabase.GetUnionMember(itsMemberId);
  if (!e)
  {
    assert(0);
    return;
  }

  auto af = e->GetAffiliation();
  auto uf = dynamic_cast<UnionAffiliation*>(af);
  if (uf)
  {
    uf->AddServiceCharge(new ServiceCharge(itsDate, itsAmount));
  }
}