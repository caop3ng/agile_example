#pragma once
#include "PersistentImp.h"
#include <map>

class Nimbus1_0PersistentImp : public PersistentImp
{
public:
  void store(std::string name, std::string value) final;
  std::string retrieve(std::string name) final;

private:
  std::map<std::string, std::string> values_;
};
