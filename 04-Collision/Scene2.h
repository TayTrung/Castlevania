#pragma once
#include "Scene.h"
#include "SceneManager.h"

class Scene2 : public Scene
{
public:
	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);

	virtual void LoadResources();
	virtual void Update(DWORD dt);
	virtual void Render();

	void erasingObjThatInacitve();
	void spawnGhou(float x, float y);
	virtual void CollisionBetWeaponAndEnemy();
	virtual void CollisionBetSimonAndItem();
	virtual void CollisionBetSimonAndEnemy();
	Scene2(Simon *simon);
	~Scene2();
};

