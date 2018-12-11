#pragma once
#include "Scene.h"
#include "SceneManager.h"

class Scene2 : public Scene
{
private:
	int stage;
public:
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);
	bool isEatingCross;
	virtual void LoadResources();
	virtual void Update(DWORD dt);
	virtual void Render();
	int randomIteminside();
	void erasingObjThatInacitve();
	void spawnGhou(float x, float y,int state);
	void spawnBat(Simon *simon, Camera *camera);
	void freezeEnemyFunction();
	void XuLyPanthera();
	void spawnFireBall();
	void spawnMonster();
	virtual void CollisionBetWeaponAndEnemy();
	virtual void CollisionBetSimonAndItem();
	virtual void spawnItemsAfterEffect();
	virtual void CollisionBetSimonAndEnemy();
	virtual int CollisionBetSimonAndUpStairs();
	virtual int CollisionBetSimonAndDownStairs();
	Scene2(Simon *simon);
	~Scene2();
};

