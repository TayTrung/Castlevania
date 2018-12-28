#pragma once
#include "GameObject.h"

class EffectBag;
typedef EffectBag * LPEFFECTBAG;

class EffectBag : public CGameObject
{
public:
	int type;// 0 = red, 1= blue , 3= white,4= 3 color
	int itemInside;
	bool effectTime;
	DWORD effectTime_start;
	void StartEffect() { effectTime = true; effectTime_start = GetTickCount(); }
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);


	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	virtual void SetState(int state);
	EffectBag();
	~EffectBag();
};

