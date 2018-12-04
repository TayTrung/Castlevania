#pragma once
#include "GameObject.h"

class Enemy;
typedef Enemy * LPENEMY;
class Enemy : public CGameObject
{

public:

	int itemInside;
	void setItemInside(int Item);
	void getItemInside(int Item);
	Enemy();
	~Enemy();
};

