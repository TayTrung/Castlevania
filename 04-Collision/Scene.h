#pragma once
#include"Time.h"
#include "Game.h"
#include "Camera.h"
#include "GameObject.h"
#include "Textures.h"
#include "Whip.h"
#include "Simon.h"
#include "Torch.h"
#include "Map.h"
#include "SoundManager.h"
#include "Heal.h"
#include "BigHeart.h"
#include "Dagger1.h"
#include "MorningStar.h"
#include "Enemy.h"
#include "Ground.h"
#include "debug.h"
#include "GoldBag.h"
#include "define.h"
#include "SmallHeart.h"
#include "Ghou.h"
#include "Panther.h"
#include "Stairs.h"
#include "Bat.h"
#include "Chicken.h"
#include "GroundEnemy.h"
#include "Potion.h"
#include "Door.h"
#include"HolyWater1.h"
#include "Cross1.h"
#include "Clock1.h"
#include "Clock.h"
#include "Axe1.h"
#include "Axe.h"
#include "EffectFire.h"
#include "EffectBag.h"
#include "Monster.h"
#include "FireBall.h"
#include "Numbah.h"
#include "Board.h"
#include "Boss.h"
#include "Grid.h"
class Scene
{
public:
	virtual void KeyState(BYTE *states)=0;
	virtual void OnKeyDown(int KeyCode)=0;
	virtual void OnKeyUp(int KeyCode)=0;

	virtual void LoadResources()=0;
	virtual void Update(DWORD dt)=0;
	virtual void Render()=0;
	virtual void readTextureFromFileTxt(char * pathOfFile) = 0;
	virtual void readCoordiantionsForSpritesFromFileTxt(char * pathOfFile) = 0;
	virtual void createAnimationsFromFileTxt(char * pathOfFile) = 0;

	virtual void CollisionBetWeaponAndEnemy()=0;
	virtual void CollisionBetSimonAndItem()=0;
	virtual void CollisionBetSimonAndEnemy()=0; 
	virtual void CollisionBetSimonAndCheckBox()=0;

	virtual void spawnItemsAfterEffect()=0;
	virtual int CollisionBetSimonAndUpStairs(vector <Stairs *>x)=0;
	virtual int CollisionBetSimonAndDownStairs(vector<Stairs *>x)=0;
	Scene();
	~Scene();
};

