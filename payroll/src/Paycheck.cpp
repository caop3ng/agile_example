#include "Paycheck.h"

using namespace std;

Paycheck::Paycheck(Date beginPayDate, Date endPayDate)
  : itsBeginPayDate(beginPayDate), itsEndPayDate(endPayDate)
{
}

Date Paycheck::GetPayDate() const
{
  return itsEndPayDate;
}

double Paycheck::GetGrossPay() const
{
  return itsGrossPay;
}

double Paycheck::GetDeduction() const
{
  return itsDeduction;
}

double Paycheck::GetNetPay() const
{
  return itsNetPay;
}

void Paycheck::SetGrossPay(double gross)
{
  itsGrossPay = gross;
}

void Paycheck::SetDeductions(double deduction)
{
  itsDeduction = deduction;
}

void Paycheck::SetNetPay(double netpay)
{
  itsNetPay = netpay;
}

std::string Paycheck::GetField(const std::string& field) const
{
  return string();
}

Date Paycheck::GetPayPeriodStartDate() const
{
  return itsBeginPayDate;
}

Date Paycheck::GetPayPeriodEndDate() const
{
  return itsEndPayDate;
}