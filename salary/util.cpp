#include "util.h"
#include "salary.h"

#include <boost/date_time/gregorian/gregorian.hpp>

std::string triming(const std::string& text)
{
	std::string whitespace = " \t";

	const auto strBegin = text.find_first_not_of(whitespace);
	if (strBegin == std::string::npos)
		return ""; // no content

	const auto strEnd = text.find_last_not_of(whitespace);
	const auto strRange = strEnd - strBegin + 1;

	return text.substr(strBegin, strRange);
}

bool work_day(boost::date_time::weekdays week_day)
{
	using namespace boost::gregorian;
	return (Monday <= week_day && week_day <= Friday);
}

bool date_is_month_last_work_day(time_t t)
{
	using namespace boost::gregorian;

	try
	{
		tm d;
		localtime_s(&d, &t);

		date today(1900 + d.tm_year, Jan + d.tm_mon, d.tm_mday);

		auto week_day = today.day_of_week();
		if (work_day(week_day.as_enum()))
		{
			date next_work_day = today + days(1);
			while (!work_day(next_work_day.day_of_week().as_enum()))
			{
				next_work_day = next_work_day + days(1);
			}

			date next_month(today.year(), today.month(), 1);
			next_month += months(1);

			if (next_work_day < next_month)
			{
				return false;
			}
			else
			{
				return true;
			}
		}
		else
		{
			return false;
		}
	}
	catch (bad_year)
	{
		std::cout << "bad year" << std::endl;
	}

	return false;
}

std::string time_point_calendar(std::chrono::system_clock::time_point tp)
{
	time_t t = std::chrono::system_clock::to_time_t(tp);
	tm tm_t;
	localtime_s(&tm_t, &t);

	char date[100] = { 0 };
	strftime(date, sizeof(date), "%Y-%m-%d %X", &tm_t);

	return date;
}