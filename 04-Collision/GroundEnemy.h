
#pragma once
#include "Enemy.h"



class GroundEnemy : public Enemy
{
	int type;
public:
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	GroundEnemy(int x);
	~GroundEnemy();
	//virtual void SetState(int state);
};