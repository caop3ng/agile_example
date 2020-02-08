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

void PayrollDatabase::AddUnionMember(int memberId, Employee* e)
{
  itsUnionMembers[memberId] = e;
}

Employee* PayrollDatabase::GetUnionMember(int memberId) const
{
  auto it = itsUnionMembers.find(memberId);
  if (it == itsUnionMembers.end())
  {
    return nullptr;
  }
  else
  {
    return it->second;
  }
}

void PayrollDatabase::GetAllEmployeeIds(std::list<int>& l) const
{
  for (auto e : itsEmployees)
  {
    l.push_back(e.first);
  }
}

void PayrollDatabase::RemoveUnionMember(int memberId)
{
  auto it = itsUnionMembers.find(memberId);
  if (it != itsUnionMembers.end())
  {
    itsUnionMembers.erase(it);
  }
  else
  {
    //assert(0);
  }
}

void PayrollDatabase::clear()
{
  itsEmployees.clear();
  itsUnionMembers.clear();
}