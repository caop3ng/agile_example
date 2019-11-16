// salary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include "salary.h"
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include "command_line.h"

using namespace std;

int main()
{
	command_line cmd_line;
	cout << "=== Welcome to employee system. ===" << endl;
	cout << endl;
	cmd_line.exec_command(Command::kHelp);
	cout << ">>> ";
	string line;
	while (getline(cin, line))
	{
		if (line.empty())
		{
			continue;
		}

		line = triming(line);
		auto cmd = cmd_line.parse(line);

		if (cmd == Command::kUnknown)
		{
			cout << "unknown command" << endl;
			cout << ">>> ";
			continue;
		}

		if (cmd == Command::kExit)
		{
			return 0;
		}

		cmd_line.exec_command(cmd);

		cout << ">>> ";
	}

}
