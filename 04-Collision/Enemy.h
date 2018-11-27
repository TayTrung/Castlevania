#pragma once
#include "GameObject.h"

class Enemy : public CGameObject
{
	
public:
	void setItemInside(int Item);
	void getItemInside(int Item);
	Enemy();
	~Enemy();
};

