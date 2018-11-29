#pragma once
#include "Game.h"
#include "Camera.h"
#include "GameObject.h"
#include "Textures.h"
#include "Whip.h"
#include "Simon.h"
#include "Torch.h"
#include "Map.h"
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
class Scene
{
public:
	virtual void KeyState(BYTE *states)=0;
	virtual void OnKeyDown(int KeyCode)=0;
	virtual void OnKeyUp(int KeyCode)=0;

	virtual void LoadResources()=0;
	virtual void Update(DWORD dt)=0;
	virtual void Render()=0;

	virtual void CollisionBetWeaponAndEnemy()=0;
	virtual void CollisionBetSimonAndItem()=0;
	virtual void CollisionBetSimonAndEnemy()=0;
	Scene();
	~Scene();
};

