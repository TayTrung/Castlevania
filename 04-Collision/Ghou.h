#pragma once
#include "Enemy.h"
class Ghou : public Enemy
{
public:
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	Ghou();
	~Ghou();
};



