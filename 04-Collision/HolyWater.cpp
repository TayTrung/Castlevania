#include "HolyWater.h"


void HolyWater::turnOnHolyWater()
{
	isOn = true;
}

void HolyWater::turnOffHolyWater()
{
	isOn = false;
}

void HolyWater::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	//	float x, y;
	//	this->GetPosition(x, y);

		//if (this->nx > 0)
	{
		l = x;
		t = y;
		r = l + HOLYWATER_BBOX_WIDTH;
		b = t + HOLYWATER_BBOX_HEIGHT;
	}
	/*else
	{
		l = x-32;
		t = y;
		r = x - 5;
		b = t + 18;
	}*/

}

void HolyWater::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	CGameObject::Update(dt);

	// Simple fall down
	vy += ITEM_GRAVITY/2 * dt;


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	CalcPotentialCollisions(colliable_objects, coEvents);

	if (GetTickCount() - burnTime_Start >  HOLYWATER_BURN_TIME)
	{
		burnTime_Start = 0;
		if(burning == true)
		{
			this->SetState(HOLYWATER_STATE_INACTIVE);
		}
		burning = false;
	}
	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty * dy + ny * 0.4f;

		if (nx != 0) vx = 0;
		if (ny != 0)
		{
			vy = 0;
			if (this->GetState() != HOLYWATER_STATE_INACTIVE && this->GetState() != HOLYWATER_STATE_BURN)
			{

				this->SetState(HOLYWATER_STATE_BURN);
				StartBurn();
			}
			
		}


	}

	//clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];


}

void HolyWater::Render()
{
	int ani;
	if (this->GetState() == HOLYWATER_STATE_ACTIVE_LEFT)
	{
		ani = HOLYWATER_ANI_LEFT;
		animations[ani]->Render(x, y);
		//RenderBoundingBox(50);
	}
	else if (this->GetState() == HOLYWATER_STATE_ACTIVE_RIGHT)
	{
		ani = HOLYWATER_ANI_RIGHT;
		animations[ani]->Render(x, y);
		//RenderBoundingBox(50);
	}
	else
		if (this->GetState() == HOLYWATER_STATE_BURN)
		{
			ani = HOLYWATER_ANI_BURN;
			animations[ani]->Render(x, y);
			//RenderBoundingBox(50);
		}

	//else this->GetState() == DAGGER_STATE_INACTIVE;


}

void HolyWater::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case HOLYWATER_STATE_ACTIVE_RIGHT:
		vx = AXE_FLYING_SPEED/1.5;
		vy = -AXE_FLYING_SPEED/2;
		nx = 1;
		break;
	case HOLYWATER_STATE_ACTIVE_LEFT:
		vx = -AXE_FLYING_SPEED/1.5;
		vy = -AXE_FLYING_SPEED/2;
		nx = -1;
		break;
	case HOLYWATER_STATE_BURN:
		vy = 0;
		vx = 0;
		break;
	}
}

void HolyWater::CreateWeapon(float x, float y, float nx)
{
	this->SetPosition(x, y);
	this->nx = nx;
	isFinished = false;
	vx = nx * HOLYWATER_FLYING_SPEED;
	vy = -HOLYWATER_FLYING_SPEED;
	//if (nx == -1)
	//{
	//	this->SetState(DAGGER_STATE_ACTIVE_LEFT);
	//}
	//else 
	//	if (nx == 1)
	//	{
	//		this->SetState(DAGGER_STATE_ACTIVE_LEFT);
	//	}
}

HolyWater::HolyWater()
{
	isOn = false;
	vx = 0;
	isFinished = true;
	this->SetState(HOLYWATER_STATE_INACTIVE);
}



HolyWater::~HolyWater()
{
}







