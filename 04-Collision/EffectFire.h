#pragma once
#include "GameObject.h"

class EffectFire;
typedef EffectFire * LPEFFECTFIRE;

class EffectFire : public CGameObject
{
	
public:
	int type;// 0 = fire, 1= rock , 3= water
	int itemInside;
	bool isFinished;
	int ani;
	bool effectTime;
	DWORD effectTime_start;
	void StartEffect() { effectTime = true; effectTime_start = GetTickCount(); }
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);


	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	virtual void SetState(int state);
	EffectFire();
	~EffectFire();
};

