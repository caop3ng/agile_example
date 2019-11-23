#include "salary.h"
#include "employee.h"

salary_employee::salary_employee()
	: id(0),
	emp_type(employee_type::UNSPECIFIED),
	society_dues(0),
	service_amount(0),
	monthly_pay(0),
	payment_mode_(payment_mode::UNSPECIFIED)
{
}

std::string salary_employee::to_string() const
{
	std::stringstream ss;
	ss << "id: " << id << "\n"
		<< " name: " << name << "\n"
		<< " address: " << address << "\n"
		<< " type: " << employee_type_descriptor(emp_type) << "\n"
		<< " society_dues: " << society_dues << "\n"
		<< " service_amount: " << service_amount << "\n"
		<< " monthly_pay: " << monthly_pay << "\n"
		<< " payment_mode: " << payment_mode_descriptor(payment_mode_) << "\n"
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