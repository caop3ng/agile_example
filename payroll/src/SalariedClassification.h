#pragma once
#include "PaymentClassification.h"

class SalariedClassification :
  public PaymentClassification
{
public:
  SalariedClassification(double salary);

  double GetSalary() const;

private:
  double itsSalary{ -1 };
};

