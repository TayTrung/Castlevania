#include "EffectFire.h"



void EffectFire::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = t = r = b = 0;
}

void EffectFire::Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects)
{
	CGameObject::Update(dt);


	if (GetTickCount() - effectTime_start > EFFECT_TIME)
	{
		effectTime_start = 0;
		effectTime = false;
		this->SetState(EFFECT_STATE_INACTIVE);
	}

}

void EffectFire::Render()
{
	int ani;
	if (this->GetState() == EFFECT_STATE_ACTIVE)
	{
		if (this->type == 0)
			ani = EFFECT_ANI_FIRE;
		else
			if (this->type == 1)
				ani = EFFECT_ANI_ROCK;
			else
				if (this->type == 2)
					ani = EFFECT_ANI_WATER;

		animations[ani]->Render(x, y);
	}
	
}

void EffectFire::SetState(int state)
{
	CGameObject::SetState(state);

		switch (state)
		{
		case EFFECT_STATE_ACTIVE:
			StartEffect();
			break;
		}
}

EffectFire::EffectFire()
{
}


EffectFire::~EffectFire()
{
}
