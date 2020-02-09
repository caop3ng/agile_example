#pragma once
#include "BrometricPressureSensorImp.h"


class Nimbus1_0BrometricPressureSensor : public BrometricPressureSensorImp
{
public:
  double read();

private:
  double value_{};
};
