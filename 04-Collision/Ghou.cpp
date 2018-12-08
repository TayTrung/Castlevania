#include "Ghou.h"



void Ghou::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + GHOU_BBOX_WIDTH;
	bottom = y + GHOU_BBOX_HEIGHT;
}

void Ghou::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

	CGameObject::Update(dt);

	// Simple fall down
	if (freezed == false)
		vy += ITEM_GRAVITY * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	CalcPotentialCollisions(coObjects, coEvents);
	if (GetTickCount() - freezeTime_Start > ENEMY_FREEZE_TIME)
	{
		freezeTime_Start = 0;
		freezed = false;


	}
	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		if (freezed == false)
		{
			x += dx;
			y += dy;
		}
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty * dy + ny * 0.4f;

		//if (nx != 0) vx = 0;
		if (ny != 0) vy = 0;


	}
	
	//clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];

	float x1, y1;
	x1 = Camera::GetInstance()->GetPosition().x;
	
 	if (x<x1 || x>x1 + SCREEN_WIDTH)
		this->SetState(GHOU_STATE_INACTIVE);
	


}


void Ghou::Render()
{
	int ani;
	if (this->freezed==true)
	{

		if (this->nx == 1)
		{
			ani = GHOU_ANI_FREEZE_RIGHT;
			animations[ani]->Render(x, y);
		}
		else
		{

			ani = GHOU_ANI_FREEZE_LEFT;
			animations[ani]->Render(x, y);
		}
	}

	else
		if (this->GetState() == GHOU_STATE_ACTIVE_RIGHT)
		{
			ani = GHOU_ANI_RIGHT;
			animations[ani]->Render(x, y);
			//	RenderBoundingBox(100);
		}
		else
			if (this->GetState() == GHOU_STATE_ACTIVE_LEFT)
			{

				ani = GHOU_ANI_LEFT;
				animations[ani]->Render(x, y);
				//RenderBoundingBox(100);
			}



}

void Ghou::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case GHOU_STATE_ACTIVE_RIGHT:
		vx = GHOU_WALKING_SPEED;
		nx = 1;
		break;
	case GHOU_STATE_ACTIVE_LEFT:
		vx = -GHOU_WALKING_SPEED;
		nx = -1;
		break;
	}
}

Ghou::Ghou()
{
}


Ghou::~Ghou()
{
}
