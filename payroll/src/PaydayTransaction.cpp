#include "PaydayTransaction.h"
#include "PayrollDatabase.h"
#include "Employee.h"
#include "Paycheck.h"

using namespace std;

extern PayrollDatabase GpayrollDatabase;

PaydayTransaction::PaydayTransaction(Date payDate)
  : itsPayDate(payDate)
{

}

void PaydayTransaction::Execute()
{
  list<int> empIds;
  GpayrollDatabase.GetAllEmployeeIds(empIds);

  for (auto empId : empIds)
  {
    auto e = GpayrollDatabase.GetEmployee(empId);
    if (e && e->IsPayDate(itsPayDate))
    {
      Paycheck* pc = new Paycheck(e->GetPayPeriodStartDate(itsPayDate), itsPayDate);
      itsPaychecks[empId] = pc;
      e->Payday(*pc);
    }
  }
}

Paycheck* PaydayTransaction::GetPaycheck(int empId) const
{
  auto it = itsPaychecks.find(empId);
  if (it == itsPaychecks.end())
  {
    return nullptr;
  }
  else
  {
    return it->second;
  }
}