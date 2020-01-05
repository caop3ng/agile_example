#pragma once
#include "AddEmployeeTransaction.h"

class AddHourlyEmployee :
  public AddEmployeeTransaction
{
public:
  AddHourlyEmployee(int empId, std::string name, std::string address, double hourlyRate);
  ~AddHourlyEmployee();

  PaymentClassification* GetClassification() const;
  PaymentSchedule* GetSchedule() const;

private:
  double itsHourlyRate{ -1 };
};

