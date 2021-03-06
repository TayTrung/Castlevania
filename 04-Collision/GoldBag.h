#pragma once


#include "Item.h"


class GoldBag : public Item
{
public:
	int type;// 0 = white 1 = red 2 = blue 3 = 3 colors combine
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);

	GoldBag(int xtype);
	~GoldBag();
};




