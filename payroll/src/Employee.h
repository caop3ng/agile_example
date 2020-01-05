#pragma once

#include <string>

class PaymentMethod;
class Afiliation;
class PaymentClassification;
class PaymentSchedule;

class Employee
{
public:
  Employee(int empId, std::string name, std::string address);

  std::string GetName() const;
  PaymentClassification* GetClassification() const;
  PaymentSchedule* GetSchedule() const;
  PaymentMethod* GetMethod() const;

  void SetClassification(PaymentClassification*);
  void SetSchedule(PaymentSchedule*);
  void SetMethod(PaymentMethod*);
  

private:
  int itsEmpId;
  std::string itsName;
  std::string itsAddress;
  PaymentMethod* itsMethod;
  PaymentSchedule* itsSchedule;
  PaymentClassification* itsClassification;
};

