#pragma once
#include "Enemy.h"
class FireBall :public Enemy
{
public:
	FireBall();
	~FireBall();

	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects = NULL);
	virtual void Render();
	virtual void SetState(int state);
};

