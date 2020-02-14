#pragma once
#include <string>
#include "PartExtension.h"

class CSVPartExtension : public PartExtension
{
public:
  virtual std::string GetCSV() = 0;
};
