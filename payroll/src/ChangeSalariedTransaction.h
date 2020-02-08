#pragma once
#include "ChangeClassificationTransaction.h"
#include <string>

class ChangeSalariedTransaction :
  public ChangeClassificationTransaction
{
public:
  ChangeSalariedTransaction(int empId, double salary);
  ~ChangeSalariedTransaction();

protected:
  PaymentClassification* GetClassification();
  PaymentSchedule* GetSchedule();

private:
  double itsSalary{ -1 };
};

