#include "TimeCardTransaction.h"

#include "PayrollDatabase.h"
#include "Employee.h"
#include "HourlyClassification.h"
#include "TimeCard.h"

extern PayrollDatabase GpayrollDatabase;

TimeCardTransaction::TimeCardTransaction(Date dt, double hours, int empId)
  : itsDate(dt),
  itsHours(hours),
  itsEmpId(empId)
{
}

void TimeCardTransaction::Execute()
{
  auto e = GpayrollDatabase.GetEmployee(itsEmpId);
  if (!e)
  {
    throw("employee not found!");
  }

  auto pc = e->GetClassification();
  auto hc = dynamic_cast<HourlyClassification*>(pc);
  if (!hc)
  {
    throw("wrong payment classification!");
  }

  auto tc = new TimeCard(itsDate, itsHours);
  hc->AddTimeCard(tc);
}