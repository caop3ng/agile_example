#ifndef PAYROLLDATABASE_H
#define PAYROLLDATABASE_H

#include <map>

class Employee;

class PayrollDatabase
{
public:
  virtual ~PayrollDatabase();
  Employee* GetEmployee(int empId);
  void AddEmployee(int empid, Employee*);
  void DeleteEmployee(int empid);
  void clear()
  {
    itsEmployees.clear();
  }

private:
  std::map<int, Employee*> itsEmployees;
};

#endif // !PAYROLLDATABASE_H

