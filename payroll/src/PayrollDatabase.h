#ifndef PAYROLLDATABASE_H
#define PAYROLLDATABASE_H

#include <map>
#include <list>

class Employee;

class PayrollDatabase
{
public:
  virtual ~PayrollDatabase();
  Employee* GetEmployee(int empId);
  Employee* GetUnionMember(int memberId) const;
  void GetAllEmployeeIds(std::list<int>&) const;
  void AddEmployee(int empid, Employee*);
  void DeleteEmployee(int empid);
  void AddUnionMember(int memberId, Employee*);
  
  void RemoveUnionMember(int memberId);

  void clear();

private:
  std::map<int, Employee*> itsEmployees;
  std::map<int, Employee*> itsUnionMembers;
};

#endif // !PAYROLLDATABASE_H

