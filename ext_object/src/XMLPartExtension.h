#pragma once
#include "PartExtension.h"

namespace tinyxml2
{
  class XMLElement;
}

class XMLPartExtension : public PartExtension
{
public:
  virtual tinyxml2::XMLElement* GetXMLElement() = 0;

  // compatible with tinyxml2
  virtual void BuildElement(tinyxml2::XMLElement& e) = 0;
};
