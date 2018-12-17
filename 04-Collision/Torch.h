#pragma once
#include "Enemy.h"



class Torch : public Enemy
{
public:
	int type;
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	
	Torch(int type1);

	~Torch();
	//virtual void SetState(int state);
};