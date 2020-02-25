#pragma once

#include <string>

#include "../util/Date.h"

class PaymentMethod;
class Afiliation;
class PaymentClassification;
class PaymentSchedule;
class Affiliation;
class Paycheck;

class Employee
{
public:
  Employee(int empId, std::string name, std::string address);

  std::string GetName() const;
  PaymentClassification* GetClassification() const;
  PaymentSchedule* GetSchedule() const;
  PaymentMethod* GetMethod() const;
  Affiliation* GetAffiliation() const;
  bool IsPayDate(Date dt) const;
  Date GetPayPeriodStartDate(Date payDate) const;

  void SetName(const std::string);
  void SetClassification(PaymentClassification*);
  void SetSchedule(PaymentSchedule*);
  void SetMethod(PaymentMethod*);
  void SetAffiliation(Affiliation*);

  void Payday(Paycheck& pc);

private:
  int itsEmpId;
  std::string itsName;
  std::string itsAddress;
  PaymentMethod* itsMethod{ nullptr };
  PaymentSchedule* itsSchedule{ nullptr };
  PaymentClassification* itsClassification{ nullptr };
  Affiliation* itsAffiliation{ nullptr };

};

