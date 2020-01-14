#include "AddEmployeeTransaction.h"
#include "HoldMethod.h"
#include "Employee.h"
#include "PayrollDatabase.h"
#include "NoAffiliation.h"

extern PayrollDatabase GpayrollDatabase;

AddEmployeeTransaction::~AddEmployeeTransaction()
{

}

AddEmployeeTransaction::AddEmployeeTransaction(int empId, std::string name, std::string address)
  : itsEmpId(empId),
  itsName(name),
  itsAddress(address)
{

}

void AddEmployeeTransaction::Execute()
{
  PaymentClassification* pc = GetClassification();
  PaymentSchedule* ps = GetSchedule();
  PaymentMethod* pm = new HoldMethod();

  Employee* e = new Employee(itsEmpId, itsName, itsAddress);
  e->SetClassification(pc);
  e->SetSchedule(ps);
  e->SetMethod(pm);
  
  e->SetAffiliation(new NoAffiliation());

  GpayrollDatabase.AddEmployee(itsEmpId, e);
}