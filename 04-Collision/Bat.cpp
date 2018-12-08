#include "Bat.h"



void Bat::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);
	if (GetTickCount() - freezeTime_Start > ENEMY_FREEZE_TIME)
	{
		if (freezed == true)
		{
			freezeTime_Start = 0;
			freezed = false;
		}
	}
	
	if (freezed == false)
	{
		x += dx;
		y += dy;
	}
	
	if (vy < 0 && y < this->x1 - 20)
	{
		y = this->x1 - 20; vy = -vy;
	}

	if (vy > 0 && y > this->x1 + 20)
	{
		y = this->x1 + 20; vy = -vy;
	}
	if (x<Camera::GetInstance()->GetPosition().x || x>Camera::GetInstance()->GetPosition().x + SCREEN_WIDTH)
		this->SetState(BAT_STATE_INACTIVE);
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
	if (this->freezed == true)
	{

		if (this->nx == 1)
		{
			ani = BAT_ANI_FREEZE_RIGHT;
			animations[ani]->Render(x, y);
		}
		else
		{

			ani = BAT_ANI_FREEZE_LEFT;
			animations[ani]->Render(x, y);
		}
	}
	else
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

	}

}
