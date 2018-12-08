#include "FireBall.h"



FireBall::FireBall()
{
}


FireBall::~FireBall()
{
}

void FireBall::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = left + FIREBALL_BBOX_WIDTH;
	bottom = top + FIREBALL_BBOX_HEIGHT;

}

void FireBall::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	CGameObject::Update(dt);

	x += dx;
	y += dy;
	float xc = Camera::GetInstance()->GetPosition().x;

	if (this->x > xc + SCREEN_WIDTH || this->x < xc)
	{
		this->SetState(FIREBALL_STATE_INACTIVE);
	}
}

void FireBall::Render()
{
	if (this->GetState() == FIREBALL_STATE_ACTIVE_RIGHT)
	{
		int ani;
		ani = FIREBALL_ANI_RIGHT;
		animations[ani]->Render(x, y);
	}
	else
		if (this->GetState() == FIREBALL_STATE_ACTIVE_LEFT)
		{
			int ani;
			ani = FIREBALL_ANI_LEFT;
			animations[ani]->Render(x, y);
		}
}

void FireBall::SetState(int state)
{
	CGameObject::SetState(state);
	
	switch(state)
	{
	case FIREBALL_STATE_ACTIVE_LEFT:
		vx = -FIREBALL_SPEED;
		break;
	case FIREBALL_STATE_ACTIVE_RIGHT:
		vx = FIREBALL_SPEED;
		break;

	}
}
