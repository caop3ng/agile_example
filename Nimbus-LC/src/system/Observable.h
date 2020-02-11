#pragma once
#include <vector>

class Observer;

class Observable
{
public:
  virtual void AddObserver(Observer*);
  virtual void NotifyObservers(double) = 0;

protected:
  std::vector<Observer*> observers_;
};
