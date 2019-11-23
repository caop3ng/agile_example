#pragma once

#include <chrono>
#include <assert.h>

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

inline std::string employee_type_descriptor(employee_type type)
{
	switch (type)
	{
	case employee_type::UNSPECIFIED:
		return "employee type unspecified";
		break;
	case employee_type::HOURLY_WORKER:
		return "hourly worker";
		break;
	case employee_type::MONTHLY_WORKER:
		return "monthly worker";
		break;
	case employee_type::COMMISSIONED_WORKER:
		return "commissioned worker";
		break;
	default:
		assert(0);
		return "";
		break;
	}
}

enum class payment_mode
{
	UNSPECIFIED = 0,
	kPostalAddress,
	kCashierKeeping,
	kBank,
};

inline std::string payment_mode_descriptor(payment_mode mode)
{
	switch (mode)
	{
	case payment_mode::UNSPECIFIED:
		return "payment mode unspecified";
		break;
	case payment_mode::kPostalAddress:
		return "postal address";
		break;
	case payment_mode::kCashierKeeping:
		return "cashier keeping";
		break;
	case payment_mode::kBank:
		return "bank";
		break;
	default:
		assert(0);
		return "";
		break;
	}
}

class salary_employee
{
public:
	salary_employee();

	std::string to_string() const;

	std::string timepoint_to_string(std::chrono::system_clock::time_point tp) const;

public:
	int id;
	std::string name;
	std::string address;
	employee_type emp_type;
	int society_dues;
	int service_amount;
	int monthly_pay;
	payment_mode payment_mode_;
	std::chrono::system_clock::time_point create_time;
};
