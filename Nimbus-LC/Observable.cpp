#include "Observable.h"

void Observable::AddObserver(Observer* obs)
{
  observers_.push_back(obs);
}