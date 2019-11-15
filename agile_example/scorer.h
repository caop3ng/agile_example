#pragma once
#include <array>

class Scorer
{
public:
	Scorer()
		: itsCurrentThrow(0)
		, itsThrows{ 0 }
	{
	}

	void addThrow(int pins)
	{
		itsThrows[itsCurrentThrow++] = pins;
	}

	int scoreForFrame(int theFrame)
	{
		ball = 0;
		int score = 0;

		for (int currentFrame = 0; currentFrame < theFrame; currentFrame++)
		{
			if (strike())
			{
				score += 10 + nextTwoBallsForStrike();
				ball++;
			}
			else if (spare())
			{
				score += 10 + nextBallForSpare();
				ball += 2;
			}
			else
			{
				score += twoBallsInFrame();
				ball += 2;
			}
		}

		return score;
	}

	int nextTwoBallsForStrike() const
	{
		return itsThrows[ball + 1] + itsThrows[ball + 2];
	}

	bool strike() const
	{
		return itsThrows[ball] == 10;
	}

	int twoBallsInFrame() const
	{
		return itsThrows[ball] + itsThrows[ball + 1];
	}

	bool spare() const
	{
		return (itsThrows[ball] + itsThrows[ball + 1]) == 10;
	}

	int nextBallForSpare() const
	{
		return itsThrows[ball + 2];
	}

private:
	int ball;
	std::array<int, 21> itsThrows;
	int itsCurrentThrow;
};
