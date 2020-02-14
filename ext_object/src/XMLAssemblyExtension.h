#pragma once
#include "XMLPartExtension.h"

class Assembly;

namespace tinyxml2
{
  class XMLDocument;
}

class XMLAssemblyExtension : public XMLPartExtension
{
public:
  XMLAssemblyExtension(Assembly*);

  tinyxml2::XMLElement* GetXMLElement();
  void BuildElement(tinyxml2::XMLElement& e);

private:
  Assembly* a_{};
  tinyxml2::XMLDocument* doc_{};
};