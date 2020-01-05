#include "SalesReceiptTransaction.h"
#include "SalesReceipt.h"
#include "PayrollDatabase.h"
#include "Employee.h"
#include "CommissionedClassification.h"

extern PayrollDatabase GpayrollDatabase;

SalesReceiptTransaction::SalesReceiptTransaction(Date dt, double amount, int empid)
  : itsDate(dt),
  itsAmount(amount),
  itsEmpid(empid)
{

}

void SalesReceiptTransaction::Execute()
{
  auto e = GpayrollDatabase.GetEmployee(itsEmpid);
  if (!e)
  {
    throw("no such employee!");
  }

  auto pc = e->GetClassification();
  auto cc = dynamic_cast<CommissionedClassification*>(pc);
  if (!cc)
  {
    throw("add salesreceipt to non commissioned classification!");
  }

  cc->AddSalesReceipts(new SalesReceipt(itsDate, itsAmount));
}