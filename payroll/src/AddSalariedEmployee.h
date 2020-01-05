#pragma once

#include "AddEmployeeTransaction.h"

class PaymentClassfication;

class AddSalariedEmployee : public AddEmployeeTransaction
{
public:
  virtual ~AddSalariedEmployee();
  AddSalariedEmployee(int empId, std::string name, std::string address, double salary);
  PaymentClassification* GetClassification() const;
  PaymentSchedule* GetSchedule() const;

private:
  double itsSalary;
};

