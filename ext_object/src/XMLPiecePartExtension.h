#pragma once
#include "XMLPartExtension.h"

class PiecePart;

namespace tinyxml2
{
  class XMLDocument;
}

class XMLPiecePartExtension : public XMLPartExtension
{
public:
  XMLPiecePartExtension(PiecePart* part);

  tinyxml2::XMLElement* GetXMLElement();
  void BuildElement(tinyxml2::XMLElement& e);

private:
  PiecePart* part_{};
  tinyxml2::XMLDocument* doc_{};
};