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
	AddSound(eTagSound::Hit, L"textures\\Sound\\sound\\hit.wav");
	AddSound(eTagSound::HitCannon, L"textures\\Sound\\sound\\hitcannon.wav");
	AddSound(eTagSound::CollItem, L"textures\\Sound\\sound\\collectitem.wav");
	AddSound(eTagSound::COllWeapon, L"textures\\Sound\\sound\\collectweapon.wav");
	AddSound(eTagSound::UsingWhip, L"textures\\Sound\\sound\\usingwhip.wav");
	AddSound(eTagSound::OpenDoor, L"textures\\Sound\\sound\\opendoor.wav");
	AddSound(eTagSound::Cross, L"textures\\Sound\\sound\\holycross.wav");
	AddSound(eTagSound::HolWater, L"textures\\Sound\\sound\\holywater.wav");
	AddSound(eTagSound::Bos, L"textures\\Sound\\music\\bos.wav");
	AddSound(eTagSound::Ax, L"textures\\Sound\\sound\\Axe.wav");
	AddSound(eTagSound::stopWatch, L"textures\\Sound\\sound\\stoptimer.wav");
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
