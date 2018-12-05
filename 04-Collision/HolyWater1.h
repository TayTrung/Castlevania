#pragma once
#pragma once
#include "Item.h"

class HolyWater1 : public Item
{
public:
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);


	HolyWater1();
	~HolyWater1();
};

