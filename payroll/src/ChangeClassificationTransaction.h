#pragma once
#include "ChangeEmployeeTransaction.h"
#include <string>

class PaymentClassification;
class PaymentSchedule;

class ChangeClassificationTransaction :
  public ChangeEmployeeTransaction
{
public:
  ChangeClassificationTransaction(int empId);
  ~ChangeClassificationTransaction();

protected:
  void Change(Employee&);

  virtual PaymentClassification* GetClassification() = 0;
  virtual PaymentSchedule* GetSchedule() = 0;

};

