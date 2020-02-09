#pragma once
#include "TemperatureSensorImp.h"

class Nimbus1_0TemperatureSensor : public TemperatureSensorImp
{
public:
  double read() final;

private:
  double value_{};
};