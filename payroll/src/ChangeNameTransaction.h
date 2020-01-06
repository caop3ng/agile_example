#pragma once
#include "ChangeEmployeeTransaction.h"
#include <string>

class ChangeNameTransaction :
  public ChangeEmployeeTransaction
{
public:
  ChangeNameTransaction(int empId, std::string name);

protected:
  void Change(Employee&);

private:
  std::string itsName;
};

