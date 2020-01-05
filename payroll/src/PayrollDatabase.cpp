#include "PayrollDatabase.h"
#include "Employee.h"

PayrollDatabase GpayrollDatabase;

PayrollDatabase::~PayrollDatabase()
{

}

Employee* PayrollDatabase::GetEmployee(int empId)
{
  auto it = itsEmployees.find(empId);
  if (it == itsEmployees.end())
  {
    return nullptr;
  }
  else
  {
    return it->second;
  }
}

void PayrollDatabase::AddEmployee(int empid, Employee* e)
{
  itsEmployees[empid] = e;
}

void PayrollDatabase::DeleteEmployee(int empid)
{
  auto it = itsEmployees.find(empid);
  if (it == itsEmployees.end())
  {
    throw("employee not found.");
  }
  else
  {
    itsEmployees.erase(it);
  }
}