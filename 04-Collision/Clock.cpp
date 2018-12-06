#include "Clock.h"

void Clock::turnOnClock()
{
	isOn = true;
}

void Clock::turnOffClock()
{
	isOn = false;
}

void Clock::CreateWeapon(float x, float y, float nx)
{
	isFinished = false;
}

void Clock::GetBoundingBox(float & l, float & t, float & r, float & b)
{
}

void Clock::Render()
{
}

Clock::Clock()
{

	isFinished = true;
	isOn = false;
}


Clock::~Clock()
{
}
