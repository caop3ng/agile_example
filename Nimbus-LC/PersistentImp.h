#pragma once
#include <string>

class Serializable;

class PersistentImp
{
public:
  virtual void store(std::string name, Serializable* obj) = 0;
  virtual Serializable* retrieve(std::string name) = 0;
};