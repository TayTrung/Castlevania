#pragma once
#include "Scene.h"
#include "SceneManager.h"
#include "Scene2.h"

class Scene1 : public Scene
{
	
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

	virtual void CollisionBetSimonAndEnemy();
	virtual void spawnItemsAfterEffect();
	virtual int CollisionBetSimonAndUpStairs();
	virtual int CollisionBetSimonAndDownStairs();
	Scene1();
	~Scene1();
};

