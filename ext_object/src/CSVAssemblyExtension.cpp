#include "CSVAssemblyExtension.h"
#include <sstream>
#include "PiecePart.h"
#include "Assembly.h"
#include "CSVPiecePartExtension.h"

using namespace std;


CSVAssemblyExtension::CSVAssemblyExtension(Assembly* a)
  : a_(a)
{
}

std::string CSVAssemblyExtension::GetCSV()
{
  stringstream ss;
  ss << "Assembly, "
    << a_->GetPartNumber() << ", "
    << a_->GetDescription();

  auto parts = a_->GetParts();
  for (auto& p : parts)
  {
    CSVPartExtension* ce = dynamic_cast<CSVPartExtension*>(p->GetExtension("CSV").value());
    ss << ", {" << ce->GetCSV() << "}";
  }

  return ss.str();
}