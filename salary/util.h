#pragma once
#include <string>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <chrono>

std::string triming(const std::string& text);

bool work_day(boost::date_time::weekdays week_day);

bool date_is_month_last_work_day(time_t t);

std::string time_point_calendar(std::chrono::system_clock::time_point tp);