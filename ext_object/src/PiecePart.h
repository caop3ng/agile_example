#pragma once
#include "Part.h"

class PiecePart : public Part
{
public:
  PiecePart(std::string part_num, std::string desc, double cost);

  std::string GetPartNumber() { return part_number_; }
  std::string GetDescription() { return description_; }
  double GetCost() { return cost_; }

private:
  std::string part_number_;
  std::string description_;
  double cost_{};
};
