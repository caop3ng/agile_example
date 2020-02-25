#include "XMLPiecePartExtension.h"
#include "PiecePart.h"
#include "xml/tinyxml2.h"

using namespace tinyxml2;

XMLPiecePartExtension::XMLPiecePartExtension(PiecePart* part)
  : part_(part)
{
}

tinyxml2::XMLElement* XMLPiecePartExtension::GetXMLElement()
{
  if (doc_)
  {
    return doc_->FirstChildElement();
  }

  doc_ = new XMLDocument;
  auto child1 = doc_->NewElement("PiecePart");
  BuildElement(*child1);
  return child1;
}

void XMLPiecePartExtension::BuildElement(tinyxml2::XMLElement& e)
{
  auto doc = e.GetDocument();

  e.SetName("PiecePart");

  auto child1_child1 = doc->NewElement("PartNumber");
  child1_child1->SetText(part_->GetPartNumber().c_str());

  auto child1_child2 = doc->NewElement("Description");
  child1_child2->SetText(part_->GetDescription().c_str());

  auto child1_child3 = doc->NewElement("Cost");
  child1_child3->SetText(part_->GetCost());

  doc->InsertFirstChild(&e);
  e.InsertFirstChild(child1_child1);
  e.InsertAfterChild(child1_child1, child1_child2);
  e.InsertAfterChild(child1_child2, child1_child3);
}