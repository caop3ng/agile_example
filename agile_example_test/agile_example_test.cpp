// agile_example_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <gtest/gtest.h>
#include "Frame.cpp"
#include "game.cpp"

using namespace std;

TEST(TestFrame, ScoreNoThrows)
{
	Frame f;
	EXPECT_EQ(0, f.getScore());
}

TEST(TestFrame, AddOneThrow)
{
	Frame f;
	f.add(5);
	EXPECT_EQ(5, f.getScore());
}

/////////////////////////////////////////////////////////////////////

//TEST(TestGame, OneThrows)
//{
//	Game g;
//	g.add(5);
//	EXPECT_EQ(5, g.score());
//	EXPECT_EQ(1, g.getCurrentFrame());
//}

TEST(TestGame, TwoThrowsNoMark)
{
	Game g;
	g.add(5);
	g.add(4);
	EXPECT_EQ(9, g.score());
	//EXPECT_EQ(2, g.getCurrentFrame());
}

TEST(TestGame, FourThrowsNoMark)
{
	Game g;
	g.add(5);
	g.add(4);
	g.add(7);
	g.add(2);
	EXPECT_EQ(18, g.score());
	EXPECT_EQ(9, g.scoreForFrame(1));
	EXPECT_EQ(18, g.scoreForFrame(2));
	//EXPECT_EQ(3, g.getCurrentFrame());
}

TEST(TestGame, SimpleSpare)
{
	Game g;
	g.add(3);
	g.add(7);
	g.add(3);

	EXPECT_EQ(13, g.scoreForFrame(1));
	//EXPECT_EQ(2, g.getCurrentFrame());
}

TEST(TestGame, SimpleFrameAfterSpare)
{
	Game g;
	g.add(3);
	g.add(7);
	g.add(3);
	g.add(2);

	EXPECT_EQ(13, g.scoreForFrame(1));
	EXPECT_EQ(18, g.scoreForFrame(2));
	EXPECT_EQ(18, g.score());
	//EXPECT_EQ(3, g.getCurrentFrame());
}

TEST(TestGame, test)
{
	Game g;
	g.add(10);
	g.add(3);
	g.add(6);

	EXPECT_EQ(19, g.scoreForFrame(1));
	EXPECT_EQ(28, g.score());
	//EXPECT_EQ(3, g.getCurrentFrame());
}

TEST(TestGame, PerfectGame)
{
	Game g;
	for (int i = 0; i < 12; i++)
	{
		g.add(10);
	}

	EXPECT_EQ(300, g.score());
	//EXPECT_EQ(11, g.getCurrentFrame());
}

TEST(TestGame, EndOfArray)
{
	Game g;
	for (int i = 0; i < 9; i++)
	{
		g.add(0);
		g.add(0);
	}

	g.add(2);
	g.add(8);
	g.add(10);

	EXPECT_EQ(20, g.score());
}

TEST(TestGame, SampleGame)
{
	Game g;
	array<int, 19> throws = { 1,4,4,5,6,4,5,5,10,0,1,7,3,6,4,10,2,8,6 };
	for (auto pins : throws)
	{
		g.add(pins);
	}

	EXPECT_EQ(133, g.score());
}

TEST(TestGame, HeartBreak)
{
	Game g;
	for (int i = 0; i < 11; i++)
	{
		g.add(10);
	}

	g.add(9);

	EXPECT_EQ(299, g.score());
}

TEST(TestGame, TenFrameSpare)
{
	Game g;
	for (int i = 0; i < 9; i++)
	{
		g.add(10);
	}

	g.add(9);
	g.add(1);
	g.add(1);

	EXPECT_EQ(270, g.score());
}

TEST(TestGame, AfterStrike)
{
	Game g;
	g.add(7);
	g.add(2);
	g.add(10);
	g.add(2);
	g.add(5);

	EXPECT_EQ(9 + 10 + 7 + 7, g.score());
}

TEST(TestGame, TwoStrkie)
{
	Game g;
	g.add(5);
	g.add(2);
	g.add(10);
	g.add(10);
	g.add(5);
	g.add(2);

	EXPECT_EQ(5+2+10+10+5+10+5+2+5+2, g.score());
}

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
