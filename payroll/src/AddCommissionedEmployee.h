#pragma once
#include "AddEmployeeTransaction.h"

class AddCommissionedEmployee :
  public AddEmployeeTransaction
{
public:
  AddCommissionedEmployee(int empId, std::string name, std::string address, double salary, double commissionRate);
  ~AddCommissionedEmployee();

  PaymentClassification* GetClassification() const;
  PaymentSchedule* GetSchedule() const;

private:
  double itsSalary{ -1 };
  double itsCommissionRate{ -1 };
};

