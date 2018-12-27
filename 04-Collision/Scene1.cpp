﻿#include "Scene1.h"



void Scene1::KeyState(BYTE * states)

{
	if (simon->whip->isFinished == true)
	{

		if (simon->dagger->isFinished == true)
		{
			if (game->IsKeyDown(DIK_RIGHT))
			{ 
			//	if (simon->isJumping == false)
				{

					if (game->IsKeyDown(DIK_S))
						simon->SetState(SIMON_STATE_ATTACK);
					else

						if (game->IsKeyDown(DIK_D))
							simon->SetState(SIMON_STATE_THROW);
						else
							simon->SetState(SIMON_STATE_WALKING_RIGHT);
				}
				//else
				//	simon->SetState(SIMON_STATE_JUMP_RIGHT);
			}
			else
				if (game->IsKeyDown(DIK_LEFT))
				{
					//if (simon->isJumping == false)
					{
						if (game->IsKeyDown(DIK_S))
							simon->SetState(SIMON_STATE_ATTACK);
						else
							if (game->IsKeyDown(DIK_D))
								simon->SetState(SIMON_STATE_THROW);
							else
								
									simon->SetState(SIMON_STATE_WALKING_LEFT);
					}
					//else
					//	simon->SetState(SIMON_STATE_JUMP_LEFT);
				}
				else
					if (game->IsKeyDown(DIK_DOWN))
					{
						/*	if (game->IsKeyDown(DIK_S))
						simon->SetState(SIMON_STATE_ATTACK_SITTING);
						else*/
						simon->SetState(SIMON_STATE_SIT);
					}
			/*else
				if (game->IsKeyDown(DIK_SPACE))
				{
					if (simon->isJumping == false)
					{
						simon->SetState(SIMON_STATE_JUMP);
						simon->isJumping = true;
					}
				}*/
					else
					{
						simon->SetState(SIMON_STATE_IDLE);

					}
		}
		
	}

}

void Scene1::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_1:
		simon->dagger->turnOnDagger();
		simon->axe->turnOffAxe();
		simon->holy->turnOffHolyWater();
		simon->clock->turnOffClock();
		break;

	case DIK_SPACE:
		if (simon->isJumping == false)
		{
			simon->SetState(SIMON_STATE_JUMP);
			simon->isJumping = true;
		}

		break;
	case DIK_A: // reset
		simon->SetState(SIMON_STATE_IDLE);
		simon->SetPosition(700.0f, 0.0f);
		simon->SetSpeed(0, 0);
		break;
		//case DIK_DOWNARROW:
		//	simon->SetState(SIMON_STATE_SIT);
		//	break;
	case DIK_Q: // reset
		SceneManager::GetInstance()->replaceScene(new Scene2(simon));
		break;
	case DIK_S:
		if(simon->eatingItem==false)
		{
			if (simon->GetState() == SIMON_STATE_SIT)
			{
				simon->SetState(SIMON_STATE_ATTACK_SITTING);
				simon->whip->CreateWeapon(simon->x, simon->y + 7, simon->nx);

			}
			else
			{
				simon->SetState(SIMON_STATE_ATTACK);
				simon->whip->CreateWeapon(simon->x, simon->y, simon->nx);

			}
		}

		
			
		break;
	case DIK_D:
	//	if (simon->GetState() != SIMON_STATE_WALKING_LEFT && simon->GetState() != SIMON_STATE_WALKING_RIGHT)
		if (simon->eatingItem == false)
		
		{

			if (simon->dagger->isOn == true)
			{
				simon->numOfWeapon = 1;
				if (simon->heartCount > 0)
				{
					simon->heartCount -= 1;
					if (simon->dagger->GetState() == DAGGER_STATE_INACTIVE)
					{

						float x, y;
						simon->GetPosition(x, y);
						if (simon->GetState() == SIMON_STATE_SIT)
						{
							simon->dagger->CreateWeapon(x, y + 7, simon->nx);

							if (simon->isUsing1stWeapon == false)
							{
								if (simon->nx > 0)
									simon->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
								else
									simon->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
								simon->SetState(SIMON_STATE_THROW_SITTING);
								simon->useWeapon();

							}

						}
						else
						{


							simon->dagger->CreateWeapon(x, y, simon->nx);

							if (simon->isUsing1stWeapon == false)
							{
								if (simon->nx > 0)
									simon->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
								else
									simon->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
								simon->SetState(SIMON_STATE_THROW);
								simon->useWeapon();

							}

						}

					}
				}
			}

		}
		break;
	}
}

void Scene1::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{

	}

}

