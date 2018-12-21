#include "Board.h"
#include <string>



void Board::Update(DWORD dt, vector<LPGAMEOBJECT>* colliable_objects)
{
}

void Board::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = top = right = bottom = 0;
}

void Board::Render()
{
	//loadBoard
	CGame::GetInstance()->Draw(x, y, CTextures::GetInstance()->Get(ID_TEX_BOARD), 0, 0, 320, 49, 255);

	//Load Vu Khi
	if (this->typeOfWeaopon == 1)
	{
		CGame::GetInstance()->Draw(x + 170, y + 25, CTextures::GetInstance()->Get(ID_TEX_ITEM_SWORD), 0, 0, 17, 9, 255);
	}
	else
		if (this->typeOfWeaopon == 2)
		{
			CGame::GetInstance()->Draw(x + 170, y + 25, CTextures::GetInstance()->Get(ID_TEX_AXE), 0, 0, 14, 13, 255);

		}
		else
		if (this->typeOfWeaopon == 3)
			{
			CGame::GetInstance()->Draw(x + 170, y + 25, CTextures::GetInstance()->Get(ID_TEX_ITEM_HOLY), 0, 0, 15, 15, 255);

			}
			else
				if (this->typeOfWeaopon == 4)
				{
					CGame::GetInstance()->Draw(x + 170, y + 25, CTextures::GetInstance()->Get(ID_TEX_ITEM_CLOCK), 0, 0, 14, 15, 255);
				}
	//load NUmbah		
	if(this->simonHasNumbah==true)
		CGame::GetInstance()->Draw(x + 260, y + 25, CTextures::GetInstance()->Get(ID_TEX_ITEM_NUMBAH), 0, 0, 14, 14, 255);
	//health bar
	for (int i = 0; i < 16; i++)
	{
		CGame::GetInstance()->Draw(x + 60+i*6, y + 17, CTextures::GetInstance()->Get(ID_TEX_HEALTH), 5, 0, 11, 9, 255);
		CGame::GetInstance()->Draw(x + 60 + i * 6, y + 27, CTextures::GetInstance()->Get(ID_TEX_HEALTH), 5, 0, 11, 9, 255);
	}
	for (int i = 0; i < this->healthCount; i++)
	{
		CGame::GetInstance()->Draw(x + 61+i*6, y + 17, CTextures::GetInstance()->Get(ID_TEX_HEALTH), 0, 0, 5, 9, 255);
	}
	for (int i = 0; i < this->bossHealth; i++)
	{
		CGame::GetInstance()->Draw(x + 61 + i * 6, y + 27, CTextures::GetInstance()->Get(ID_TEX_HEALTH), 11, 0, 17, 9, 255);


	}
	//Load time
	SetRect(&fRect, 173, 1, 200, 20);
	string x = std::to_string(this->time);

	do
	{
		char d = '0';
		x = d + x;
	} while (x.length() < 3);
	mess = x;
	font->DrawTextA(NULL, mess.c_str(), -1, &fRect, DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

	//Load heartCount
	SetRect(&fRect, 230,15, 250, 30);
	mess = std::to_string(this->heartCount);
	font->DrawTextA(NULL, mess.c_str(), -1, &fRect, DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	//LifeCount
	SetRect(&fRect, 230, 30, 250, 50);
	mess = std::to_string(this->playerLife);
	font->DrawTextA(NULL, mess.c_str(), -1, &fRect, DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));
	//Stage COunt
	SetRect(&fRect, 285, 3, 305, 50);
	mess = std::to_string(this->stage);
	font->DrawTextA(NULL, mess.c_str(), -1, &fRect, DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

	//Load Score
	SetRect(&fRect, 60, 1, 100, 20);
	string y = std::to_string(this->score);

		do
		{
			char d = '0';
			y = d + y;
		} while (y.length()<6);
		mess = y;
	font->DrawTextA(NULL, mess.c_str(), -1, &fRect, DT_LEFT | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255));

}

Board::Board()
{
	simonHasNumbah = false;
	font = NULL;
	D3DXCreateFont(CGame::GetInstance()->GetDirect3DDevice(), 0, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS,
		ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, L"Arial", &font);


}


Board::~Board()
{
}
