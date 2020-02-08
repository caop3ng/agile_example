#include "ChangeCommissionedTransaction.h"

#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"

ChangeCommissionedTransaction::ChangeCommissionedTransaction(int empId, double salary, double commissionedRate)
  : ChangeClassificationTransaction(empId),
  itsSalary(salary),
  itsCommissionedRate(commissionedRate)
{
}

ChangeCommissionedTransaction::~ChangeCommissionedTransaction()
{
}

PaymentClassification* ChangeCommissionedTransaction::GetClassification()
{
  return new CommissionedClassification(itsSalary, itsCommissionedRate);
}

PaymentSchedule* ChangeCommissionedTransaction::GetSchedule()
{
  return new BiweeklySchedule();
}