#include "Nimbus1_0BrometricPressureSensor.h"

double Nimbus1_0BrometricPressureSensor::read()
{
  return ++value_;
}