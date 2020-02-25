#pragma once
#include "CSVPartExtension.h"

class Assembly;

class CSVAssemblyExtension : public CSVPartExtension
{
public:
  CSVAssemblyExtension(Assembly*);
  
  std::string GetCSV();

private:
  Assembly* a_{};
};
