#pragma once
#include "Scene.h"
#include "Game.h"
class SceneManager
{
private:
	static SceneManager * __instance;
	Scene * currentScene;
public:
	Scene *getCurrentScene();
	void replaceScene(Scene *newScene);
	SceneManager();
	~SceneManager();

	virtual void KeyState(BYTE *states);
	virtual void OnKeyDown(int KeyCode);
	virtual void OnKeyUp(int KeyCode);

	static SceneManager * GetInstance();
	void LoadResources();
	void Update(DWORD dt);
	void Render();
};

