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
	CTextures * textures;
	CSprites * sprites;
	CAnimations		*animations;
	LPDIRECT3DTEXTURE9 texBoard;
	LPDIRECT3DTEXTURE9 texEffect;
	LPDIRECT3DTEXTURE9 texEffectBrick;
	LPDIRECT3DTEXTURE9 texEffectWater;
	LPDIRECT3DTEXTURE9 texEffectBag;
	LPDIRECT3DTEXTURE9 texSimon2;
	LPDIRECT3DTEXTURE9 texMario;
	LPDIRECT3DTEXTURE9 texMarioDeath;
	LPDIRECT3DTEXTURE9 texTorch;
	LPDIRECT3DTEXTURE9 texWhip;
	LPDIRECT3DTEXTURE9 texItemSword;
	LPDIRECT3DTEXTURE9 texAxe;
	LPDIRECT3DTEXTURE9 texHolyWater;
	LPDIRECT3DTEXTURE9 texItemBigHeart;
	LPDIRECT3DTEXTURE9 texItemWhip;
	LPDIRECT3DTEXTURE9 texGoldBag;
	LPDIRECT3DTEXTURE9 texClock;
	LPANIMATION ani;
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
	virtual void readTextureFromFileTxt(char * pathOfFile);
	virtual void readCoordiantionsForSpritesFromFileTxt(char * pathOfFile);
	virtual void createAnimationsFromFileTxt(char * pathOfFile);
	virtual int CollisionBetSimonAndUpStairs(vector <Stairs *>x);
	virtual int CollisionBetSimonAndDownStairs(vector <Stairs *>x);
	Scene1();
	~Scene1();
};

