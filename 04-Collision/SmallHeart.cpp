#include "SmallHeart.h"



void SmallHeart::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down

	vy += ITEM_GRAVITY/1.5;
	//
	// TO-DO: make sure Goomba can interact with the world and to each of them too!
	// 
	bool chamDat = false;
	
	
	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	CalcPotentialCollisions(colliable_objects, coEvents);

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
		//x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		//y += min_ty * dy + ny * 0.4f;

		if (nx != 0) vx = 0;
		if (ny != 0)
		{
			vy = 0;
			chamDat = true;
		}
		



	}
	if (chamDat == false)
	{
		if (vx < 0 && x < this->x1 - 10) {
			x = this->x1 - 10; vx = -vx;
		}

		if (vx > 0 && x > this->x1 + 10) {
			x = this->x1 + 10; vx = -vx;
		}
	}
	else
	{
		vx = 0;
	}
	
	//clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

SmallHeart::SmallHeart(int x2)
{
	x1 = x2;
	state = ITEM_STATE_INACTIVE;
}


SmallHeart::~SmallHeart()
{
}


void SmallHeart::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + BIGHEART_BBOX_WIDTH;
	bottom = y + BIGHEART_BBOX_HEIGHT;
}



void SmallHeart::Render()
{
	if (this->GetState() == ITEM_STATE_ACTIVE)
	{
		animations[0]->Render(x, y);
		//RenderBoundingBox(100);
	}


}

void SmallHeart::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case ITEM_STATE_ACTIVE:
		vx = SMALLHEART_WALKING_SPEED;
	default:
		break;
	}

}
