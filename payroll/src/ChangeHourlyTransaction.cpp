#include "ChangeHourlyTransaction.h"
#include "HourlyClassification.h"
#include "WeeklySchedule.h"

ChangeHourlyTransaction::ChangeHourlyTransaction(int empId, double hourlyRate)
  : ChangeClassificationTransaction(empId),
  itsHourlyRate(hourlyRate)
{
}

PaymentClassification* ChangeHourlyTransaction::GetClassification()
{
  return new HourlyClassification(itsHourlyRate);
}

PaymentSchedule* ChangeHourlyTransaction::GetSchedule()
{
  return new WeeklySchedule();
}
