#pragma once
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>

std::string triming(const std::string& text);

bool work_day(boost::date_time::weekdays week_day);

bool date_is_month_last_work_day(time_t t);