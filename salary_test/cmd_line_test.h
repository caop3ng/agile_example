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

TEST(ExecuteCmd, Help)
{
	command_line cmd_line;
	EXPECT_TRUE(cmd_line.exec_command(Command::kHelp));
}