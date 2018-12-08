#include "Effect.h"



void Effect::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = t = r = b = 0;
}

void Effect::Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects)
{
	CGameObject::Update(dt);


	if (GetTickCount() - effectTime_start > EFFECT_TIME)
	{
		effectTime_start = 0;
		effectTime = false;
		this->SetState(HOLYWATER_STATE_INACTIVE);
	}

}

void Effect::Render()
{
	int ani;
	if (this->GetState() == EFFECT_STATE_ACTIVE)
	{
		ani = EFFECT_ANI_ACTIVE;
		animations[ani]->Render(x, y);
	}
	
}

void Effect::SetState(int state)
{
	CGameObject::SetState(state);

		switch (state)
		{
		case EFFECT_STATE_ACTIVE:
			StartEffect();
			break;
		}
}

Effect::Effect()
{

}


Effect::~Effect()
{
}
