#pragma once
#include "ChangeAffiliationTransaction.h"
#include <string>


class ChangeUnaffiliationTransaction :
  public ChangeAffiliationTransaction
{
public:
  ChangeUnaffiliationTransaction(int empId);
  ~ChangeUnaffiliationTransaction();

protected:
  Affiliation* GetAffiliation();
  void RecordMembership(Employee* e);
};

