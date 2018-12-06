#pragma once
#include "Weapon.h"
class Clock: public Weapon
{
public:
	bool isFinished;
	void turnOnClock();
	void turnOffClock();
	bool isOn; // true when eats Clock
	virtual void CreateWeapon(float x, float y, float nx);
	virtual void GetBoundingBox(float &l, float &t, float &r, float &b);

	virtual void Render();
	Clock();
	~Clock();
};

