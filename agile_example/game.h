#pragma once
#include <vector>
#include <array>
#include "scorer.h"

class Game
{
public:
	Game();
	int score();
	void add(int pins);
	int scoreForFrame(int theFrame);
	//int getCurrentFrame() const;

private:

	void adjustCurrentFrame(int pins);
	void advanceFrame()
	{
		itsCurrentFrame = std::min(10, itsCurrentFrame + 1);
	}
	bool adjustFrameForStrike(int pins)
	{
		if (pins == 10)
		{
			advanceFrame();
			return true;
		}

		return false;
	}

	bool strike(int pins)
	{
		return (firstThrowInFrame && pins == 10);
	}

	bool lastBallInFrame(int pins)
	{
		return strike(pins) || !firstThrowInFrame;
	}

	int itsCurrentFrame;
	bool firstThrowInFrame;
	Scorer itsScorer;
};