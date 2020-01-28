#include "TextParserTransactionSource.h"

#include <fstream>
#include <iostream>

using namespace std;

TextParserTransactionSource::TextParserTransactionSource(std::string filename)
  : itsFilename(filename)
{
  try
  {
    ifstream ifs(itsFilename);
    // ...
    // ...
  }
  catch (...)
  {
    cout << "failed to open transaction source file: " << itsFilename;
  }
}

Transaction* TextParserTransactionSource::GetTransaction()
{
  if (itsIndex >= itsTransactions.size())
  {
    return nullptr;
  }

  return itsTransactions[itsIndex++];
}