#include "Sprites.h"
#include "Game.h"
#include "debug.h"

CSprite::CSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->texture = tex;
}

CSprites * CSprites::__instance = NULL;

CSprites *CSprites::GetInstance()
{
	if (__instance == NULL) __instance = new CSprites();
	return __instance;
}

void CSprite::Draw(float x, float y, int alpha)
{
	CGame * game = CGame::GetInstance();

	
	D3DXVECTOR2 pos = Camera::GetInstance()->Transform(x, y);
	game->Draw(pos.x, pos.y, texture, left, top, right, bottom, alpha);
}

void CSprite::DrawWithoutTrans(float x, float y, int alpha)
{
	CGame * game = CGame::GetInstance();
	game->Draw(x, y, texture, left, top, right, bottom, alpha);

}

void CSprites::Add(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 tex)
{
	LPSPRITE s = new CSprite(id, left, top, right, bottom, tex);
	sprites[id] = s;
}

LPSPRITE CSprites::Get(int id)
{
	return sprites[id];
}



void CAnimation::Add(int spriteId, DWORD time)
{
	int t = time;
	if (time == 0) t=this->defaultTime;

	LPSPRITE sprite = CSprites::GetInstance()->Get(spriteId);
	LPANIMATION_FRAME frame = new CAnimationFrame(sprite, t);
	frames.push_back(frame);
}

void CAnimation::Render(float x, float y, int alpha)
{
	DWORD now = GetTickCount();
	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		if (now - lastFrameTime > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size()) currentFrame = 0;
		}
	}


	if (frames[currentFrame]->GetSprite()->getID() == 10104 || frames[currentFrame]->GetSprite()->getID() == 10656 ||
		frames[currentFrame]->GetSprite()->getID() == 10650 )//first frame Attacking right
		frames[currentFrame]->GetSprite()->Draw(x - 9, y, alpha);
	else if (frames[currentFrame]->GetSprite()->getID() == 10103 || frames[currentFrame]->GetSprite()->getID() == 10661 ||
		frames[currentFrame]->GetSprite()->getID() == 10655)//last frame Attacking left
		frames[currentFrame]->GetSprite()->Draw(x - 6, y, alpha);
	else if (frames[currentFrame]->GetSprite()->getID() == 10204)//first fr Sitting Attck right
		frames[currentFrame]->GetSprite()->Draw(x-8 , y, alpha);
	else if (frames[currentFrame]->GetSprite()->getID() == 10203)//last fr Sitting attck left
		frames[currentFrame]->GetSprite()->Draw(x - 6, y, alpha);
	else if (frames[currentFrame]->GetSprite()->getID() == 30003 || frames[currentFrame]->GetSprite()->getID() == 30013 || frames[currentFrame]->GetSprite()->getID() == 30023)
		frames[currentFrame]->GetSprite()->Draw(x - 15, y + 8, alpha);//1st fr Whip right
	else if (frames[currentFrame]->GetSprite()->getID() == 30004 || frames[currentFrame]->GetSprite()->getID() == 30014 || frames[currentFrame]->GetSprite()->getID() == 30024)
		frames[currentFrame]->GetSprite()->Draw(x - 14, y + 5, alpha); // 2nd fr Whip right
	else if (frames[currentFrame]->GetSprite()->getID() == 30005 || frames[currentFrame]->GetSprite()->getID() == 30015 || frames[currentFrame]->GetSprite()->getID() == 30025)
		frames[currentFrame]->GetSprite()->Draw(x + 18, y + 7, alpha);// 3nd fr Whip right
	else if (frames[currentFrame]->GetSprite()->getID() == 30000 || frames[currentFrame]->GetSprite()->getID() == 30010 || frames[currentFrame]->GetSprite()->getID() == 30020)
		frames[currentFrame]->GetSprite()->Draw(x + 23, y + 7, alpha);//1st fr Whip left
	else if (frames[currentFrame]->GetSprite()->getID() == 30001 || frames[currentFrame]->GetSprite()->getID() == 30011 || frames[currentFrame]->GetSprite()->getID() == 30021)
		frames[currentFrame]->GetSprite()->Draw(x + 16, y + 5, alpha);//2nd fr Whip left
	else if (frames[currentFrame]->GetSprite()->getID() == 30002 || frames[currentFrame]->GetSprite()->getID() == 30012)
		frames[currentFrame]->GetSprite()->Draw(x - 26, y + 7, alpha);//3rd fr Whip left
	else if (frames[currentFrame]->GetSprite()->getID() == 30022)
		frames[currentFrame]->GetSprite()->Draw(x - 44, y + 8, alpha); //Special Offset for 3rd whip 3rd frame left
	else
		frames[currentFrame]->GetSprite()->Draw(x, y, alpha);



}

int CAnimation::GetCurrentFrame()
{
	return currentFrame;
}

void CAnimation::SetCurrentFrame(int x)
{
	currentFrame = x;
	lastFrameTime = GetTickCount();
}


CAnimations * CAnimations::__instance = NULL;

CAnimations * CAnimations::GetInstance()
{
	if (__instance == NULL) __instance = new CAnimations();
	return __instance;
}

void CAnimations::Add(int id, LPANIMATION ani)
{
	//if (id == 476)
	//{
	//	int xsadasd = 0;
	//}
	animations[id] = ani;
}

LPANIMATION CAnimations::Get(int id)
{
	return animations[id];
}


