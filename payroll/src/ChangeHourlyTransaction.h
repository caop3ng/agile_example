#pragma once
#include "ChangeClassificationTransaction.h"
#include <string>

class ChangeHourlyTransaction :
  public ChangeClassificationTransaction
{
public:
  ChangeHourlyTransaction(int empId, double hourlyRate);

protected:
  PaymentClassification* GetClassification();
  PaymentSchedule* GetSchedule();

private:
  double itsHourlyRate{ -1 };
};

