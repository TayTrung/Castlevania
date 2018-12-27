#pragma once
#include "GameObject.h"

class Item : public CGameObject
{
public:
	DWORD dropTime_Start;
	bool dropped;

	DWORD TimeWaitToEat=0;
public:
	void StartCountTIme() { dropped = true, dropTime_Start = GetTickCount(); }
	Item();
	~Item();
};

