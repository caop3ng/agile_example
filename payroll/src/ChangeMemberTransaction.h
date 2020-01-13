#pragma once
#include "ChangeAffiliationTransaction.h"
#include <string>


class ChangeMemberTransaction :
  public ChangeAffiliationTransaction
{
public:
  ChangeMemberTransaction(int empId, int memberId, double dues);
  ~ChangeMemberTransaction();

protected:
  Affiliation* GetAffiliation();
  void RecordMembership(Employee* e);

private:
  int itsMemberId{ -1 };
  double itsDues{ -1 };
};

