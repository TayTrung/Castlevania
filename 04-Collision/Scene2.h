#pragma once
#include "Scene.h"
#include "SceneManager.h"

class Scene2 : public Scene
{
private:
	CGame *game1 = CGame::GetInstance();
	Ground *ground1;
	Simon *simon1;
	Board *board;
	vector<LPGAMEOBJECT> listItem1;
	vector<LPGAMEOBJECT> listSurface1;
	vector<LPGAMEOBJECT> listSurfaceUnderGround;
	vector<LPENEMY> listEnemy1;
	vector<LPENEMY> listTorches1;
	vector<LPSTAIRS> listUpStairs1;
	vector<LPSTAIRS> listDownStairs1;
	vector<LPEFFECTFIRE>listEffectFire1;
	vector<LPEFFECTBAG>listEffectBag1;
	Camera *camera1 = Camera::GetInstance();
	Map *map1;
	Bat *bat1;
	BigHeart *bigheart1;
	MorningStar *morningstar1;
	Dagger1 *dagger1;
	SmallHeart *smallheart1;
	Ghou *ghou;
	Panther *pant;
	Stairs *stairs;
	Chicken *chick;
	Door *door, *door1;
	GroundEnemy *groundEnemy, *groundEnemy1;
	GoldBag *goldbag1;
	Cross1 *cross1;
	HolyWater1 *holy1;
	Clock1 *clock1;
	Axe1 *axe1;
	EffectFire *effectFire1;
	EffectBag *effectBag1;
	Monster *monster1;
	FireBall *fire;
	Numbah *num;
	Potion *potion;
	int tickGhou = 300;
	int tickBat = 290;
	int tickMonster = 290; 
	bool spawnedEnoughGhou;
	bool spawnedEnoughMonster;
	bool x = true;
	bool y = false;
	bool floor1 = true;
	bool changedColor = true;


	DWORD TimeWait;

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

