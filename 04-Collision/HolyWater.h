#pragma once
#include "Weapon.h"

class HolyWater : public Weapon
{
public:
	bool isOn; //true when eat a dagger 
	bool isFinished;

	bool burning;
	DWORD burnTime_Start;
public:
	void turnOnHolyWater();

	void turnOffHolyWater();

	void StartBurn() { burning=true, burnTime_Start = GetTickCount(); }
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects);
	virtual void Render();
	virtual void SetState(int state);
	virtual void CreateWeapon(float x, float y, float nx);
	HolyWater();
	~HolyWater();
};

