// salary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

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
	auto c1 = Command::kList;
	auto c2 = Command::kList;
	
	cout << sizeof(c1) << endl;

}
