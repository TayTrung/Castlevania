#pragma once
#include "GameObject.h"

class Stairs;
typedef Stairs * LPSTAIRS;
class Stairs : public CGameObject
{
	float type;//1= right, 2 = left
	bool isDownStairs;
public:
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	int getType();
	Stairs(float xtype,bool x);
	~Stairs();
};