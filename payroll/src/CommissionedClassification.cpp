#include "CommissionedClassification.h"
#include "SalesReceipt.h"

CommissionedClassification::CommissionedClassification(double salary, double commissionRate)
  : itsSalary(salary), itsCommissionRate(commissionRate)
{

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
    if (sr->GetDate().Equal(dt))
    {
      return sr;
    }
  }

  return nullptr;
}