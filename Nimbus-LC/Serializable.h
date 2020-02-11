#pragma once

#include <string>

class Serializable
{
public:
  virtual std::string serialize() = 0;
};
