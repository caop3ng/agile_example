#pragma once

#include <string>
#include <vector>

enum class Command
{
	kUnknown = 0,
	kList,
	kAdd,
	kChange,
	kHelp
};

class command_line
{
public:
	command_line();

	Command parse(const std::string& text) const;

private:

	std::string triming(const std::string& text) const;

	std::vector<std::string> cmds_;
};
