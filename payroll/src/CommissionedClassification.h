#pragma once
#include "PaymentClassification.h"
#include "../util/Date.h"
#include <vector>

class SalesReceipt;

class CommissionedClassification :
  public PaymentClassification
{
public:
  CommissionedClassification(double salary, double commissionRate);

  double CalculatePay(Paycheck&) const;

  double GetSalary() const;
  double GetCommissionRate() const;
  void AddSalesReceipts(SalesReceipt*);
  SalesReceipt* GetSalesReceipt(Date dt) const;

private:
  double itsSalary{ -1 };
  double itsCommissionRate{ -1 };

  std::vector<SalesReceipt*> itsSalesReceipts;
};

