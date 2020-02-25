#pragma once
#include <string>
#include <map>
#include <optional>

class PartExtension;

class Part
{
public:
  virtual std::string GetPartNumber() = 0;
  virtual std::string GetDescription() = 0;

  void AddExtension(std::string ext_type, PartExtension* ext)
  {
    exts_[ext_type] = ext;
  }

  std::optional<PartExtension*> GetExtension(std::string ext_type)
  {
    auto it = exts_.find(ext_type);
    if (it == exts_.end())
    {
      return {};
    }

    return it->second;
  }

private:
  std::map<std::string, PartExtension*> exts_;
};
