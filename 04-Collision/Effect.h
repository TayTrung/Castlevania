#pragma once
#include "GameObject.h"

class Effect;
typedef Effect * LPEFFECT;

class Effect : public CGameObject
{
public:
	int itemInside;
	bool effectTime;
	DWORD effectTime_start;
	void StartEffect() { effectTime = true; effectTime_start = GetTickCount(); }
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);


	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	virtual void SetState(int state);
	Effect();
	~Effect();
};

