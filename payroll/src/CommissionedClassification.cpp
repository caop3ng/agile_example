#include "CommissionedClassification.h"
#include "SalesReceipt.h"

CommissionedClassification::CommissionedClassification(double salary, double commissionRate)
  : itsSalary(salary), itsCommissionRate(commissionRate)
{

}

double CommissionedClassification::CalculatePay(Paycheck&) const
{
  return 0;
}

double CommissionedClassification::GetSalary() const
{
  return itsSalary;
}

double CommissionedClassification::GetCommissionRate() const
{
  return itsCommissionRate;
}

void CommissionedClassification::AddSalesReceipts(SalesReceipt* sr)
{
  itsSalesReceipts.push_back(sr);
}

SalesReceipt* CommissionedClassification::GetSalesReceipt(Date dt) const
{
  for (const auto& sr : itsSalesReceipts)
  {
    if (sr->GetDate() == dt)
    {
      return sr;
    }
  }

  return nullptr;
}