#pragma once
#include "PaymentClassification.h"

class SalariedClassification :
  public PaymentClassification
{
public:
  SalariedClassification(double salary);

  double CalculatePay(Paycheck&) const;

  double GetSalary() const;

private:
  double itsSalary{ -1 };
};

