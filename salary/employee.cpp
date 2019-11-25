#include "salary.h"
#include "employee.h"

salary_employee::salary_employee()
	: id(0),
	employee_type_(employee_type::UNSPECIFIED),
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
		<< " type: " << employee_type_descriptor(employee_type_) << "\n"
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

bool salary_employee::parse(const std::vector<std::string>& v)
{
	try
	{
		id = atoi(v[0].c_str());
		name = v[1];
		address = v[2];
		employee_type_ = static_cast<employee_type>(atoi(v[3].c_str()));
		if (!IsValidEmployeeType(employee_type_))
		{
			assert(0);
			return false;
		}
		society_dues = atoi(v[4].c_str());
		service_amount = atoi(v[5].c_str());
		monthly_pay = atoi(v[6].c_str());
		payment_mode_ = static_cast<payment_mode>(atoi(v[7].c_str()));
		
		tm tm_t;
		int ret = sscanf_s(v[8].c_str(), "%d-%d-%d %d:%d:%d", &tm_t.tm_year, &tm_t.tm_mon, &tm_t.tm_mday,
			&tm_t.tm_hour, &tm_t.tm_min, &tm_t.tm_sec);

		if (ret != 6)
		{
			return false;
		}

		tm_t.tm_year -= 1900;
		tm_t.tm_mon -= 1;

		create_time = std::chrono::system_clock::from_time_t(mktime(&tm_t));
		
	}
	catch (...)
	{
		return false;
	}

	return true;
}