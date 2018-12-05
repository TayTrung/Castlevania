#include "Door.h"

void Door::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = t = r = b = 0;
}

void Door::Render()
{
	if (state != DOOR_STATE_INACTIVE)
	{
		int ani;
		if (state == DOOR_STATE_ACTIVE_OPENED)
		{
			ani = DOOR_ANI_OPENED;
		}
		else
			if (state == DOOR_STATE_ACTIVE_CLOSED)
			{
				ani = DOOR_ANI_CLOSED;
			}

		animations[ani]->Render(x, y);
	}

}



Door::Door()
{

}

Door::~Door()
{
}
