#pragma once
#include "Application.h"

class PayrollApplication
  : public Application
{
public:
  PayrollApplication(TransactionSource*);
  void Excute() const;
};
