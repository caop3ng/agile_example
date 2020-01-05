#include "SalesReceipt.h"

SalesReceipt::SalesReceipt(Date dt, double amount)
  : itsDate(dt),
  itsAmount(amount)
{

}

double SalesReceipt::GetAmount() const
{
  return itsAmount;
}

Date SalesReceipt::GetDate() const
{
  return itsDate;
}