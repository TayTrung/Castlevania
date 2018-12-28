#pragma once

#include "Enemy.h"

class Bat : public Enemy
{
private:
	int x1;
public:
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);

	Bat(int x1);
	~Bat();
};




