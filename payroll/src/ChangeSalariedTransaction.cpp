#include "ChangeSalariedTransaction.h"
#include "SalariedClassification.h"
#include "MonthlySchedule.h"


ChangeSalariedTransaction::ChangeSalariedTransaction(int empId, double salary)
  : ChangeClassificationTransaction(empId),
  itsSalary(salary)
{
}

ChangeSalariedTransaction::~ChangeSalariedTransaction()
{

}

PaymentClassification* ChangeSalariedTransaction::GetClassification()
{
  return new SalariedClassification(itsSalary);
}

PaymentSchedule* ChangeSalariedTransaction::GetSchedule()
{
  return new MonthlySchedule();
}
