#pragma once
#include "GameObject.h"


class Ground : public CGameObject
{
	int type; //0 = basic ground, 1 = invis box
public:
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	Ground(int x);
	~Ground();
};