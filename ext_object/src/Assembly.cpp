#include "Assembly.h"
#include "XMLAssemblyExtension.h"
#include "CSVAssemblyExtension.h"

Assembly::Assembly(std::string part_number, std::string desc)
  : part_number_(part_number),
  description_(desc)
{
  AddExtension("XML", new XMLAssemblyExtension(this));
  AddExtension("CSV", new CSVAssemblyExtension(this));
}

void Assembly::Add(Part* p)
{
  parts_.push_back(p);
}