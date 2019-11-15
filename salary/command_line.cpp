#include "command_line.h"
#include <map>
#include <iostream>

using namespace std;

map<string, Command> commands_dict = {
	{ "list" , Command::kList },
	{ "add", Command::kAdd },
	{ "change", Command::kChange },
	{ "help", Command::kHelp },
};

command_line::command_line()
{
	cmds_.push_back("list");
	cmds_.push_back("add");
	cmds_.push_back("change");
	cmds_.push_back("help");
}

Command command_line::parse(const std::string& text) const
{
	auto trimed_text = triming(text);

	auto it = commands_dict.find(trimed_text);
	if (it == commands_dict.end())
	{
		return Command::kUnknown;
	}
	else
	{
		return commands_dict[trimed_text];
	}

}

std::string command_line::triming(const std::string& text) const
{
	string whitespace = " \t";

	const auto strBegin = text.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = text.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return text.substr(strBegin, strRange);
}

bool command_line::exec_command(Command cmd) const
{
	if (cmd == Command::kHelp)
	{
		cout << "executing help command." << endl;
		cout << "you can use those commands blow: " << endl;
		for (const auto& it : cmds_)
		{
			cout << it << endl;
		}

		return true;
	}

	return false;
}