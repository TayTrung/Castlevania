#include "SoundManager.h"



void SoundManager::stopSound(eTagSound x)
{
	listOfSounds[x]->Stop();
}

void SoundManager::playSound(eTagSound x, bool replay)
{
	if (replay == true)
		listOfSounds[x]->Play(0, DSBPLAY_LOOPING);
	else
		listOfSounds[x]->Play();

}

void SoundManager::LoadSounds()
{
	AddSound(eTagSound::Stage1, L"textures\\Sound\\music\\Stage1.wav");
	//AddSound(Stage2)
}

void SoundManager::AddSound(eTagSound x, LPTSTR pathToSound)
{
	CSound *sound;
	dsound->Create(&sound, pathToSound);
	listOfSounds[x] = sound;
	
}

SoundManager * SoundManager::__instance = NULL;

	SoundManager *SoundManager::GetInstance()
	{
		if (__instance == NULL) __instance = new SoundManager();
		return __instance;
	}


SoundManager::SoundManager()
{
	dsound = new CSoundManager();
	dsound->Initialize(CGame::GetInstance()->getWindowHandler(), DSSCL_PRIORITY);
	LoadSounds();

}


SoundManager::~SoundManager()
{
}
