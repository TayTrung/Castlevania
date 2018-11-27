#pragma once
#include "Weapon.h"
#include "Torch.h"

class Whip: public Weapon
{
public:
	int type;

	int ani;
public:
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	bool isFinished;
	void levelUpWhip();
	bool isAllowedToCollide;
	virtual void CreateWeapon(float x, float y, float nx);
	Whip()
	{

		type = VAMPIRE_KILLER;
		this->AddAnimation(710);
		this->AddAnimation(711); 
		isFinished = true;
		isAllowedToCollide=false;

	};
};
