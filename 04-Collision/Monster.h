#pragma once
#include "Enemy.h"

class Monster : public Enemy
{
	float x1;



	DWORD TimeWait;
	bool isWaitting = true;

	int ani;
public:
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	Monster(float x11);
	~Monster();
};



