#pragma once
#include "Weapon.h"

class Dagger : public Weapon
{
public:
	bool isOn; //true when eat a dagger 
	bool isFinished;
public:
	void turnOnDagger();

	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	virtual void CreateWeapon(float x, float y, float nx);
	Dagger();
	~Dagger();
};

