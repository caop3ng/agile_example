#pragma once
#include "Affiliation.h"
#include <vector>


class NoAffiliation :
  public Affiliation
{
public:
  NoAffiliation();

  double GetFee(Date dt) const;
  double CalculateDeduction(Paycheck&) const;

  double GetDues() const;
};