void Scene1::LoadResources()
{
	newGrid = new Grid();
	time = new Time();
	camera = Camera::GetInstance();
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;
	textures->Add(ID_TEX_MAP1, L"textures\\Map\\Map1.png", D3DCOLOR_XRGB(255, 0, 255));
	map = new Map(ID_TEX_MAP1, "textures\\Map\\Map1.csv");
	//Effect
	textures->Add(ID_TEX_EFFECT, L"textures\\Effect\\Kill.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_EFFECT1, L"textures\\Effect\\brickbreak.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_EFFECT2, L"textures\\Effect\\water.png", D3DCOLOR_XRGB(255, 0, 255));
	//board
	textures->Add(ID_TEX_BOARD, L"textures\\board.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_HEALTH, L"textures\\heal.png", D3DCOLOR_XRGB(255, 0, 255));

	//Objects
	textures->Add(ID_TEX_SIMON, L"textures\\simon.png", D3DCOLOR_XRGB(255, 0, 255)); 
	textures->Add(ID_TEX_TORCH, L"textures\\Enemy\\0.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_SIMON_DEATH, L"textures\\simondeath.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_SIMON2, L"textures\\simon2.png", D3DCOLOR_XRGB(0, 128, 128));

	textures->Add(ID_TEX_WHIP, L"textures\\Weapon\\morningstar.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_AXE, L"textures\\Weapon\\3.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_HOLYWATER, L"textures\\Weapon\\2.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	//Items
	textures->Add(ID_TEX_ITEM_BIGHEART, L"textures\\Item\\1.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_WHIP, L"textures\\Item\\3.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_SWORD, L"textures\\Item\\4.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_GOLD, L"textures\\Item\\2.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_POTION, L"textures\\Item\\potion.png", D3DCOLOR_XRGB(0, 0, 0));
	textures->Add(ID_TEX_ITEM_CLOCK, L"textures\\Item\\clock.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_HOLY, L"textures\\Item\\holywater.png", D3DCOLOR_XRGB(255, 0, 255));




	//Ground 0
	LPDIRECT3DTEXTURE9 texBoard = textures->Get(ID_TEX_BOARD);
	sprites->Add(65412, 0, 0, 510, 95, texBoard);
	ani = new CAnimation(1000);
	ani->Add(65412);
	animations->Add(547, ani);

#pragma region Co-ordinations of Effect

	LPDIRECT3DTEXTURE9 texEffect = textures->Get(ID_TEX_EFFECT);
	sprites->Add(01111, 0, 0, 20, 21, texEffect);
	sprites->Add(01112, 21, 0, 41, 21, texEffect);
	sprites->Add(01113, 42, 0, 62, 21, texEffect);

	LPDIRECT3DTEXTURE9 texEffectBrick = textures->Get(ID_TEX_EFFECT1);
	sprites->Add(02523, 0, 0, 103, 26, texEffectBrick);
	sprites->Add(02524, 0, 27, 103, 53, texEffectBrick);
	sprites->Add(02525, 0, 54, 103, 80, texEffectBrick);
	sprites->Add(02526, 0, 81, 103, 107, texEffectBrick);


	LPDIRECT3DTEXTURE9 texEffectWater = textures->Get(ID_TEX_EFFECT2);
	sprites->Add(02530, 0, 0, 102, 52, texEffectWater);
	sprites->Add(02531, 0, 54, 102, 106, texEffectWater);
	sprites->Add(02532, 104, 0, 207, 52, texEffectWater);
	sprites->Add(02533, 104, 54, 207, 106, texEffectWater);

	ani = new CAnimation(200);
	ani->Add(02530);
	ani->Add(02531);
	ani->Add(02532);
	ani->Add(02533);
	animations->Add(576, ani);
	ani = new CAnimation(200);
	ani->Add(02523);
	ani->Add(02524);
	ani->Add(02525);
	ani->Add(02526);
	animations->Add(577, ani);

	ani = new CAnimation(100);	// Effect fire
	ani->Add(01111);
	ani->Add(01112);
	ani->Add(01113);
	animations->Add(578, ani);

	effect = new EffectFire();
	effect->AddAnimation(578);
	

	LPDIRECT3DTEXTURE9 texEffectBag = textures->Get(ID_TEX_ITEM_POTION);
	sprites->Add(01114, 409, 46, 425, 53, texEffectBag);
	sprites->Add(01115, 409, 71, 425, 78, texEffectBag);
	sprites->Add(01116, 409, 95, 425, 102, texEffectBag);
	sprites->Add(01117, 409, 125, 431, 132, texEffectBag);
	

	ani = new CAnimation(100);	// Effect
	ani->Add(01114);
	animations->Add(579, ani);

	ani = new CAnimation(100);	// Effect
	ani->Add(01115);
	animations->Add(580, ani);

	ani = new CAnimation(100);	// Effect
	ani->Add(01116);
	animations->Add(581, ani);

	ani = new CAnimation(100);	// Effect
	ani->Add(01117);
	animations->Add(582, ani);

	effectBag = new EffectBag();
	effectBag->AddAnimation(579);
	effectBag->AddAnimation(580);
	effectBag->AddAnimation(581);
	effectBag->AddAnimation(582);
#pragma endregion

#pragma region Co-ordinations of Simon

	
		LPDIRECT3DTEXTURE9 texSimon2 = textures->Get(ID_TEX_SIMON2);
		//idle right when eating whip		
		sprites->Add(11001, 3, 2, 18, 32, texSimon2);
		sprites->Add(11002, 25, 2, 40, 32, texSimon2);
		sprites->Add(11003, 48, 2, 63, 32, texSimon2);
		//idle left when eating whip		
		sprites->Add(11004, 72, 38, 87, 68, texSimon2);
		sprites->Add(11005, 50, 38, 65, 68, texSimon2);
		sprites->Add(11006, 27, 38, 42, 68, texSimon2);
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_SIMON);
	//idle left
	sprites->Add(10011, 6, 1, 21, 31, texMario);
	
	//Walking left		
	sprites->Add(10003, 39, 1, 54, 31, texMario);
	sprites->Add(10004, 69, 1, 89, 31, texMario);
	sprites->Add(10005, 99, 1, 114, 31, texMario);

	//Sitting left
	sprites->Add(10007, 127, 1, 142, 31, texMario);

	//Attacking left
	sprites->Add(10101, 157, 1, 180, 31, texMario);
	sprites->Add(10102, 188, 1, 203, 31, texMario);
	sprites->Add(10103, 212, 1, 233, 31, texMario);

	//Sitting Attacking left
	sprites->Add(10201, 218, 34, 241, 64, texMario);
	sprites->Add(10202, 6, 67, 21, 97, texMario);
	sprites->Add(10203, 31, 67, 52, 97, texMario);

	// Right
	//idle right
	sprites->Add(10012, 220, 100, 235, 130, texMario);

	//Walking right		
	sprites->Add(10013, 187, 100, 202, 130, texMario);
	sprites->Add(10014, 157, 100, 172, 130, texMario);
	sprites->Add(10015, 127, 100, 142, 130, texMario);

	//Sitting right
	sprites->Add(10017, 99, 100, 114, 130, texMario);

	//Attacking right
	sprites->Add(10104, 60, 100, 84, 130, texMario);
	sprites->Add(10105, 38, 100, 53, 130, texMario);
	sprites->Add(10106, 8, 100, 29, 130, texMario);

	//Sitting Attacking right 
	sprites->Add(10204, 0, 133, 23, 163, texMario);
	sprites->Add(10205, 220, 166, 235, 196, texMario);
	sprites->Add(10206, 189, 166, 210, 196, texMario);

	//HURT LEFT

	sprites->Add(10300, 5, 34, 20, 64, texMario);
	//HURT RIGHT

	sprites->Add(10301, 221, 133, 236, 163, texMario);

	//STAIR LEFT UP
	sprites->Add(10350, 131, 34, 146, 64, texMario);
	sprites->Add(10351, 162, 34, 177, 64, texMario);

	//STAIR LEFT DOWN
	sprites->Add(10352, 66, 34, 81, 64, texMario);
	sprites->Add(10353, 96, 34, 111, 64, texMario);

	//STAIR RIGHT UP
	sprites->Add(10354, 95, 133, 110, 163, texMario);
	sprites->Add(10355, 64, 133, 79, 163, texMario);

	//STAIR RIGHT DOWN
	sprites->Add(10356, 160, 133, 175, 163, texMario);
	sprites->Add(10357, 130, 133, 145, 163, texMario);
	

	//Attack on stairs up right
	sprites->Add(10650, 58 , 166, 81, 196, texMario);
	sprites->Add(10651, 35, 166, 50, 196, texMario);
	sprites->Add(10652, 5, 166, 26, 196, texMario);
					
	//Attack on stairs up LEFT
	sprites->Add(10653, 160, 67, 183, 97, texMario);
	sprites->Add(10654, 191, 67, 206, 97, texMario);
	sprites->Add(10655, 215, 67, 236, 97, texMario);

	//Attack on stairs down right
	sprites->Add(10656, 152, 166, 175, 196, texMario);
	sprites->Add(10657, 130, 166, 145, 196, texMario);
	sprites->Add(10658, 100, 166, 120, 196, texMario);

	//Attack on stairs down left
	sprites->Add(10659, 66, 67, 89, 97, texMario);
	sprites->Add(10660, 96, 67, 111, 97, texMario);
	sprites->Add(10661, 121, 67, 141, 97, texMario);


	LPDIRECT3DTEXTURE9 texMarioDeath = textures->Get(ID_TEX_SIMON_DEATH);
	// death
		sprites->Add(78888, 0, 0, 31, 30, texMarioDeath);
	


#pragma endregion

#pragma region Co-ordinations of Ground

	/*LPDIRECT3DTEXTURE9 texGround = textures->Get(ID_TEX_GROUND);
	sprites->Add(20001, 0, 0, 16, 16, texGround);*/

#pragma endregion

#pragma region Co-ordinations of Torch

	LPDIRECT3DTEXTURE9 texTorch = textures->Get(ID_TEX_TORCH);
	sprites->Add(40001, 0, 0, 15, 31, texTorch);
	sprites->Add(40002, 16, 0, 31, 31, texTorch);

#pragma endregion

#pragma region Co-ordinations of Whip

	LPDIRECT3DTEXTURE9 texWhip = textures->Get(ID_TEX_WHIP);

	//VAMPIRE_KILLLER	
	//LEFT
	sprites->Add(30000, 13, 9, 18, 32, texWhip);
	sprites->Add(30001, 56, 9, 69, 27, texWhip);
	sprites->Add(30002, 91, 11, 116, 19, texWhip);



	//RIGHT
	sprites->Add(30003, 20, 9, 26, 32, texWhip);
	sprites->Add(30004, 35, 9, 49, 27, texWhip);
	sprites->Add(30005, 120, 11, 146, 19, texWhip);
	//NOTHING
	sprites->Add(30006, 0, 0, 1, 1, texWhip);

	//CHAIN WHIP
	//LEFT
	sprites->Add(30010, 13, 43, 18, 66, texWhip);
	sprites->Add(30011, 56, 43, 69, 61, texWhip);
	sprites->Add(30012, 91, 45, 116, 53, texWhip);

	//RIGHT
	sprites->Add(30013, 20, 43, 26, 66, texWhip);
	sprites->Add(30014, 35, 43, 49, 61, texWhip);
	sprites->Add(30015, 120, 45, 146, 53, texWhip);

	//MORNING_STAR
	//LEFT
	sprites->Add(30020, 13, 77, 18, 100, texWhip);
	sprites->Add(30021, 56, 77, 69, 95, texWhip);
	sprites->Add(30022, 75, 79, 116, 87, texWhip);

	//RIGHT
	sprites->Add(30023, 20, 77, 26, 100, texWhip);
	sprites->Add(30024, 35, 77, 49, 95, texWhip);
	sprites->Add(30025, 120, 79, 162, 87, texWhip);

#pragma endregion

#pragma region Co-ordinations of Dagger and Item Dagger

	LPDIRECT3DTEXTURE9 texItemSword = textures->Get(ID_TEX_ITEM_SWORD);
	sprites->Add(00002, 0, 0, 16, 8, texItemSword);//right


	sprites->Add(00003, 0, 9, 17, 18, texItemSword);//left

#pragma endregion	

#pragma region Co-ordinations of Axe

	LPDIRECT3DTEXTURE9 texAxe = textures->Get(ID_TEX_AXE);
	sprites->Add(54320, 0, 0, 14, 13, texAxe);//right
	sprites->Add(54321, 15, 0, 29, 13, texAxe);//side
	sprites->Add(54322, 30, 0, 44, 13, texAxe);//
	sprites->Add(54323, 45, 0, 59, 13, texAxe);//

#pragma endregion	

#pragma region Co-ordinations of HolyWater

	LPDIRECT3DTEXTURE9 texHolyWater = textures->Get(ID_TEX_HOLYWATER);
	
	sprites->Add(54400, 0, 0, 15, 12, texHolyWater);//left
	sprites->Add(54401, 16, 0, 31, 12, texHolyWater);//side
	sprites->Add(54402, 32, 0, 47, 12, texHolyWater);//

	
	sprites->Add(54410, 32, 13, 47, 25, texHolyWater);//right side



#pragma endregion	

#pragma region Co-ordinations of Item Big Heart

	LPDIRECT3DTEXTURE9 texItemBigHeart = textures->Get(ID_TEX_ITEM_BIGHEART);
	sprites->Add(00000, 0, 0, 12, 10, texItemBigHeart);

#pragma endregion

#pragma region Co-ordinations of Item Morning Star

	LPDIRECT3DTEXTURE9 texItemWhip = textures->Get(ID_TEX_ITEM_WHIP);
	sprites->Add(00001, 0, 0, 15, 15, texItemWhip);

#pragma endregion	

#pragma region Co-ordinations of Bag of Gold

	LPDIRECT3DTEXTURE9 texGoldBag = textures->Get(ID_TEX_ITEM_GOLD);
	sprites->Add(00004, 0, 0, 14, 14, texGoldBag); //red gold
	sprites->Add(00005, 15, 0, 29, 14, texGoldBag); // white gold
	sprites->Add(00006, 30, 0, 44, 14, texGoldBag); // blue gold

#pragma endregion

#pragma region Co-ordinations of Clock

	LPDIRECT3DTEXTURE9 texClock = textures->Get(ID_TEX_ITEM_CLOCK);
	sprites->Add(23541, 0, 0, 14, 15, texClock);

#pragma endregion

#pragma region Adding item Clcok

	ani = new CAnimation(100);
	ani->Add(23541);
	animations->Add(426, ani);


#pragma endregion
#pragma region Adding Animations for Simon

	ani = new CAnimation(100);	// idle right
	ani->Add(10012);
	animations->Add(400, ani);

	ani = new CAnimation(100);	// idle left
	ani->Add(10011);
	animations->Add(401, ani);

	ani = new CAnimation(100);	// Walking right
	ani->Add(10013);
	ani->Add(10014);
	ani->Add(10015);
	animations->Add(402, ani);

	ani = new CAnimation(100);	// Walking left
	ani->Add(10003);
	ani->Add(10004);
	ani->Add(10005);
	animations->Add(403, ani);

	ani = new CAnimation(100);	// Sitting right
	ani->Add(10017);
	animations->Add(500, ani);

	ani = new CAnimation(100);	// Sitting left
	ani->Add(10007);
	animations->Add(501, ani);


	ani = new CAnimation(500);	// Jumping right
	ani->Add(10017);
	animations->Add(600, ani);

	ani = new CAnimation(500);	// Jumping left
	ani->Add(10007);
	animations->Add(601, ani);

	ani = new CAnimation(100);	// Attacking right
	ani->Add(10104);
	ani->Add(10105);
	ani->Add(10106);
	ani->Add(10012);
	animations->Add(700, ani);

	ani = new CAnimation(100);	// Attacking left
	ani->Add(10101);
	ani->Add(10102);
	ani->Add(10103);
	ani->Add(10011);
	animations->Add(701, ani);
	ani = new CAnimation(100);	// Attack  up right
	ani->Add(10650);
	ani->Add(10651);
	ani->Add(10652);
	ani->Add(10354);
	animations->Add(702, ani);

	ani = new CAnimation(100);	// Attack  up left
	ani->Add(10653);
	ani->Add(10654);
	ani->Add(10655);
	ani->Add(10350);
	animations->Add(703, ani);

	ani = new CAnimation(100);	// Attack down right
	ani->Add(10656);
	ani->Add(10657);
	ani->Add(10658);
	ani->Add(10356);
	animations->Add(704, ani);

	ani = new CAnimation(100);	// Attack down left
	ani->Add(10659);
	ani->Add(10660);
	ani->Add(10661);
	ani->Add(10352);
	animations->Add(705, ani);

	ani = new CAnimation(100);	// Sitting Attacking right
	ani->Add(10204);
	ani->Add(10205);
	ani->Add(10206);
	ani->Add(10017);
	animations->Add(800, ani);

	ani = new CAnimation(100);	// Sitting Attacking left
	ani->Add(10201);
	ani->Add(10202);
	ani->Add(10203);
	ani->Add(10007);
	animations->Add(801, ani);

	ani = new CAnimation(300);	//  Hurt right
	ani->Add(10301);
	animations->Add(905, ani);

	ani = new CAnimation(300);	// Hurt left
	ani->Add(10300);
	animations->Add(906, ani);


	ani = new CAnimation(100);	//  up left 
	ani->Add(10350);
	ani->Add(10351);
	animations->Add(907, ani);
	
	ani = new CAnimation(100);	// Up right
	ani->Add(10354);
	ani->Add(10355);
	animations->Add(908, ani);

	ani = new CAnimation(100);	// down left 
	ani->Add(10352);
	ani->Add(10353);
	animations->Add(909, ani);

	ani = new CAnimation(100);	// down right
	ani->Add(10356);
	ani->Add(10357);
	animations->Add(910, ani);

	ani = new CAnimation(300);	// AFK up left 
	ani->Add(10350);
	animations->Add(001, ani);

	ani = new CAnimation(300);	// AFK Up right
	ani->Add( 10354);
	animations->Add(002, ani);

	ani = new CAnimation(300);	// AFK down left 
	ani->Add( 10352);
	animations->Add(003, ani);

	ani = new CAnimation(300);	// AFK down right
	ani->Add(10356);
	animations->Add(004, ani);

	ani = new CAnimation(100);//death
	ani->Add(78888);
	animations->Add(706, ani);
	ani = new CAnimation(300);	// Eating whip left
	ani->Add(11001);
	ani->Add(11002);
	ani->Add(11003);
	ani->Add(10011);
	animations->Add(152, ani);

	ani = new CAnimation(300);	// Eatign whip right
	ani->Add(11004);
	ani->Add(11005);
	ani->Add(11006);
	ani->Add(10012);
	animations->Add(153, ani);
		
		
		
		
		

		
		
		
		


#pragma region Adding Animation for Whip //de trong simon vì bên duoi co new simon
	// lvl1
	ani = new CAnimation(100); //Left
	ani->Add(30000);
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30006);
	animations->Add(710, ani);

	ani = new CAnimation(100); //Right
	ani->Add(30003);
	ani->Add(30004);
	ani->Add(30005);
	ani->Add(30006);
	animations->Add(711, ani);


	//lvl2
	ani = new CAnimation(100); //Left
	ani->Add(30010);
	ani->Add(30011);
	ani->Add(30012);
	ani->Add(30006);
	animations->Add(712, ani);

	ani = new CAnimation(100); //Right
	ani->Add(30013);
	ani->Add(30014);
	ani->Add(30015);
	ani->Add(30006);
	animations->Add(713, ani);
	//lvl3
	ani = new CAnimation(100); //Left
	ani->Add(30020);
	ani->Add(30021);
	ani->Add(30022);
	ani->Add(30006);
	animations->Add(714, ani);

	ani = new CAnimation(100); //Right
	ani->Add(30023);
	ani->Add(30024);
	ani->Add(30025);
	ani->Add(30006);
	animations->Add(715, ani);

#pragma endregion	

	simon = new Simon();
	simon->score = 0;
	simon->healthCount =16;
	simon->heartCount = 999999;
	simon->playerLife = 3;
	simon->stage = 01;
	simon->AddAnimation(400);		// idle right
	simon->AddAnimation(401);		// idle left

	simon->AddAnimation(402);		// walking right
	simon->AddAnimation(403);		// walking left 

	simon->AddAnimation(500);		// sitting right
	simon->AddAnimation(501);		// sitting left

	simon->AddAnimation(600);		// jumping right
	simon->AddAnimation(601);		// jumping left

	simon->AddAnimation(700);		// Attacking right
	simon->AddAnimation(701);		// Attacking left

	simon->AddAnimation(800);		// Sitting Attacking right
	simon->AddAnimation(801);		// Sitting Attacking  left

	simon->AddAnimation(700);		// Throw dagger right
	simon->AddAnimation(701);		// Throw dagger left 

	simon->AddAnimation(801);		// Sitting Throw dagger right
	simon->AddAnimation(800);		// Sitting Throw dagger left 

	simon->AddAnimation(905);		// HUrt right
	simon->AddAnimation(906);		// HUrt left

	simon->AddAnimation(908);		// Up right
	simon->AddAnimation(907);		// up left 
	simon->AddAnimation(910);		// down right
	simon->AddAnimation(909);		// down left 

	simon->AddAnimation(002);		// AFK Up right
	simon->AddAnimation(001);		// AFK up left 
	simon->AddAnimation(004);		// AFK down right
	simon->AddAnimation(003);		// AFK down left 

	simon->AddAnimation(702);		//ATK_OS_UP_RIGHT
	simon->AddAnimation(703);		//ATK_OS_UP_LEFT
	simon->AddAnimation(704);		//ATK_OS_DOWN_RIGHT
	simon->AddAnimation(705);		//ATK_OS_DOWN_LEFT

	simon->AddAnimation(706);//death

	simon->AddAnimation(153);		//Eating whip right
	simon->AddAnimation(152);		//Eating whip left

	simon->SetPosition(50.0f, 0);
	//objects.push_back(mario);
#pragma endregion 	

#pragma region Adding Ground


#pragma endregion

#pragma region Adding Torch

	ani = new CAnimation(100);
	ani->Add(40001);
	ani->Add(40002);
	animations->Add(901, ani);

	//for (int i = 0; i < 5; i++)
	//{
	//	torch = new Torch(0);
	//	torch->AddAnimation(901);

	//	
	//		torch->SetPosition(110 + i * 130, offsetMap + 144 - TORCH_BBOX_HEIGHT);
	//		if (i == 0 || i == 3)
	//			torch->setItemInside(bigheartInside);

	//		if (i == 1 || i == 2)
	//			torch->setItemInside(morningstarInside);

	//		if (i == 4)
	//			torch->setItemInside(daggerInside);


	//		newGrid->insertObjectIntoGrid(torch);
	//		//listEnemy.push_back(torch);
	//}


	
#pragma endregion

#pragma region Adding Item BigHeart

	ani = new CAnimation(100);
	ani->Add(00000);
	animations->Add(765, ani);

	//for (int i = 0; i < 2; i++)
	{
	bigheart = new BigHeart();
		bigheart->AddAnimation(765);
	}

#pragma endregion

#pragma region Adding Item Dagger

	ani = new CAnimation(100); //right
	ani->Add(00002);
	animations->Add(766, ani);

	ani = new CAnimation(100); //left
	ani->Add(00003);
	animations->Add(767, ani);

	//dag = new Dagger();
	//dag->AddAnimation(767);

	//dag->AddAnimation(766);

	

	simon->dagger->AddAnimation(767); //left
	simon->dagger->AddAnimation(766); //right
	
		simon->dagger1->AddAnimation(767);
		simon->dagger1->AddAnimation(766);
	dagger = new Dagger1();
	dagger->AddAnimation(767);

#pragma endregion


#pragma region Adding Axe

	ani = new CAnimation(100); //left side
	ani->Add(54320);
	ani->Add(54321);
	ani->Add(54322);
	ani->Add(54323);
	animations->Add(053, ani);

	ani = new CAnimation(100); //left side
	ani->Add(54323);
	ani->Add(54322);
	ani->Add(54321);
	ani->Add(54320);
	animations->Add(054, ani);

	ani = new CAnimation(100); //left side
	ani->Add(54320);
	animations->Add(055, ani);

	
	simon->axe->AddAnimation(054);
	simon->axe->AddAnimation(053);
	simon->axe1->AddAnimation(054);
	simon->axe1->AddAnimation(053);
#pragma endregion

#pragma region Adding HolyWater

	
	ani = new CAnimation(100); //left side
	ani->Add(54400);
	animations->Add(032, ani);
	ani = new CAnimation(100); //right side
	ani->Add(54410);
	animations->Add(033, ani);
	ani = new CAnimation(300); //burn
	ani->Add(54401);
	ani->Add(54402);
	ani->Add(54401);
	ani->Add(54402);
	animations->Add(034, ani);
	
	simon->holy->AddAnimation(032);
	simon->holy->AddAnimation(033);
	simon->holy->AddAnimation(034);
	simon->holy1->AddAnimation(032);
	simon->holy1->AddAnimation(033);
	simon->holy1->AddAnimation(034);

#pragma endregion 

#pragma region Adding Item Morning Star

	ani = new CAnimation(100);
	ani->Add(00001);
	animations->Add(777, ani);

	//for (int i = 0; i < 2; i++)
	//{
	morningstar = new MorningStar();
		morningstar->AddAnimation(777);
	//}

#pragma endregion

#pragma region Adding Item Bag of Gold

	ani = new CAnimation(100);
	ani->Add(00005);
	animations->Add(778, ani);

	ani = new CAnimation(100);
	ani->Add(00004);
	animations->Add(779, ani);

	ani = new CAnimation(100);
	ani->Add(00006);
	animations->Add(780, ani);


	ani = new CAnimation(100);
	ani->Add(00006);
	ani->Add(00004);
	ani->Add(00005);
	animations->Add(781, ani);
	

	goldbag = new GoldBag(3);
	goldbag->AddAnimation(778);
	goldbag->AddAnimation(779);
	goldbag->AddAnimation(780);
	goldbag->AddAnimation(781);
	
	newBoard = new Board();
	newBoard->SetPosition(0, 0);
	newBoard->typeOfWeaopon = 0;
#pragma endregion


	newGrid->readObjectFromTextFile("textures\\Objects1.txt");
}

void Scene1::Update(DWORD dt)
{
	if (time->x == 0)
		simon->healthCount = 0;
	time->Update(dt);
	newGrid->getListOfObjects(listColliableObjects, camera);
	listCheckBox.clear();
	listEnemy.clear();
	listSurface.clear();
	for (int i = 0; i < listColliableObjects.size(); i++)
	{
		if (listColliableObjects.at(i)->tag == eTag::TORCHES)
		{
			Torch *tor = dynamic_cast<Torch *>(listColliableObjects.at(i));
			listEnemy.push_back(tor);
		}
		else
			if (listColliableObjects.at(i)->tag == eTag::CHECK_BOX)
			{
				listCheckBox.push_back(listColliableObjects.at(i));
			}
			else
				if (listColliableObjects.at(i)->tag == eTag::GROUND)
				{
					listSurface.push_back(listColliableObjects.at(i));
				}
	}

	if (simon->shotTwoWeaponOneTime == true)
	{
		newBoard->simonHasNumbah = true;
	}
	newBoard->heartCount = simon->heartCount;
	newBoard->healthCount = simon->healthCount;
	newBoard->playerLife = simon->playerLife;
	newBoard->stage = simon->stage;
	newBoard->score = simon->score;
	newBoard->bossHealth = 16;
	newBoard->time = time->x;

		float x1, y1;
	x1 = Camera::GetInstance()->GetPosition().x;
	y1 = Camera::GetInstance()->GetPosition().y;
	if (simon->dagger->isOn == true)
	{
		if (simon->isUsing1stWeapon == true)
		{

		if ((simon->dagger->x) < x1|| (simon->dagger->x) > (x1 + SCREEN_WIDTH))// set lai dagger is not being used neu bay qua man hinh
		{

			simon->notUseWeapon();
			simon->dagger->SetState(DAGGER_STATE_INACTIVE);

		}

		}
	}

	CollisionBetWeaponAndEnemy();
	for (int i = 0; i < listItem.size(); i++)
	{
		//if (listItem.at(i)->GetState() == ITEM_STATE_ACTIVE);
		listItem.at(i)->Update(dt, &listSurface);
	}

	for (int i = 0; i < listEffectFire.size(); i++)
	{
		//if (listItem.at(i)->GetState() == ITEM_STATE_ACTIVE);
		listEffectFire.at(i)->Update(dt, &listSurface);
	}

	for (int i = 0; i < listEffectBag.size(); i++)//render ietms
		listEffectBag[i]->Update(dt);
	spawnItemsAfterEffect();
	
	if (goldbag->GetState() == ITEM_STATE_ACTIVE)
		goldbag->Update(dt, &listSurface);

	simon->Update(dt, &listSurface);
	
	if ((simon->dagger->GetState() != DAGGER_STATE_INACTIVE) && simon->dagger->isOn == true && simon->isUsing1stWeapon == true)//updating dagger when being used
		simon->dagger->Update(dt, &listSurface);
	if (simon->dagger->GetState() == DAGGER_STATE_INACTIVE)
		simon->dagger->isFinished = true;
	camera->SetPosition(simon->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon
	camera->Update();
	CollisionBetSimonAndCheckBox();
	CollisionBetSimonAndItem();
	erasingObjThatInacitve();
	if (proceedToLvl2 == true)
	{
		if (simon->x > 703)
			SceneManager::GetInstance()->replaceScene(new Scene2(simon));
	}

}

void Scene1::Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		newBoard->Render();
	//	DrawTextA(NULL, message.c_str(),-1,	&rect, DT_LEFT | DT_NOCLIP,);
		map->drawTileMap(camera, ID_TEX_MAP1);
		//All items are rendered if state = active
		for (int i = 0; i < listSurface.size(); i++)//render surface
		listSurface[i]->Render();

		for (int i = 0; i < listEnemy.size(); i++)//render torches
			listEnemy[i]->Render();

		for (int i = 0; i < listItem.size(); i++)//render ietms
			listItem[i]->Render();
		for (int i = 0; i < listEffectFire.size(); i++)//render ietms
			listEffectFire[i]->Render();
		goldbag->Render();
		//

	for (int i = 0; i < listEffectBag.size(); i++)//render ietms
		listEffectBag[i]->Render();
	simon->Render();
	simon->dagger->Render();
		simon->whip->Render();
		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}



void Scene1::CollisionBetSimonAndEnemy()
{

}

int Scene1::CollisionBetSimonAndUpStairs(vector <Stairs *>x)
{

	return true;
}
int Scene1::CollisionBetSimonAndDownStairs(vector <Stairs *>x)
{

	return true;
}

Scene1::Scene1()
{
	proceedToLvl2 = false;
	LoadResources();
}


Scene1::~Scene1()
{

}

void Scene1::spawnItemsAfterEffect()
{
	for (UINT i = 0; i < listEffectFire.size(); i++)
	{

		if (listEffectFire.at(i)->state == EFFECT_STATE_INACTIVE)
		{
			float x, y;
			listEffectFire.at(i)->GetPosition(x, y);

			switch (listEffectFire.at(i)->itemInside)
			{
			case 0:
				break;
			case bigheartInside:
				bigheart->SetState(ITEM_STATE_ACTIVE);
				bigheart->SetPosition(x, y);
				listItem.push_back(bigheart);
				break;
			case morningstarInside:
				morningstar->SetState(ITEM_STATE_ACTIVE);
				morningstar->SetPosition(x, y);
				listItem.push_back(morningstar);
		
				break;
			case daggerInside:
				dagger->SetState(ITEM_STATE_ACTIVE);
				dagger->SetPosition(x, y);
				listItem.push_back(dagger);
				break;
			case smallheartInside:
				break;
			default:
				break;
			}


			listEffectFire.erase(listEffectFire.begin() + i);// Delete it from enemy since Simion killed it

			i = i - 1; // Push back 1 cuz after deleting i+1 will replace i

		}


	}
}

void Scene1::erasingObjThatInacitve()
{
	for (UINT i = 0; i < listItem.size(); i++)
	{
		if (listItem.at(i)->state == ITEM_STATE_INACTIVE)
		{
			listItem.erase(listItem.begin() + i);
			i = i - 1;
		}
	}
}
void Scene1::CollisionBetWeaponAndEnemy()
{


	if (simon->whip->isFinished == false && simon->whip->isAllowedToCollide == true)
	{
		for (UINT i = 0; i < listEnemy.size(); i++)
		{

			if (simon->whip->CheckCollision(listEnemy.at(i)) == true)
			{
				if (listEnemy.at(i)->state == TORCH_STATE_ACTIVE)
				{
					float x, y;
					OutputDebugString(L"Collision Whip and Candle \n");
					listEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
					listEnemy.at(i)->GetPosition(x, y);

					effect->SetPosition(x, y);
					effect->SetState(EFFECT_STATE_ACTIVE);
					effect->type = 0;
					effect->itemInside = listEnemy.at(i)->itemInside;
					listEffectFire.push_back(effect);

					listEnemy.erase(listEnemy.begin() + i);// Delete it from enemy since Simion killed it

					i = i - 1; // Push back 1 cuz after deleting i+1 will replace i

				}

			}
		}
	}
	else 
		if (simon->dagger->state != DAGGER_STATE_INACTIVE && simon->dagger->isOn == true && simon->isUsing1stWeapon == true)
		{
			for (UINT i = 0; i < listEnemy.size(); i++)
			{

				if (simon->dagger->CheckCollision(listEnemy.at(i)) == true)
				{
					if (listEnemy.at(i)->state == TORCH_STATE_ACTIVE)
					{
						float x, y;
						OutputDebugString(L"Collision Dagger and Candle \n");
						listEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
						listEnemy.at(i)->GetPosition(x, y);
						simon->dagger->SetState(DAGGER_STATE_INACTIVE);
						simon->notUseWeapon();

						effect->SetPosition(x, y);
						effect->SetState(EFFECT_STATE_ACTIVE);
						effect->itemInside = listEnemy.at(i)->itemInside;
						listEffectFire.push_back(effect);

						listEnemy.erase(listEnemy.begin() + i);// Delete it from enemy since Simion killed it

						i = i - 1; // Push back 1 cuz after deleting i+1 will replace i
					}

				}
			}
		}
}




void Scene1::CollisionBetSimonAndItem()
{
	for (UINT i = 0; i < listItem.size(); i++)
	{
		if (simon->CheckCollision(listItem.at(i)) == true)
		{
			if (dynamic_cast<BigHeart *>(listItem.at(i)))
			{
				if (listItem.at(i)->state == ITEM_STATE_DROPPED)
				{

					OutputDebugString(L"Simon and BigHeart \n");
					listItem.at(i)->SetState(ITEM_STATE_INACTIVE);
					simon->heartCount += 5;
					listItem.erase(listItem.begin() + i);
					i = i - 1;
				}
				
			}
			else
				if (dynamic_cast<MorningStar *>(listItem.at(i)))
				{
					if (listItem.at(i)->state == ITEM_STATE_DROPPED)
					{
						OutputDebugString(L"Simon and WHIP \n");
						listItem.at(i)->SetState(ITEM_STATE_INACTIVE);
						if (simon->nx == 1)
							simon->SetState(SIMON_STATE_EAT_RIGHT);
						else
							simon->SetState(SIMON_STATE_EAT_LEFT);
						simon->whip->levelUpWhip();
						listItem.erase(listItem.begin() + i);
						i = i - 1;
					}
					
				}
				else
					if (dynamic_cast<Dagger1 *>(listItem.at(i)))
					{
						if (listItem.at(i)->state == ITEM_STATE_DROPPED)
						{
							OutputDebugString(L"Simon and DAGGER \n");
							listItem.at(i)->SetState(ITEM_STATE_INACTIVE);
							simon->dagger->turnOnDagger();
							OutputDebugString(L"Dagger on \n");
							listItem.erase(listItem.begin() + i);
							newBoard->typeOfWeaopon = 1;
							i = i - 1;
						}
						
					}
					else
						if (dynamic_cast<Ground *>(listItem.at(i)))
						{
							if (listItem.at(i)->state == INVIS_STATE_NEXT_LVL)
							{
								simon->SetState(SIMON_STATE_WALKING_RIGHT);
								proceedToLvl2 = true;
								OutputDebugString(L"Proceed to lvl 2 \n");
								
							/*	delete simon;
								for (int i=0;i<2;i++)
								delete bigheart[i];
								delete dagger;
								delete ground;
								delete invisBox;
								delete invisBox2;
								delete camera;
								delete map;
								delete goldbag;
								for (int i = 0; i<2; i++)
								delete morningstar[i];*/

							}
							else
								if (listItem.at(i)->state == INVIS_STATE_INVIS_ITEM)
								{
									OutputDebugString(L"Invis item appear \n");
									listItem.at(i)->SetState(INVIS_STATE_INACTIVE);
									goldbag->SetPosition(660, 125 + offsetMap);
									goldbag->SetState(ITEM_STATE_ACTIVE);
									listItem.push_back(goldbag);
								}
						}
						else
							if (dynamic_cast<GoldBag *>(listItem.at(i)))
							{
								if (listItem.at(i)->state == ITEM_STATE_DROPPED)
								{
									OutputDebugString(L"GoldBag \n");
									listItem.at(i)->SetState(ITEM_STATE_INACTIVE);
									GoldBag *newGoldBag = dynamic_cast<GoldBag *>(listItem.at(i));
									float x, y;
									newGoldBag->GetPosition(x, y);
									effectBag->SetPosition(x+5, y);
									effectBag->type = newGoldBag->type;
									effectBag->SetState(EFFECT_STATE_ACTIVE);
									if (newGoldBag->type == 0)
									{
										simon->score += 700;
									}
									else
										if (newGoldBag->type == 1)
										{
											simon->score += 100;
										}
										else
											if (newGoldBag->type == 2)
											{
												simon->score += 400;
											}
											else
												if (newGoldBag->type == 3)
												{
													simon->score += 1000;
												}
									listEffectBag.push_back(effectBag);
									listItem.erase(listItem.begin() + i);
									i = i - 1;
								}
								
							}
			
		}
	}
}

void Scene1::CollisionBetSimonAndCheckBox()
{
	for (UINT i = 0; i < listCheckBox.size(); i++)
	{
		if (simon->CheckCollision(listCheckBox.at(i)) == true)
		{
						if (dynamic_cast<Ground *>(listCheckBox.at(i)))
						{
							if (listCheckBox.at(i)->state == INVIS_STATE_NEXT_LVL)
							{
								simon->SetState(SIMON_STATE_WALKING_RIGHT);
								proceedToLvl2 = true;
								OutputDebugString(L"Proceed to lvl 2 \n");
							}
							else
								if (listCheckBox.at(i)->state == INVIS_STATE_INVIS_ITEM)
								{
									OutputDebugString(L"Invis item appear \n");
									listCheckBox.at(i)->SetState(INVIS_STATE_INACTIVE);
									goldbag->SetPosition(660, 125 + offsetMap);
									goldbag->SetState(ITEM_STATE_ACTIVE);
									goldbag->type = 3;
									listItem.push_back(goldbag);
								}
						}
		

		}
	}
}



