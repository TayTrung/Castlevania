#include "EffectBag.h"



void EffectBag::GetBoundingBox(float & l, float & t, float & r, float & b)
{
	l = t = r = b = 0;
}

void EffectBag::Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects)
{
	CGameObject::Update(dt);


	if (GetTickCount() - effectTime_start > EFFECT_TIME)
	{
		if (effectTime == true)
		{

			this->SetState(EFFECT_STATE_INACTIVE);
		}

		effectTime_start = 0;
		effectTime = false;

	}

}

void EffectBag::Render()
{
	int ani;
	if (this->GetState() == EFFECT_STATE_ACTIVE)
	{
		if (this->type == 0)
			ani = EFFECT_ANI_SCORE_RED;
		else
			if (this->type == 1)
				ani = EFFECT_ANI_SCORE_BLUE;
			else
				if (this->type == 2)
					ani = EFFECT_ANI_SCORE_WHITE;
				else

					if (this->type == 3)
						ani = EFFECT_ANI_SCORE_3COLOR;

		animations[ani]->Render(x, y);
	}

}

void EffectBag::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case EFFECT_STATE_ACTIVE:
		StartEffect();
		break;
	}
}

EffectBag::EffectBag()
{
}


EffectBag::~EffectBag()
{
}
