#pragma once
#include "GameObject.h"
#include "Textures.h"
#include "Simon.h"
class Board : public CGameObject
{
public:

	ID3DXFont *font;
	RECT fRect;
	int heartCount;
	int healthCount;
	int score;
	int stage;
	int playerLife;
	int bossHealth;
	int time;
	std::string mess;
	int typeOfWeaopon;
	bool simonHasNumbah;
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT> *colliable_objects = NULL);
	virtual void GetBoundingBox(float &left, float &top, float &right, float &bottom);
	virtual void Render();
	Board();
	~Board();
};

