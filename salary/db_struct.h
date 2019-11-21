#pragma once

#include <string>
#include <chrono>
#include <sstream>

#include "employee.h"

struct employee_time_card
{
	int employee_id;
	std::chrono::system_clock::time_point date_time;
	int hours;
};

struct sales_receipt
{
	int employee_id;
	std::chrono::system_clock::time_point date_time;
	int amount;
};