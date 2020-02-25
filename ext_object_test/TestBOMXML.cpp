#include <gtest/gtest.h>
#include "all_header.h"

class TestBOMXML : public ::testing::Test
{
protected:
  void SetUp() override
  {
    p1_ = new PiecePart("997624", "MyPart", 3.20);
    p2_ = new PiecePart("7734", "Hell", 666);
    a_ = new Assembly("5879", "MyAssembly");
  }

  PiecePart* p1_{};
  PiecePart* p2_{};
  Assembly* a_{};
};

TEST_F(TestBOMXML, CreatePart)
{
  EXPECT_EQ("997624", p1_->GetPartNumber());
  EXPECT_EQ("MyPart", p1_->GetDescription());
  EXPECT_EQ(3.20, p1_->GetCost());
}

TEST_F(TestBOMXML, CreateAssembly)
{
  EXPECT_EQ("5879", a_->GetPartNumber());
  EXPECT_EQ("MyAssembly", a_->GetDescription());
}

TEST_F(TestBOMXML, PiecePart1XML)
{
  auto op = p1_->GetExtension("XML");
  EXPECT_TRUE(op.has_value());
  PartExtension* e = op.value();
  XMLPiecePartExtension* xe = dynamic_cast<XMLPiecePartExtension*>(e);
  EXPECT_NE(xe, nullptr);

  tinyxml2::XMLElement* xml = xe->GetXMLElement();
  EXPECT_STREQ("PiecePart", xml->Name());
  EXPECT_STREQ("997624", xml->FirstChildElement("PartNumber")->GetText());
  EXPECT_STREQ("MyPart", xml->FirstChildElement("Description")->GetText());
  EXPECT_EQ(3.2, atof(xml->FirstChildElement("Cost")->GetText()));
}

TEST_F(TestBOMXML, PiecePart2XML)
{
  auto op = p2_->GetExtension("XML");
  EXPECT_TRUE(op.has_value());
  PartExtension* e = op.value();
  XMLPiecePartExtension* xe = dynamic_cast<XMLPiecePartExtension*>(e);
  EXPECT_NE(xe, nullptr);

  tinyxml2::XMLElement* xml = xe->GetXMLElement();
  EXPECT_STREQ("PiecePart", xml->Name());
  EXPECT_STREQ("7734", xml->FirstChildElement("PartNumber")->GetText());
  EXPECT_STREQ("Hell", xml->FirstChildElement("Description")->GetText());
  EXPECT_EQ(666, atof(xml->FirstChildElement("Cost")->GetText()));
}

TEST_F(TestBOMXML, testAssembly)
{
  a_->Add(p1_);
  a_->Add(p2_);

  auto ps = a_->GetParts();
  EXPECT_EQ(ps[0], p1_);
  EXPECT_EQ(ps[1], p2_);

  EXPECT_EQ(ps.size(), 2);
}

TEST_F(TestBOMXML, testAssemblyOfAssemblies)
{
  Assembly* subAssembly = new Assembly("1324", "SubAssembly");
  subAssembly->Add(p1_);
  a_->Add(subAssembly);

  EXPECT_EQ(a_->GetParts()[0], subAssembly);
}

TEST_F(TestBOMXML, testSimpleAssemblyXML)
{
  auto e = a_->GetExtension("XML");
  EXPECT_TRUE(e.has_value());
  
  XMLPartExtension* xe = dynamic_cast<XMLPartExtension*>(e.value());
  EXPECT_NE(xe, nullptr);

  auto xml = xe->GetXMLElement();
  EXPECT_STREQ("Assembly", xml->Name());
  EXPECT_STREQ("5879", xml->FirstChildElement("PartNumber")->GetText());
  EXPECT_STREQ("MyAssembly", xml->FirstChildElement("Description")->GetText());

  auto parts = xml->FirstChildElement("Parts");
  EXPECT_TRUE(parts->NoChildren());
}

TEST_F(TestBOMXML, testAssemblyWithPartsXML)
{
  a_->Add(p1_);
  a_->Add(p2_);

  auto e = a_->GetExtension("XML");
  EXPECT_TRUE(e.has_value());

  XMLPartExtension* xe = dynamic_cast<XMLPartExtension*>(e.value());
  EXPECT_NE(xe, nullptr);

  auto xml = xe->GetXMLElement();
  EXPECT_STREQ("Assembly", xml->Name());
  EXPECT_STREQ("5879", xml->FirstChildElement("PartNumber")->GetText());
  EXPECT_STREQ("MyAssembly", xml->FirstChildElement("Description")->GetText());

  auto parts = xml->FirstChildElement("Parts");
  EXPECT_FALSE(parts->NoChildren());

  auto first = parts->FirstChildElement();
  EXPECT_STREQ("PiecePart", first->Name());
  EXPECT_STREQ("997624", first->FirstChildElement("PartNumber")->GetText());

  auto second = first->NextSiblingElement();
  EXPECT_STREQ("PiecePart", second->Name());
  EXPECT_STREQ("7734", second->FirstChildElement("PartNumber")->GetText());
}

TEST_F(TestBOMXML, testPiecePart1CSV)
{
  auto e = p1_->GetExtension("CSV");
  EXPECT_TRUE(e.has_value());
  CSVPartExtension* ce = dynamic_cast<CSVPartExtension*>(e.value());
  std::string csv = ce->GetCSV();
  EXPECT_STREQ("PiecePart, 997624, MyPart, 3.2", csv.c_str());
}

TEST_F(TestBOMXML, testPiecePart2CSV)
{
  auto e = p2_->GetExtension("CSV");
  EXPECT_TRUE(e.has_value());
  CSVPartExtension* ce = dynamic_cast<CSVPartExtension*>(e.value());
  std::string csv = ce->GetCSV();
  EXPECT_STREQ("PiecePart, 7734, Hell, 666", csv.c_str());
}

TEST_F(TestBOMXML, testAssemblyCSV)
{
  auto e = a_->GetExtension("CSV");
  EXPECT_TRUE(e.has_value());
  CSVPartExtension* ce = dynamic_cast<CSVPartExtension*>(e.value());
  std::string csv = ce->GetCSV();
  EXPECT_STREQ("Assembly, 5879, MyAssembly", csv.c_str());
}

TEST_F(TestBOMXML, testAssemblyWithPartsCSV)
{
  a_->Add(p1_);
  a_->Add(p2_);

  auto optional = a_->GetExtension("CSV");
  CSVPartExtension* ce = dynamic_cast<CSVPartExtension*>(optional.value());
  EXPECT_NE(ce, nullptr);

  EXPECT_STREQ("Assembly, 5879, MyAssembly, "
    "{PiecePart, 997624, MyPart, 3.2}, "
    "{PiecePart, 7734, Hell, 666}", ce->GetCSV().c_str());
}