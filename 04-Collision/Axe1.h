#pragma once

#include "Item.h"


class Axe1 : public Item
{
public:
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);

	Axe1();
	~Axe1();
};




