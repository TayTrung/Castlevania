#include "Axe.h"


void Axe::turnOnAxe()
{
	isOn = true;
}

void Axe::turnOffAxe()
{
	isOn = false;
}

void Axe::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	//	float x, y;
	//	this->GetPosition(x, y);

		//if (this->nx > 0)
	{
		l = x;
		t = y;
		r = l + AXE_BBOX_WIDTH;
		b = t + AXE_BBOX_HEIGHT;
	}
	/*else
	{
		l = x-32;
		t = y;
		r = x - 5;
		b = t + 18;
	}*/

}

void Axe::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	CGameObject::Update(dt);

	// Simple fall down
	vy += ITEM_GRAVITY/2 * dt;


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	//CalcPotentialCollisions(colliable_objects, coEvents);

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
			//this->SetState(AXE_STATE_INACTIVE);
		}
			

	}
	float xcam, ycam;
	xcam=camera->GetPosition().x;
	ycam=camera->GetPosition().y;
	if(this->x<xcam || this->x>xcam+SCREEN_WIDTH || this->y>ycam+SCREEN_HEIGHT)
		this->SetState(AXE_STATE_INACTIVE);
	if (this->GetState() != AXE_STATE_INACTIVE)
	{
		sound->GetInstance()->playSound(eTagSound::Ax, true);
	}
	else
		sound->GetInstance()->stopSound(eTagSound::Ax);
	//clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];


}

void Axe::Render()
{
	int ani;
	if (this->GetState() == AXE_STATE_ACTIVE_LEFT)
	{
		ani = AXE_ANI_LEFT;
		animations[ani]->Render(x, y);
		//RenderBoundingBox(50);
	}
	else if (this->GetState() == AXE_STATE_ACTIVE_RIGHT)
	{
		ani = AXE_ANI_RIGHT;
		animations[ani]->Render(x, y);
		//RenderBoundingBox(50);
	}

	//else this->GetState() == DAGGER_STATE_INACTIVE;


}

void Axe::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case AXE_STATE_ACTIVE_RIGHT:
		vx = AXE_FLYING_SPEED;
		vy = -1.5*AXE_FLYING_SPEED ;
		nx = 1;
		break;
	case AXE_STATE_ACTIVE_LEFT:
		vx = -AXE_FLYING_SPEED;
		vy = -1.5*AXE_FLYING_SPEED ;
		nx = -1;
		break;
	case AXE_STATE_INACTIVE:
		vy = 0;
		vx = 0;
		break;
	}
}

void Axe::CreateWeapon(float x, float y, float nx)
{
	this->SetPosition(x, y);
	this->nx = nx;
	isFinished = false;
	vx = nx * AXE_FLYING_SPEED;
	vy = -AXE_FLYING_SPEED;
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

Axe::Axe()
{
	camera = Camera::GetInstance();
	isOn = false;
	vx = 0;
	isFinished = true;
	this->SetState(AXE_STATE_INACTIVE);
}



Axe::~Axe()
{
}







