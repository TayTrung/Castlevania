#pragma once
#include "GameObject.h"
#include "Whip.h"
#include "Dagger.h"


class Simon : public CGameObject
{
public:
	bool untouchable;
	//bool isHavingSword;
	Whip *whip;
	DWORD untouchable_start;
	Dagger *dagger;
	//int heartCount;
	bool isUsingDagger;
	int ani;

public: 
	Simon() : CGameObject()
	{
		
		isUsingDagger = false;
		//isHavingSword = false;
		untouchable = false;
		whip = new Whip();
		dagger = new Dagger();
	//	heartCount = 10;
		isJumping = false;
	}
	void useDagger();
	bool isJumping;
	void notUseDagger();
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void Render();
	void SetState(int state);
	void StartUntouchable() { untouchable = true; untouchable_start = GetTickCount(); }
	//void PickedSword();
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
};