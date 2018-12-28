#pragma once
#include "Weapon.h"

class Axe : public Weapon
{
public:
	Camera *camera;
	bool isOn; //true when eat a dagger 
	bool isFinished;
public:
	void turnOnAxe();

	void turnOffAxe();

	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	virtual void CreateWeapon(float x, float y, float nx);
	Axe();
	~Axe();
};

