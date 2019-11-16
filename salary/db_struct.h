#pragma once

#include <string>
#include <chrono>
#include <sstream>

enum class employee_type
{
	UNSPECIFIED = 0,
	HOURLY_WORKER = 1,
	MONTHLY_WORKER = 2,
	COMMISSIONED_WORKER = 3,
};

struct salary_employee
{
	int id;
	std::string name;
	std::string address;
	employee_type emp_type;
	int society_dues;
	int service_amount;
	std::chrono::system_clock::time_point create_time;

	std::string to_string() const
	{
		std::stringstream ss;
		ss << "id: " << id
			<< " name: " << name
			<< " address: " << address
			<< " type: " << static_cast<int>(emp_type)
			<< " society_dues: " << society_dues
			<< " service_amount: " << service_amount
			<< " create_time: " << timepoint_to_string(create_time);

		return ss.str();
	}

	std::string timepoint_to_string(std::chrono::system_clock::time_point tp) const
	{
		auto t = std::chrono::system_clock::to_time_t(tp);
		tm tm;
		localtime_s(&tm, &t);
		char sztime[80] = { 0 };
		strftime(sztime, sizeof(sztime), "%Y-%m-%d %X", &tm);
		return sztime;
	}
};

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