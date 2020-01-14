#include "Employee.h"
#include "PaymentSchedule.h"
#include "Paycheck.h"
#include "PaymentClassification.h"
#include "Affiliation.h"
#include "PaymentMethod.h"

Employee::Employee(int empId, std::string name, std::string address)
  : itsEmpId(empId), 
  itsName(name),
  itsAddress(address)
{
}

std::string Employee::GetName() const
{
  return itsName;
}

PaymentClassification* Employee::GetClassification() const
{
  return itsClassification;
}

PaymentSchedule* Employee::GetSchedule() const
{
  return itsSchedule;
}

PaymentMethod* Employee::GetMethod() const
{
  return itsMethod;
}

Affiliation* Employee::GetAffiliation() const
{
  return itsAffiliation;
}

bool Employee::IsPayDate(Date dt) const
{
  return itsSchedule->IsPayDate(dt);
}

void Employee::SetName(const std::string name)
{
  itsName = name;
}

void Employee::SetClassification(PaymentClassification* pc)
{
  itsClassification = pc;
}

void Employee::SetSchedule(PaymentSchedule* ps)
{
  itsSchedule = ps;
}

void Employee::SetMethod(PaymentMethod* pm)
{
  itsMethod = pm;
}

void Employee::SetAffiliation(Affiliation* af)
{
  itsAffiliation = af;
}

void Employee::Payday(Paycheck& pc)
{
  double grossPay = itsClassification->CalculatePay(pc);
  double deductions = itsAffiliation->CalculateDeduction(pc);
  double netPay = grossPay - deductions;

  pc.SetGrossPay(grossPay);
  pc.SetDeductions(deductions);
  pc.SetNetPay(netPay);

  itsMethod->Pay(pc);
}