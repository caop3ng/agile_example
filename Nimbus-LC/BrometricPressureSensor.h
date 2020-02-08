#pragma once
#include "Observable.h"

class BrometricPressureSensor : public Observable
{
public:
  virtual void read();
  virtual void NotifyObservers(double) = 0;
};