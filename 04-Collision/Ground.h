#pragma once
#include "GameObject.h"


class Ground : public CGameObject
{
	int type; //0 = invis Box, 1 = map
	int Bbox_WIDTH;
public:
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	Ground(int xtype, int xbbox_WIDTH);
	~Ground();
};