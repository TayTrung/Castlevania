#include "MorningStar.h"



void MorningStar::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	vy += ITEM_GRAVITY * dt;


	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	CalcPotentialCollisions(colliable_objects, coEvents);

	//// No collision occured, proceed normally
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
		if (ny != 0) vy = 0;

	}
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void MorningStar::Render()
{
	if (this->GetState() == ITEM_STATE_ACTIVE)
	{
		animations[0]->Render(x, y);
		//RenderBoundingBox(100);
	}
}

void MorningStar::SetState(int state)
{
	this->state = state;
}

void MorningStar::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + MSTAR_BBOX_WIDTH;
	bottom = y + MSTAR_BBOX_HEIGHT;
}

MorningStar::MorningStar()
{
	state = ITEM_STATE_ACTIVE;
}


MorningStar::~MorningStar()
{
}
