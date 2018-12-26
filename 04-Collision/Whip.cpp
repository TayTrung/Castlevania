#include "Whip.h"




void Whip::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	float x, y;
	this->GetPosition(x, y);
	
	if (this->nx > 0)
	{
		if (this->type == VAMPIRE_KILLER)
		{
			l = x + offsetXRightSide;
			t = y + offsetYBothSide;
			r = l + VAMPIRE_KILLER_BBOX_WIDTH;
			b = t + VAMPIRE_KILLER_BBOX_HEIGHT;

		}
		if (this->type == CHAIN_WHIP)
		{
			l = x + offsetXRightSide;
			t = y + offsetYBothSide;
			r = l + CHAIN_WHIP_BBOX_WIDTH;
			b = t + CHAIN_WHIP_BBOX_HEIGHT;
		}
		if (this->type == MORNING_STAR)
		{
			l = x+ offsetXRightSide;
			t = y+ offsetYBothSide;
			r = l + MORNING_STAR_BBOX_WIDTH;
			b = t + MORNING_STAR_BBOX_HEIGHT;
		}
	}
	else
	{
		if (this->type == VAMPIRE_KILLER)
		{
			l = x- offsetXLeftSide - VAMPIRE_KILLER_BBOX_WIDTH;
			t = y+ offsetYBothSide;
			r = x-offsetXLeftSide;
			b = t + VAMPIRE_KILLER_BBOX_HEIGHT;

		}
		if (this->type == CHAIN_WHIP)
		{
			l = x - offsetXLeftSide - CHAIN_WHIP_BBOX_WIDTH;
			t = y + offsetYBothSide;
			r = x - offsetXLeftSide;
			b = t + CHAIN_WHIP_BBOX_HEIGHT;
		}
		if (this->type == MORNING_STAR)
		{
			l = x-2- offsetXLeftSide - MORNING_STAR_BBOX_WIDTH;
			t = y + offsetYBothSide;
			r = x - offsetXLeftSide;
			b = t + MORNING_STAR_BBOX_HEIGHT;
		}
	}
	

}

void Whip::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
	if (isFinished)
		return;
	CGameObject::Update(dt, coObjects);
	

}

void Whip::Render()
{
	/*if (this->GetState() == WHIP_STATE_INACTIVE)
	{
		ani = WHIP_ANI_INACTIVE;
		
	}
	else
	*/

		if (isFinished)
		return;

		if (this->GetState() == WHIP_STATE_ACTIVE_LEFT)
		{
			ani = WHIP_ANI_LEFT;
			animations[ani]->Render(x, y);
		}
		else
		{
			ani = WHIP_ANI_RIGHT;
			animations[ani]->Render(x, y);
		}
	//	RenderBoundingBox(100);



		if (animations[ani]->GetCurrentFrame() == 3)
		{
			isFinished = true;
		}
		if (animations[ani]->GetCurrentFrame() == 2)
		{
			isAllowedToCollide = true;
			//RenderBoundingBox(50);
		}
		else
			isAllowedToCollide = false;
	
}

void Whip::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case WHIP_STATE_ACTIVE_RIGHT:
		nx = 1;
		break;
	case WHIP_STATE_ACTIVE_LEFT:
		nx = -1;
		break;
	case WHIP_STATE_INACTIVE:
		break;
	}
}

void Whip::levelUpWhip()
{

	if (type == VAMPIRE_KILLER)
	{
		this->DeleteAllAnimation();

		type = CHAIN_WHIP;
		this->AddAnimation(712);
		this->AddAnimation(713);

	}
	else
	{
		this->DeleteAllAnimation();
		type = MORNING_STAR;
		this->AddAnimation(714);
		this->AddAnimation(715);
	}

}

void Whip::CreateWeapon(float x, float y, float nx)
{
	isFinished = false;
	this->SetPosition(x, y);
	if (nx == 1)
		this->SetState(WHIP_STATE_ACTIVE_RIGHT);
	else
		this->SetState(WHIP_STATE_ACTIVE_LEFT);
}
