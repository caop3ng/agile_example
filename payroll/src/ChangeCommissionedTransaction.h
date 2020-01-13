#pragma once
#include "ChangeClassificationTransaction.h"
#include <string>

class ChangeCommissionedTransaction :
  public ChangeClassificationTransaction
{
public:
  ChangeCommissionedTransaction(int empId, double salary, double commissionedRate);
  ~ChangeCommissionedTransaction();

protected:
  PaymentClassification* GetClassification();
  PaymentSchedule* GetSchedule();

private:
  double itsSalary{ -1 };
  double itsCommissionedRate{ 0 };
};

