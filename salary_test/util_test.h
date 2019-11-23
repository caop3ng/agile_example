#pragma once

#include "util.h"

#include <gtest/gtest.h>

TEST(Util, LastWorkDay)
{
	tm tm_t = { 0 };
	tm_t.tm_year = 2019 - 1900;
	tm_t.tm_mon = 10;
	tm_t.tm_mday = 23;
	EXPECT_FALSE(date_is_month_last_work_day(mktime(&tm_t)));

	tm_t.tm_mday = 30;
	EXPECT_FALSE(date_is_month_last_work_day(mktime(&tm_t)));

	tm_t.tm_mday = 28;
	EXPECT_FALSE(date_is_month_last_work_day(mktime(&tm_t)));

	tm_t.tm_mon = 9;
	tm_t.tm_mday = 31;
	EXPECT_TRUE(date_is_month_last_work_day(mktime(&tm_t)));

	tm_t.tm_mon = 7;
	tm_t.tm_mday = 30;
	EXPECT_TRUE(date_is_month_last_work_day(mktime(&tm_t)));
}
