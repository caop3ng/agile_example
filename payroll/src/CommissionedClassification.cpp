#include "CommissionedClassification.h"
#include "SalesReceipt.h"

CommissionedClassification::CommissionedClassification(double salary, double commissionRate)
  : itsSalary(salary), itsCommissionRate(commissionRate)
{

}

double CommissionedClassification::CalculatePay(Paycheck& pc) const
{
  double commission = 0;
  for (auto sr : itsSalesReceipts)
  {
    if (IsInPayPeriod(sr, pc.GetPayDate()))
    {
      commission += sr->GetAmount() * itsCommissionRate;
    }
  }

  return itsSalary + commission;
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

bool CommissionedClassification::IsInPayPeriod(SalesReceipt* sr, Date endPeriod) const
{
  Date begin = endPeriod - 13;
  if (begin < sr->GetDate()
    && sr->GetDate() <= endPeriod)
  {
    return true;
  }

  return false;
}