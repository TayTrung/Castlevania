#include "Boss.h"



void Boss::Update(DWORD dt, Simon x)
{
}

void Boss::Render()
{
}

void Boss::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BOSS_STATE_MOVE_RIGHT:
		vx = GHOU_WALKING_SPEED;
		vy = 0;
		nx = 1;
		break;
	case BOSS_STATE_MOVE_LEFT:
		vx = -GHOU_WALKING_SPEED;
		vy = 0;
		nx = -1;
		break;
		case



	}
}

void Boss::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + BOSS_BBOX_WIDTH;
	bottom = y + BOSS_BBOX_HEIGHT;
}

Boss::Boss()
{

}


Boss::~Boss()
{
}
