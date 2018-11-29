#pragma once
#include "Enemy.h"
class Panther:public Enemy
{
	float X;
	float distanceToJump;
public:
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	virtual void SetPosition(float x, float y);
	Panther(float distance);
	~Panther();
};

