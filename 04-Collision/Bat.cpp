#include "Bat.h"



void Bat::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);
	
	// No collision occured, proceed normally
	x += dx;
	y += dy;

	if (vy < 0 && y < this->x1 - 10) {
		y = this->x1 - 10; vy = -vy;
	}

	if (vy > 0 && y > this->x1 + 10) {
		y = this->x1 + 10; vy = -vy;
	}
}

Bat::Bat(int x2)
{
	x1 = x2;
	
}


Bat::~Bat()
{
}


void Bat::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + BAT_BBOX_WIDTH;
	bottom = y + BAT_BBOX_HEIGHT;
}



void Bat::Render()
{
	int ani;
	if (this->GetState() == BAT_STATE_ACTIVE_RIGHT)
	{
		ani = BAT_ANI_RIGHT;
		animations[ani]->Render(x, y);
		//	RenderBoundingBox(100);
	}
	else
		if (this->GetState() == BAT_STATE_ACTIVE_LEFT)
		{

			ani = BAT_ANI_LEFT;
			animations[ani]->Render(x, y);
			//RenderBoundingBox(100);
		}
}

void Bat::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BAT_STATE_ACTIVE_RIGHT:
		vx = GHOU_WALKING_SPEED;
		vy = GHOU_WALKING_SPEED/3;
		nx = 1;
		break;
	case BAT_STATE_ACTIVE_LEFT:
		vx = -GHOU_WALKING_SPEED;
		vy = GHOU_WALKING_SPEED / 3;
		nx = -1;
		break;
	case GHOU_STATE_INACTIVE:
		vx = 0;
		break;
	}

}
