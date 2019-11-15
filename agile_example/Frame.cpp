#include "Frame.h"

Frame::Frame()
	: itsScore(0)
{

}

int Frame::getScore()
{
	return itsScore;
}

void Frame::add(int pins)
{
	itsScore += pins;
}