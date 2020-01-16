#include "Paycheck.h"

using namespace std;

Paycheck::Paycheck(Date payDate)
  : itsPayDate(payDate)
{
}

Date Paycheck::GetPayDate() const
{
  return itsPayDate;
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

Date Paycheck::GetPayPeriodEndDate() const
{
  return Date();
}