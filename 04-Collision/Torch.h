#pragma once
#include "Enemy.h"



class Torch : public Enemy
{
	int type;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
public: 	
	Torch(int type1);
	//virtual void SetState(int state);
};