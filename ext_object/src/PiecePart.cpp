#include "PiecePart.h"
#include "XMLPiecePartExtension.h"
#include "CSVPiecePartExtension.h"

PiecePart::PiecePart(std::string part_num, std::string desc, double cost)
  : part_number_(part_num),
  description_(desc), 
  cost_(cost)
{
  AddExtension("CSV", new CSVPiecePartExtension(this));
  AddExtension("XML", new XMLPiecePartExtension(this));
}