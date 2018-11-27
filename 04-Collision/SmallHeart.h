#pragma once

#include "Item.h"


class SmallHeart : public Item
{
private:
	int x1;
public:
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);

	SmallHeart(int x1);
	~SmallHeart();
};




