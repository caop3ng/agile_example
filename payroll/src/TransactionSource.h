#pragma once

class Transaction;

class TransactionSource
{
public:
  virtual ~TransactionSource()
  {
  }

  virtual Transaction* GetTransaction() = 0;

};