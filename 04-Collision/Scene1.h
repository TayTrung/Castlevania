#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Scene2.h"

class Scene1 : public Scene
{
public:
	CGame *game = CGame::GetInstance();
	Ground *ground, *invisBox, *invisBox2;
	Camera *camera;
	Simon *simon; Map *map;
	vector<LPENEMY> listEnemy;
	vector<LPGAMEOBJECT> listItem;
	vector<LPGAMEOBJECT> listSurface;
	vector<LPEFFECTFIRE>listEffectFire;
	vector<LPEFFECTBAG>listEffectBag;
	vector<LPGAMEOBJECT>listColliableObjects;
	vector<LPGAMEOBJECT>listCheckBox;
	GoldBag *goldbag;
	Torch *torch;
	Board *newBoard;
		Grid *newGrid;
	Dagger1 *dagger;
	MorningStar	*morningstar;
	BigHeart *bigheart;
	EffectFire *effect;
	EffectBag *effectBag;
	Time *time;
public:
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	virtual void LoadResources();
	virtual void Update(DWORD dt);
	virtual void Render();
	bool proceedToLvl2;
	void erasingObjThatInacitve();
	virtual void CollisionBetWeaponAndEnemy();
	virtual void CollisionBetSimonAndItem();
	virtual void CollisionBetSimonAndCheckBox();
	virtual void CollisionBetSimonAndEnemy();
	virtual void spawnItemsAfterEffect();
	virtual int CollisionBetSimonAndUpStairs(vector <Stairs *>x);
	virtual int CollisionBetSimonAndDownStairs(vector <Stairs *>x);
	Scene1();
	~Scene1();
};

