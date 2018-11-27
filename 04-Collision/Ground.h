#pragma once
#include "GameObject.h"


class Ground : public CGameObject
{
	int type; //0 = invis Box, 11 = map 1, 21= map 2.1, 22 = map 2.2, 23 = map 2.3
public:
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	Ground(int x);
	~Ground();
};