#pragma once

#include <gtest/gtest.h>
#include "command_line.cpp"

TEST(CmdLine, ParseValidCommand)
{
	command_line cmd_line;
	EXPECT_EQ(cmd_line.parse("list"), Command::kList);
	EXPECT_EQ(cmd_line.parse("add"), Command::kAdd);
	EXPECT_EQ(cmd_line.parse("change"), Command::kChange);
	EXPECT_EQ(cmd_line.parse("help"), Command::kHelp);
}

TEST(CmdLine, ParseValidCommandWithWhiteSpace)
{
	command_line cmd_line;
	EXPECT_EQ(cmd_line.parse("list  "), Command::kList);
	EXPECT_EQ(cmd_line.parse("   add"), Command::kAdd);
	EXPECT_EQ(cmd_line.parse("  ch ange"), Command::kUnknown);
	EXPECT_EQ(cmd_line.parse("h e lp"), Command::kUnknown);
}

TEST(CmdLine, ParseUnExistCommand)
{
	command_line cmd_line;
	EXPECT_EQ(cmd_line.parse("abc"), Command::kUnknown);
	EXPECT_EQ(cmd_line.parse(""), Command::kUnknown);
	EXPECT_EQ(cmd_line.parse("   "), Command::kUnknown);
}

TEST(ExecuteCmd, All)
{
	auto& db = salary_db::instance();
	db.add_employee(0, "ll", "beijing", employee_type::HOURLY_WORKER);
	db.add_employee(1, "xiaoming", "shanghai", employee_type::COMMISSIONED_WORKER);
	db.add_employee(2, "zhangsan", "guangzhou", employee_type::MONTHLY_WORKER);

	string id = typeid(db).name();

	command_line cmd_line;
	EXPECT_TRUE(cmd_line.exec_command(Command::kHelp));
	EXPECT_TRUE(cmd_line.exec_command(Command::kList));
	//EXPECT_TRUE(cmd_line.exec_command(Command::kChange));
	//EXPECT_TRUE(cmd_line.exec_command(Command::kAdd));
	//EXPECT_FALSE(cmd_line.exec_command(Command::kUnknown));
}

