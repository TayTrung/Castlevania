#pragma once
//#ifdefine _DXAUDIO_H
#define _DXAUDIO_H
#include "DSutil.h"

extern CSoundManager *dsound;

class Sound
{
public:
	int Init_DirectSound(HWND);
	CSound *LoadSound(char *);
	void PlaySound(CSound *);
	void LoopSound(CSound *);
	void StopSound(CSound *);
	Sound();
	~Sound();
};

