#ifndef ADDEMPLOYEETRANSACTION_H
#define ADDEMPLOYEETRANSACTION_H

#include "Transaction.h"
#include <string>

class PaymentClassification;
class PaymentSchedule;

class AddEmployeeTransaction : public Transaction
{
public:
  virtual ~AddEmployeeTransaction();
  AddEmployeeTransaction(int empId, std::string name, std::string address);
  virtual PaymentClassification* GetClassification() const = 0;
  virtual PaymentSchedule* GetSchedule() const = 0;
  virtual void Execute();

private:
  int itsEmpId{ -1 };
  std::string itsName;
  std::string itsAddress;
};


#endif // !ADDEMPLOYEETRANSACTION_H