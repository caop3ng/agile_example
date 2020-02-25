#include "XMLAssemblyExtension.h"
#include "xml/tinyxml2.h"
#include "Assembly.h"
#include <assert.h>

using namespace tinyxml2;

XMLAssemblyExtension::XMLAssemblyExtension(Assembly* a)
  : a_(a)
{

}

tinyxml2::XMLElement* XMLAssemblyExtension::GetXMLElement()
{
  if (doc_)
  {
    return doc_->FirstChildElement();
  }

  doc_ = new XMLDocument;
  auto child1 = doc_->NewElement("Assembly");
  auto child1_child1 = doc_->NewElement("PartNumber");
  child1_child1->SetText(a_->GetPartNumber().c_str());

  auto child1_child2 = doc_->NewElement("Description");
  child1_child2->SetText(a_->GetDescription().c_str());

  doc_->InsertFirstChild(child1);
  child1->InsertFirstChild(child1_child1);
  child1->InsertAfterChild(child1_child1, child1_child2);

  auto parts = doc_->NewElement("Parts");
  child1->InsertAfterChild(child1_child2, parts);
  for (auto& p : a_->GetParts())
  {
    auto op_pe = p->GetExtension("XML");
    assert(op_pe.has_value());
    PartExtension* pe = op_pe.value();
    XMLPartExtension* xpe = dynamic_cast<XMLPartExtension*>(pe);
    assert(xpe != nullptr);

    XMLElement* e = doc_->NewElement("unknown");
    xpe->BuildElement(*e);
    parts->InsertEndChild(e);
  }

  return child1;
}

void XMLAssemblyExtension::BuildElement(tinyxml2::XMLElement& e)
{
  assert(0);
}