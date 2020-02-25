#include "Nimbus1_0Persistent.h"

void Nimbus1_0PersistentImp::store(std::string name, std::string value)
{
  values_[name] = value;
}

std::string Nimbus1_0PersistentImp::retrieve(std::string name)
{
  auto it = values_.find(name);
  if (it != values_.end())
  {
    return it->second;
  }

  return std::string();
}