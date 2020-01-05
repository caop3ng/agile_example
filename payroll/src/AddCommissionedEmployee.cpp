#include "AddCommissionedEmployee.h"
#include "CommissionedClassification.h"
#include "BiweeklySchedule.h"

AddCommissionedEmployee::AddCommissionedEmployee(int empId, std::string name, std::string address, double salary, double commissionRate)
  : AddEmployeeTransaction(empId, name, address),
  itsSalary(salary),
  itsCommissionRate(commissionRate)
{

}

AddCommissionedEmployee::~AddCommissionedEmployee()
{
}

PaymentClassification* AddCommissionedEmployee::GetClassification() const
{
  return new CommissionedClassification(itsSalary, itsCommissionRate);
}

PaymentSchedule* AddCommissionedEmployee::GetSchedule() const
{
  return new BiweeklySchedule();
}