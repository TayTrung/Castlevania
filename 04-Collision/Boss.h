#pragma once
#include "Enemy.h"
#include "Simon.h"
class Boss : public Enemy
{
public:


	virtual void Update(DWORD dt,Simon x);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);

	Boss();
	~Boss();
};

