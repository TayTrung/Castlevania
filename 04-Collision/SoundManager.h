#pragma once
#include "DSutil.h"
#include <unordered_map>
#include "Game.h"

enum eTagSound
{
	Stage1,
	Hit,
	HitCannon,
	CollItem,
	COllWeapon,
	UsingWhip,
	OpenDoor,
	Cross,
	HolWater,
	Bos,
	Ax,
	stopWatch
	
};

class SoundManager
{

	CSoundManager *dsound;
	static SoundManager * __instance;
	unordered_map<eTagSound, CSound*> listOfSounds;
public:
	void stopSound(eTagSound x);
	void playSound(eTagSound x,bool replay);
	void LoadSounds();
	void AddSound(eTagSound x, LPTSTR pathToSound);
	static SoundManager * GetInstance();
	SoundManager();
	~SoundManager();
};

