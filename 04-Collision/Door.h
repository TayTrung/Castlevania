#pragma once
#include "GameObject.h"


class Door : public CGameObject
{
	
public:

	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Render();
	Door();
	~Door();
};