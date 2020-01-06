#include "Employee.h"

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