#pragma once
#include "GameObject.h"
#include "Whip.h"
#include "Dagger.h"
#include "Clock.h"
#include "Axe.h"
#include "HolyWater.h"

class Simon : public CGameObject
{
public:
	Whip *whip;
	bool untouchable;
	DWORD untouchable_start;
	Dagger *dagger;
	Clock *clock;
	Axe *axe;
	HolyWater *holy;
	int heartCount;
	int score;
	int healthCount;
	bool isUsingDagger;
	int ani;
	bool isOnStairs; 
	bool directionOnStairs; // true=going up, false=going down
	bool proceedThruDoor;
public:
	Simon() : CGameObject()
	{
		isUsingDagger = false;
		//isHavingSword = false;
		untouchable = false;
		whip = new Whip();
		axe = new Axe();
		dagger = new Dagger();
		clock = new Clock();
		holy = new HolyWater();
		//	heartCount = 10;
		isJumping = false;
		isOnStairs = false;
		proceedThruDoor = false;

	}
	void useDagger();
	bool isJumping;
	void notUseDagger();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);

	void StartUntouchable() {
		untouchable = true; 
		untouchable_start = GetTickCount();
		this->healthCount -= 2;
	}
	//void PickedSword();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};