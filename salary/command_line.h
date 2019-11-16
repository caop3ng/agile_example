#pragma once

#include <string>
#include <vector>

enum class Command
{
	kUnknown = 0,
	kList,
	kAdd,
	kChange,
	kHelp,
	kExit,
	kClear
};

class command_line
{
public:
	command_line();

	Command parse(const std::string& text) const;
	bool exec_command(Command cmd) const;

private:

	bool exec_help() const;
	bool exec_list() const;
	bool exec_add() const;
	bool exec_clear() const;
};