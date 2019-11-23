// salary_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <gtest/gtest.h>
#include "util.cpp"
#include "employee.cpp"
#include "db.cpp"

#include "util_test.h"
#include "db_test.h"
#include "cmd_line_test.h"
#include "pay_test.h"

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}