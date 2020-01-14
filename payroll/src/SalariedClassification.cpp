#include "SalariedClassification.h"

SalariedClassification::SalariedClassification(double salary)
  : itsSalary(salary)
{

}

double SalariedClassification::CalculatePay(Paycheck& pc) const
{
  return itsSalary;
}

double SalariedClassification::GetSalary() const
{
  return itsSalary;
}