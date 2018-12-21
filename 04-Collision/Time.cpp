#include "Time.h"



Time::Time()
{
	x = 300;
	count = 0;
}


Time::~Time()
{
}


void Time::Update(DWORD dt)
{
	count = count + dt;
	if (count >= 1000)
	{
		count = count % 1000;
		x = x - 1;
	}
}
