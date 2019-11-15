#include "game.h"

Game::Game()
	: itsCurrentFrame(1),
	firstThrowInFrame(true)
	 
{
}

int Game::score()
{
	return scoreForFrame(itsCurrentFrame);
}

int Game::scoreForFrame(int theFrame)
{
	return itsScorer.scoreForFrame(theFrame);
}

void Game::add(int pins)
{
	itsScorer.addThrow(pins);
	adjustCurrentFrame(pins);
}

void Game::adjustCurrentFrame(int pins)
{
	if (lastBallInFrame(pins))
	{
		advanceFrame();
		firstThrowInFrame = true;
	}
	else
	{
		firstThrowInFrame = false;
	}
}

//int Game::getCurrentFrame() const
//{
//	return itsCurrentFrame;
//}