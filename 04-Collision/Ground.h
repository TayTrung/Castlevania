#pragma once
#include "GameObject.h"
class Ground;

typedef Ground * LPGROUND;

class Ground : public CGameObject
{
	
public:
	int type; //0 = invis Box, 1 = map
	int Bbox_WIDTH;
	virtual void Render();
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	Ground(int xtype, int xbbox_WIDTH);
	~Ground();
};