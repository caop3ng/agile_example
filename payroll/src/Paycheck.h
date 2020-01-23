#pragma once

#include <string>

#include "../util/Date.h"

class Paycheck
{
public:
  Paycheck(Date beginDate, Date payDate);

  Date GetPayDate() const;
  double GetGrossPay() const;
  double GetDeduction() const;
  double GetNetPay() const;
  std::string GetField(const std::string& field) const;
  Date GetPayPeriodStartDate() const;
  Date GetPayPeriodEndDate() const;

  void SetGrossPay(double);
  void SetDeductions(double);
  void SetNetPay(double);

private:
  Date itsBeginPayDate;
  Date itsEndPayDate;
  double itsGrossPay{ 0 };
  double itsDeduction{ 0 };
  double itsNetPay{ 0 };
};

