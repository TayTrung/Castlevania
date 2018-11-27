#pragma once
#include "GameObject.h"
class Weapon :public CGameObject
{
public:

	virtual void CreateWeapon(float x,float y, float nx)=0;
	Weapon();
	~Weapon();
};

