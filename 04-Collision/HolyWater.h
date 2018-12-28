#pragma once
#include "Weapon.h"
#include "SoundManager.h"
class HolyWater : public Weapon
{
public:
	bool isOn; //true when eat a dagger 
	bool isFinished;
	SoundManager *sound;
	bool burning;
	DWORD burnTime_Start;

	int ani;
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

