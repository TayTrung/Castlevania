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

	bool eatingItem;
	DWORD eatingItemEffect_start;


	bool isInvis;
	DWORD invisTimeStart_start;

	Dagger *dagger;
	Clock *clock;
	Dagger *dagger1;
	Clock *clock1;
	Axe *axe;
	Axe *axe1;
	HolyWater *holy1;
	HolyWater *holy;
	int heartCount;
	int score;
	int healthCount;
	bool isUsing1stWeapon;
	bool isUsing2ndWeapon;
	int ani;
	bool shotTwoWeaponOneTime;
	bool isOnStairs; 
	bool directionOnStairs; // true=going up, false=going down
	bool proceedThruDoor;
	int numOfWeapon;
public:
	Simon() : CGameObject()
	{
		shotTwoWeaponOneTime = false;
		isUsing1stWeapon = false;
		isUsing2ndWeapon = false;
		eatingItem = false;
		isInvis = false;
		untouchable = false;
		whip = new Whip();
		axe = new Axe();
		dagger = new Dagger();
		clock = new Clock();
		holy = new HolyWater();
		axe1 = new Axe();
		dagger1 = new Dagger();
		clock1 = new Clock();
		holy1 = new HolyWater();
		//	heartCount = 10;
		isJumping = false;
		isOnStairs = false;
		proceedThruDoor = false;

	}
	bool isJumping;
	void useWeapon();
	void notUseWeapon();
	void useWeapon2();
	void notUseWeapon2();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);

	void StartUntouchable() {
		untouchable = true; 
		untouchable_start = GetTickCount();
		this->healthCount -= 2;
	}
	void StartEatingItemStart() {
		eatingItem = true;
		eatingItemEffect_start = GetTickCount();
	}

	void StartInvisTime() {
		isInvis = true;
		invisTimeStart_start = GetTickCount();
	}
	//void PickedSword();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};