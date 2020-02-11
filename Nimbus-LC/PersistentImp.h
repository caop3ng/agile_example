#pragma once
#include <string>

//class Serializable;

class PersistentImp
{
public:
  virtual void store(std::string name, std::string value) = 0;
  virtual std::string retrieve(std::string name) = 0;
};