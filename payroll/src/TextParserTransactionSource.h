#pragma once
#include "TransactionSource.h"

#include <string>
#include <vector>

class TextParserTransactionSource
  : public TransactionSource
{
public:
  TextParserTransactionSource(std::string filename);

  Transaction* GetTransaction();

private:
  std::string itsFilename;
  std::vector<Transaction*> itsTransactions;
  int itsIndex{ 0 };
};