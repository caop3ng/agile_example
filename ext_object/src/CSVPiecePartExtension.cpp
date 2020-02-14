#include "CSVPiecePartExtension.h"
#include <sstream>
#include "PiecePart.h"

using namespace std;

CSVPiecePartExtension::CSVPiecePartExtension(PiecePart* part)
  : part_(part)
{
}

std::string CSVPiecePartExtension::GetCSV()
{
  stringstream ss;
  ss << "PiecePart, "
    << part_->GetPartNumber() << ", "
    << part_->GetDescription() << ", "
    << part_->GetCost();

  return ss.str();
}