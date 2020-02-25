#include "PayrollApplication.h"
#include "TransactionSource.h"
#include "Transaction.h"

PayrollApplication::PayrollApplication(TransactionSource* ts)
  : Application(ts)
{

}

void PayrollApplication::Excute() const
{
  auto t = itsTransSource->GetTransaction();
  while (t)
  {
    t->Execute();
    t = itsTransSource->GetTransaction();
  }
}