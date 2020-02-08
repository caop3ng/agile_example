#pragma once
#include "ChangeEmployeeTransaction.h"
#include <string>

class Affiliation;

class ChangeAffiliationTransaction :
  public ChangeEmployeeTransaction
{
public:
  ChangeAffiliationTransaction(int empId);
  ~ChangeAffiliationTransaction();

protected:
  void Change(Employee&);
  virtual Affiliation* GetAffiliation() = 0;
  virtual void RecordMembership(Employee* e) = 0;
};

