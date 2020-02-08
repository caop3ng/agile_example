#include "ChangeClassificationTransaction.h"
#include "Employee.h"

ChangeClassificationTransaction::ChangeClassificationTransaction(int empId)
  : ChangeEmployeeTransaction(empId)
{
}

ChangeClassificationTransaction::~ChangeClassificationTransaction()
{

}

void ChangeClassificationTransaction::Change(Employee& e)
{
  auto pc = GetClassification();
  e.SetClassification(pc);

  auto ps = GetSchedule();
  e.SetSchedule(ps);
}