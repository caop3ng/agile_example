#pragma once

enum class employee_type
{
	UNSPECIFIED = 0,
	HOURLY_WORKER = 1,
	MONTHLY_WORKER = 2,
	COMMISSIONED_WORKER = 3,
	kEmployeeType_MAX = COMMISSIONED_WORKER,
};

inline bool IsValidEmployeeType(employee_type type)
{
	if (type <= employee_type::UNSPECIFIED
		|| type > employee_type::kEmployeeType_MAX)
	{
		return false;
	}

	return true;
}

class salary_employee
{
public:
	std::string to_string() const;

	std::string timepoint_to_string(std::chrono::system_clock::time_point tp) const;

	bool pay(std::chrono::system_clock::time_point pay_day);

private:

	bool pay_monthly(std::chrono::system_clock::time_point pay_day);

public:
	int id;
	std::string name;
	std::string address;
	employee_type emp_type;
	int society_dues;
	int service_amount;
	std::chrono::system_clock::time_point create_time;
};
