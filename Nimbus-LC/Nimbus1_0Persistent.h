#pragma once
#include "PersistentImp.h"

class Nimbus1_0PersistentImp : public PersistentImp
{
public:
  void store(std::string name, Serializable* obj) final;
  Serializable* retrieve(std::string name) final;
};
