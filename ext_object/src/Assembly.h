#pragma once
#include <vector>
#include "Part.h"

class Assembly : public Part
{
public:
  Assembly(std::string part_number, std::string desc);

  std::string GetPartNumber() { return part_number_; }
  std::string GetDescription() { return description_; }
  std::vector<Part*> GetParts() { return parts_; }

  void Add(Part* p);

private:
  std::vector<Part*> parts_;
  std::string part_number_;
  std::string description_;

};
