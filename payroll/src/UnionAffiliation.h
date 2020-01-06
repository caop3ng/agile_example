#pragma once
#include "Affiliation.h"
#include <vector>

class ServiceCharge;

class UnionAffiliation :
  public Affiliation
{
public:
  UnionAffiliation(int memberId, double dues);

  double GetFee(Date dt) const;
  void AddServiceCharge(ServiceCharge*);
  ServiceCharge* GetServiceCharge(Date dt) const;

private:
  int itsMemberId{ -1 };
  double itsDues{ 0 };
  std::vector<ServiceCharge*> itsServiceCharges;
};

