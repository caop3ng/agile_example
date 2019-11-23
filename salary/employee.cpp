#include "salary.h"
#include "employee.h"

std::string salary_employee::to_string() const
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

std::string salary_employee::timepoint_to_string(std::chrono::system_clock::time_point tp) const
{
	auto t = std::chrono::system_clock::to_time_t(tp);
	tm tm;
	localtime_s(&tm, &t);
	char sztime[80] = { 0 };
	strftime(sztime, sizeof(sztime), "%Y-%m-%d %X", &tm);
	return sztime;
}

bool salary_employee::pay(std::chrono::system_clock::time_point pay_day)
{
	if (emp_type == employee_type::MONTHLY_WORKER)
	{
		return pay_monthly(pay_day);
	}

	return false;
}

bool salary_employee::pay_monthly(std::chrono::system_clock::time_point pay_day)
{
	
	return false;
}