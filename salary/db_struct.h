#pragma once

#include <string>
#include <chrono>

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