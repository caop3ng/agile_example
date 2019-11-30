#include "salary.h"
#include "db_struct.h"

using namespace std;

bool employee_time_card::parse(std::vector<std::string> values)
{
	if (values.size() != property_count())
	{
		return false;
	}

	try
	{
		employee_id = atoi(values[static_cast<int>(TimeCardProperty::kEmployeeId)].c_str());
		
		tm tmp = { 0 };
		sscanf_s(values[static_cast<int>(TimeCardProperty::kWordDate)].c_str(), "%d-%d-%d", &tmp.tm_year, &tmp.tm_mon, &tmp.tm_mday);
		tmp.tm_year -= 1900;
		tmp.tm_mon -= 1;
		time_t t = mktime(&tmp);
		
		if (t == -1)
		{
			assert(0);
			return false;
		}

		work_date = std::chrono::system_clock::from_time_t(t);
		
		hours = atoi(values[static_cast<int>(TimeCardProperty::kHours)].c_str());

		paid = atoi(values[static_cast<int>(TimeCardProperty::kPaid)].c_str());
	}
	catch (...)
	{
		return false;
	}

	return true;
	
}

std::string employee_time_card::serialize() const
{
	stringstream ss;
	ss << employee_id
		<< ";" << time_point_calendar(work_date)
		<< ";" << hours
		<< ";" << static_cast<int>(paid);

	return ss.str();
}

std::string employee_time_card::to_string() const
{
	stringstream ss;
	ss << "employee_id: " << employee_id
		<< ", work_date: " << time_point_calendar(work_date)
		<< ", hours: " << hours
		<< ", paid: " << paid;

	return ss.str();
}

bool employee_time_card::payday(time_t t)
{
	if (t == -1)
	{
		assert(0);
		return false;
	}

	tm tmp;
	localtime_s(&tmp, &t);

	return tmp.tm_wday == PAY_WEEKDAY;
}