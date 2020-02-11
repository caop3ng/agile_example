#include "Nimbus1_0TemperatureSensor.h"

double Nimbus1_0TemperatureSensor::read()
{
  return ++value_;
}