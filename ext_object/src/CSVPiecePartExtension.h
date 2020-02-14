#pragma once
#include "CSVPartExtension.h"

class PiecePart;

class CSVPiecePartExtension : public CSVPartExtension
{
public:
  CSVPiecePartExtension(PiecePart*);

  std::string GetCSV();
private:
  PiecePart* part_;
};