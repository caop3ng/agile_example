#pragma once

class TransactionSource;

class Application
{
public:
  Application(TransactionSource*);
  virtual ~Application() {}
  virtual void Excute() const = 0;
  
protected:
  TransactionSource* itsTransSource;
};
