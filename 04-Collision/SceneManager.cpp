#include "SceneManager.h"

SceneManager *SceneManager::__instance = NULL;

Scene *SceneManager::getCurrentScene()
{
	return currentScene;
}

void SceneManager::replaceScene(Scene * newScene)
{
	delete currentScene;
	currentScene = newScene;
}

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::KeyState(BYTE * states)
{
	currentScene->KeyState(states);
}

void SceneManager::OnKeyDown(int KeyCode)
{
	currentScene->OnKeyDown(KeyCode);
}

void SceneManager::OnKeyUp(int KeyCode)
{
	currentScene->OnKeyUp(KeyCode);
}

SceneManager * SceneManager::GetInstance()
{
	if (__instance == NULL) __instance = new SceneManager();
	return __instance;
}

void SceneManager::LoadResources()
{
	currentScene->LoadResources();
}

void SceneManager::Update(DWORD dt)
{
	currentScene->Update(dt);
}

void SceneManager::Render()
{
	currentScene->Render();
}
