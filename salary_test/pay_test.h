#pragma once

#include <iostream>
#include <gtest/gtest.h>
#include <time.h>

#include <boost/date_time/gregorian/gregorian.hpp>

using namespace std;
using namespace chrono;

TEST(Pay, MonthlyEmployee)
{
	auto& db = salary_db::instance();
	salary_employee emp;
	emp.id = 0;
	emp.name = "cc";
	emp.address = "xx";

	db.add_employee(emp);

	auto need_pay_emp = db.get_employee(0);

	auto now = chrono::system_clock::now();
	auto now_t = chrono::system_clock::to_time_t(now);
	tm pay_day;
	localtime_s(&pay_day, &now_t);
	pay_day.tm_mon = 10;
	pay_day.tm_mday = 29;
	auto pay_day_t = mktime(&pay_day);
	auto today = chrono::system_clock::from_time_t(pay_day_t);

	EXPECT_TRUE(need_pay_emp.pay(today));
}