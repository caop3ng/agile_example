#pragma once

#include <string>
#include <chrono>
#include <sstream>
#include <vector>
#include <time.h>

enum class TimeCardProperty
{
	kEmployeeId = 0,
	kWordDate,
	kHours,
	kPaid,
};

struct employee_time_card
{
	int employee_id;
	std::chrono::system_clock::time_point work_date;
	int hours;
	bool paid;
	inline int property_count() { return 4; }

	bool parse(std::vector<std::string> values);
	std::string serialize() const;
	std::string to_string() const;

	static bool payday(time_t t);
	static const int PAY_WEEKDAY = 5;
};

struct sales_receipt
{
	int employee_id;
	std::chrono::system_clock::time_point date_time;
	int amount;
};