﻿#include "Scene2.h"
#include "Scene1.h"



CGame *game1 = CGame::GetInstance();
Ground *ground1;
Simon *simon1;
vector<LPGAMEOBJECT> listItem1;
vector<LPGAMEOBJECT> listSurface1;
vector<LPGAMEOBJECT> listEnemy1;
Camera *camera1 = Camera::GetInstance();
Map *map1;
BigHeart *bigheart1;
MorningStar *morningstar1;
Dagger1 *dagger1;
SmallHeart *smallheart1;
Ghou *ghou;
Panther *pant;


void Scene2::KeyState(BYTE * states)

{
	if (simon1->whip->isFinished == true)
	{


		if (game1->IsKeyDown(DIK_RIGHT))
		{
			if (game1->IsKeyDown(DIK_S))
				simon1->SetState(SIMON_STATE_ATTACK);
			else
				simon1->SetState(SIMON_STATE_WALKING_RIGHT);
		}
		else
			if (game1->IsKeyDown(DIK_LEFT))
			{
				if (game1->IsKeyDown(DIK_S))
					simon1->SetState(SIMON_STATE_ATTACK);
				else
					simon1->SetState(SIMON_STATE_WALKING_LEFT);
			}
			else
				if (game1->IsKeyDown(DIK_DOWN))
				{
					/*	if (game->IsKeyDown(DIK_S))
					simon->SetState(SIMON_STATE_ATTACK_SITTING);
					else*/
					simon1->SetState(SIMON_STATE_SIT);
				}
				else
					if (game1->IsKeyDown(DIK_SPACE))
					{
						if (simon1->isJumping == false)
						{
							simon1->SetState(SIMON_STATE_JUMP);
							simon1->isJumping = true;
						}
					}
					else
					{
						simon1->SetState(SIMON_STATE_IDLE);

					}
	}

}

void Scene2::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		if (simon1->isJumping == false)
		{
			simon1->SetState(SIMON_STATE_JUMP);
			simon1->isJumping = true;
		}

		break;
	case DIK_A: // reset
		simon1->SetState(SIMON_STATE_IDLE);
		simon1->SetPosition(688.0f, 0.0f);
		simon1->SetSpeed(0, 0);
		break;

		//case DIK_DOWNARROW:
		//	simon1->SetState(SIMON_STATE_SIT);
		//	break;
	case DIK_S:
		//if (simon1->untouchable == false)
		{
			if (simon1->GetState() == SIMON_STATE_SIT)
			{
				simon1->SetState(SIMON_STATE_ATTACK_SITTING);
				simon1->whip->CreateWeapon(simon1->x, simon1->y + 7, simon1->nx);

			}
			else
			{
				simon1->SetState(SIMON_STATE_ATTACK);
				simon1->whip->CreateWeapon(simon1->x, simon1->y, simon1->nx);

			}
		}
		break;
	case DIK_D:
	//	if (simon1->untouchable == false)
		{
			if (simon1->dagger->isOn == true)
			{
				if (simon1->dagger->GetState() == DAGGER_STATE_INACTIVE)
				{

					float x, y;
					simon1->GetPosition(x, y);
					if (simon1->GetState() == SIMON_STATE_SIT)
					{
						simon1->dagger->CreateWeapon(x, y + 7, simon1->nx);

						if (simon1->isUsingDagger == false)
						{
							if (simon1->nx > 0)
								simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
							else
								simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
							simon1->SetState(SIMON_STATE_THROW_SITTING);
							simon1->useDagger();

						}

					}
					else
					{


						simon1->dagger->CreateWeapon(x, y, simon1->nx);

						if (simon1->isUsingDagger == false)
						{
							if (simon1->nx > 0)
								simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
							else
								simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
							simon1->SetState(SIMON_STATE_THROW);
							simon1->useDagger();

						}

					}

				}

			}
		}
		break;
	case DIK_Z:

		spawnGhou(300 /*SCREEN_WIDTH*/, 50);
		break;
	}
}

void Scene2::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		break;
	case DIK_DOWNARROW:
		simon1->SetState(SIMON_STATE_IDLE);
		break;
	case DIK_LEFT:
		simon1->SetState(SIMON_STATE_IDLE);
		break;
	case DIK_RIGHT:
		simon1->SetState(SIMON_STATE_IDLE);
		break;
	}

}

void Scene2::LoadResources()
{
	camera1 = Camera::GetInstance();
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;
	simon1->SetPosition(50, 0);
	camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
	textures->Add(ID_TEX_MAP2, L"textures\\Map\\Map2.png", D3DCOLOR_XRGB(255, 0, 255));

	map1 = new Map(ID_TEX_MAP2, "textures\\Map\\Map2.csv");

	textures->Add(ID_TEX_GROUND, L"textures\\Ground\\ground2.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_ITEM_SMALLHEART, L"textures\\Item\\smallheart.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_GHOUL, L"textures\\Enemy\\Ghoul.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_PANTHER, L"textures\\Enemy\\Pant.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_CANDLE, L"textures\\Enemy\\1.png", D3DCOLOR_XRGB(255, 0, 255));
#pragma region Co-ordinations of Ground

	LPDIRECT3DTEXTURE9 texGround = textures->Get(ID_TEX_GROUND);
	sprites->Add(20001, 0, 0, 16, 16, texGround);

#pragma endregion

#pragma region Co-ordinations of Candle

	LPDIRECT3DTEXTURE9 texCandle = textures->Get(ID_TEX_CANDLE);
	sprites->Add(40001, 0, 0, 7, 15, texCandle);
	sprites->Add(40002, 8, 0, 15, 15, texCandle);

#pragma endregion

#pragma region Co-ordinations of Ghoul

	LPDIRECT3DTEXTURE9 texGhoul = textures->Get(ID_TEX_GHOUL);
	sprites->Add(22220, 0, 0, 15, 31, texGhoul); //right
	sprites->Add(22221, 18, 0, 33, 31, texGhoul);

	sprites->Add(22222, 0, 32, 15, 63, texGhoul);	//left
	sprites->Add(22223, 18, 32, 33, 63, texGhoul);
#pragma endregion


#pragma region Co-ordinations of PAnth

	LPDIRECT3DTEXTURE9 texPant = textures->Get(ID_TEX_PANTHER);
	sprites->Add(60000, 64, 18, 95, 33, texPant);	//run right
	sprites->Add(60001, 32, 18, 63, 33, texPant);

	sprites->Add(60010, 32, 0, 63, 15, texPant);	//run left
	sprites->Add(60011, 64, 0, 95, 15, texPant);

	sprites->Add(60002, 96, 18, 127, 33, texPant);	//sit right

	sprites->Add(60012, 0, 0, 31, 15, texPant);		//sit left


	sprites->Add(60003, 0, 18, 31, 33, texPant);	//jump right

	sprites->Add(60013, 96, 0, 127, 15, texPant);		//jump left



#pragma endregion
#pragma region Co-ordinations of SHeart

	LPDIRECT3DTEXTURE9 texSHeart = textures->Get(ID_TEX_ITEM_SMALLHEART);
	sprites->Add(23330, 0, 0, 8, 8, texSHeart);

#pragma endregion

#pragma region Adding Small Heart

	ani = new CAnimation(100);
	ani->Add(23330);
	animations->Add(482, ani);


#pragma endregion

#pragma region Adding Ghou

	ani = new CAnimation(100); // right
	ani->Add(22222);
	ani->Add(22223);
	animations->Add(531, ani);

	ani = new CAnimation(100);//left
	ani->Add(22220);
	ani->Add(22221);
	animations->Add(532, ani);
	
#pragma endregion

#pragma region Adding Panther

	ani = new CAnimation(100); //run right
	ani->Add(60000);
	ani->Add(60001);
	animations->Add(550, ani);

	ani = new CAnimation(100); //run left
	ani->Add(60010);
	ani->Add(60011);
	animations->Add(551, ani);

	ani = new CAnimation(100); //sit right
	ani->Add(60002);
	animations->Add(552, ani);
	
	ani = new CAnimation(100); //sit left
	ani->Add(60012);
	animations->Add(553, ani);

	ani = new CAnimation(100); //jump right
	ani->Add(60003);
	animations->Add(554, ani);
	
	ani = new CAnimation(100);//jump left
	ani->Add(60013);
	animations->Add(555, ani);

#pragma endregion
		 
#pragma region Adding Small Candle
		
		ani = new CAnimation(100);
		ani->Add(40001);
		ani->Add(40002);
		animations->Add(476, ani);

		/*for (int i = 0; i < 5; i++)
		{
		Torch *candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(smallheartInside);
		candle->SetPosition(29+i*(157-29), offsetMap +128);
		listEnemy1.push_back(candle);

		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(smallheartInside);
		candle->SetPosition(92 + i * (220 - 92), offsetMap + 97);
		listEnemy1.push_back(candle);
		}*/
#pragma endregion



#pragma region Adding Ground

	ani = new CAnimation(100);
	ani->Add(20001);

	animations->Add(999, ani);

// 3 ground neen
	Ground *ground = new Ground(1, BRICKMAP21_BBOX_WIDTH);
	ground->AddAnimation(999);
	ground->SetPosition(0, offsetMap + 160);
	listSurface1.push_back(ground);

	ground = new Ground(1, BRICKMAP22_BBOX_WIDTH);
	ground->AddAnimation(999);
	ground->SetPosition(0 + 17 + BRICKMAP21_BBOX_WIDTH, offsetMap + 160);
	listSurface1.push_back(ground);

	ground = new Ground(1, BRICKMAP23_BBOX_WIDTH);
	ground->AddAnimation(999);
	ground->SetPosition(0 + 17 * 2 + BRICKMAP21_BBOX_WIDTH + BRICKMAP22_BBOX_WIDTH, offsetMap + 160);
	listSurface1.push_back(ground);

	//3 ground len cau thang 

	ground = new Ground(1, 3 * 16);
	ground->AddAnimation(999);
	ground->SetPosition(688, offsetMap + 160 - 16 * 4);
	listSurface1.push_back(ground);

	ground = new Ground(1, 10 * 16);
	ground->AddAnimation(999);
	ground->SetPosition(688 + 4 * 16, offsetMap + 160 - 16 * 6);
	listSurface1.push_back(ground);


	ground = new Ground(1,6 * 16);
	ground->AddAnimation(999);
	ground->SetPosition(688 + 15 * 16, offsetMap + 160 - 16 * 4);
	listSurface1.push_back(ground);


#pragma endregion
	for (int i = 0; i < 3; i++)
	{
		pant = new Panther();
		pant->AddAnimation(550);
		pant->AddAnimation(551);
		pant->AddAnimation(552);
		pant->AddAnimation(553);
		pant->AddAnimation(554);
		pant->AddAnimation(555);
		if(i==0)
		pant->SetState(PANTHER_STATE_ACTIVE_LEFT);
		else
			if(i==1)
				pant->SetState(PANTHER_STATE_SIT_LEFT);
			else
				if(i==2)
					pant->SetState(PANTHER_STATE_JUMPING_LEFT);
		if (i == 0)
			pant->SetPosition(250, 125 + offsetMap);
		else
			if (i == 1)
				pant->SetPosition(280, 125 + offsetMap);
			else
				if (i == 2)
					pant->SetPosition(320, 125 + offsetMap);
	//	listEnemy1.push_back(pant);
	}
}

int tick = 0;

void Scene2::Update(DWORD dt)
{

	float x1, y1,x2,y2;
	x1 = Camera::GetInstance()->GetPosition().x;
	y1 = Camera::GetInstance()->GetPosition().y;
	tick += 1;

	simon1->GetPosition(x2, y2);
	if (x2 < 417 - SIMON_BIG_BBOX_WIDTH)
	{
		if (tick == 360)
		{
			tick = 0;
			spawnGhou(x1 + SCREEN_WIDTH - 60, 125 + offsetMap);
		}
		else if (tick > 360)
			tick = 0;
	}

	if (simon1->dagger->isOn == true)
	{
		if (simon1->isUsingDagger == true)
		{

			if ((simon1->dagger->x) < x1 || (simon1->dagger->x) > (x1 + SCREEN_WIDTH))
			{
				simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
				simon1->notUseDagger();
			}

		}
	}

	for (int i = 0; i < listItem1.size(); i++)
	{
		//if (Item1.at(i)->GetState() == ITEM_STATE_ACTIVE)+		Enemy1[i]	0x006196e8 {...}	CGameObject * {Ghou}

		listItem1.at(i)->Update(dt, &listSurface1);
	}


	for (int i = 0; i < listEnemy1.size(); i++)
		listEnemy1[i]->Update(dt, &listSurface1);

	erasingObjThatInacitve();

	if (simon1->untouchable == false)
		CollisionBetSimonAndEnemy();

	CollisionBetSimonAndItem();

	if (simon1->untouchable == false)
		CollisionBetWeaponAndEnemy();

	

	camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1

	camera1->Update();
	simon1->Update(dt, &listSurface1);
	if ((simon1->dagger->GetState() != DAGGER_STATE_INACTIVE) && simon1->dagger->isOn == true && simon1->isUsingDagger == true)
		simon1->dagger->Update(dt, &listSurface1);


//	if(Item1.at(0)->GetState()==SMALLHEART_STATE_ACTIVE)
	//Item1.at(0)->Update(dt, &listSurface1);

}

void Scene2::Render()
{
	LPDIRECT3DDEVICE9 d3ddv = game1->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 bb = game1->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game1->GetSpriteHandler();

	if (d3ddv->BeginScene())
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		map1->drawTileMap(camera1, ID_TEX_MAP2);
		for (int i = 0; i < listSurface1.size(); i++)
			listSurface1[i]->Render();
		for (int i = 0; i < listEnemy1.size(); i++)
			listEnemy1[i]->Render();
		for (int i = 0; i < listItem1.size(); i++)
			listItem1[i]->Render();

		simon1->Render();
		simon1->dagger->Render();
		simon1->whip->Render();
		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}



Scene2::Scene2(Simon *simon)
{
	simon1 = simon;
	LoadResources();
}


Scene2::~Scene2()
{

}

void Scene2::erasingObjThatInacitve()
{
	for (UINT i = 0; i < listEnemy1.size(); i++)
	{
		if (dynamic_cast<Ghou *>(listEnemy1.at(i)))
		{
			if (listEnemy1.at(i)->state == GHOU_STATE_INACTIVE)
			{
				listEnemy1.erase(listEnemy1.begin() + i);
				i = i - 1;
			}
		}
	
	}
}

void Scene2::spawnGhou(float x,float y)
{
	for (int i = 0; i < 1; i++)
	{
		ghou = new Ghou();
		ghou->AddAnimation(531);
		ghou->AddAnimation(532);
		ghou->setItemInside(smallheartInside);
		ghou->SetPosition(x+30+i*20, y);
		ghou->SetState(GHOU_STATE_ACTIVE_LEFT);
		listEnemy1.push_back(ghou);
	}
	ghou = new Ghou();
	ghou->AddAnimation(531);
	ghou->AddAnimation(532);
	ghou->setItemInside(smallheartInside);
	ghou->SetPosition(Camera::GetInstance()->GetPosition().x, y);
	ghou->SetState(GHOU_STATE_ACTIVE_RIGHT);
//	listEnemy1.push_back(ghou);
}

void Scene2::CollisionBetWeaponAndEnemy()
{

	if (simon1->whip->isFinished == false && simon1->whip->isAllowedToCollide == true)
	{
		for (UINT i = 0; i < listEnemy1.size(); i++)
		{

		if (simon1->whip->CheckCollision(listEnemy1.at(i)) == true)
			{
				if (dynamic_cast<Torch *>(listEnemy1.at(i)))
				{
					if (listEnemy1.at(i)->state == TORCH_STATE_ACTIVE)
					{
						float x, y;
						OutputDebugString(L"Collision Whip and Candle \n");
						listEnemy1.at(i)->SetState(TORCH_STATE_INACTIVE);
						listEnemy1.at(i)->GetPosition(x, y);

						switch (listEnemy1.at(i)->itemInside)
						{
						case 0:
							break;
						case bigheartInside:
							bigheart1->SetState(ITEM_STATE_ACTIVE);
							bigheart1->SetPosition(x, y);
							listItem1.push_back(bigheart1);
							break;
						case morningstarInside:
							morningstar1->SetState(ITEM_STATE_ACTIVE);
							morningstar1->SetPosition(x, y);
							listItem1.push_back(morningstar1);
							break;
						case daggerInside:
							dagger1->SetState(ITEM_STATE_ACTIVE);
							dagger1->SetPosition(x, y);
							listItem1.push_back(dagger1);
							break;
						case smallheartInside:
							smallheart1 = new SmallHeart(x);
							smallheart1->AddAnimation(482);
							smallheart1->SetState(ITEM_STATE_ACTIVE);
							smallheart1->SetPosition(x, y);
							listItem1.push_back(smallheart1);
							break;

						default:
							break;
						}
						listEnemy1.erase(listEnemy1.begin() + i);
						i = i - 1; //Optional cuz simon only can hit 1 torch at one moment
					}

				}
				else
					if (dynamic_cast<Ghou *>(listEnemy1.at(i)))
					{
						if (listEnemy1.at(i)->state == GHOU_STATE_ACTIVE_LEFT || listEnemy1.at(i)->state == GHOU_STATE_ACTIVE_RIGHT)
						{
							float x, y;
							OutputDebugString(L"Collision Whip and Ghou \n");
							listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
							listEnemy1.at(i)->GetPosition(x, y);

							switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								//tickHeart += 1;

								break;
							case morningstarInside:
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								//tickWhip += 1;
								break;
							case daggerInside:
								dagger1->SetState(ITEM_STATE_ACTIVE);
								dagger1->SetPosition(x, y);
								listItem1.push_back(dagger1);
								break;
							case smallheartInside:
								smallheart1 = new SmallHeart(x);
								smallheart1->AddAnimation(482);
								smallheart1->SetState(ITEM_STATE_ACTIVE);
								smallheart1->SetPosition(x, y);
								listItem1.push_back(smallheart1);
								break;

							default:
								break;
							}

							listEnemy1.erase(listEnemy1.begin() + i);
							i = i-1;
						}
					
					}
			}
		}
	}
	else
		if (simon1->dagger->state != DAGGER_STATE_INACTIVE && simon1->dagger->isOn == true && simon1->isUsingDagger == true)
		{
			for (UINT i = 0; i < listEnemy1.size(); i++)
			{
				if (simon1->dagger->CheckCollision(listEnemy1.at(i)) == true)
				{
					if (listEnemy1.at(i)->state == TORCH_STATE_ACTIVE)
					{
						float x, y;
						OutputDebugString(L"Collision Dagger and Candle \n");
						listEnemy1.at(i)->SetState(TORCH_STATE_INACTIVE);
						listEnemy1.at(i)->GetPosition(x, y);
						simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
						simon1->notUseDagger();






						switch (listEnemy1.at(i)->itemInside)
						{
						case 0:
							break;
						case bigheartInside:
							bigheart1->SetState(ITEM_STATE_ACTIVE);
							bigheart1->SetPosition(x, y);
							listItem1.push_back(bigheart1);
							//tickHeart += 1;

							break;
						case morningstarInside:
							morningstar1->SetState(ITEM_STATE_ACTIVE);
							morningstar1->SetPosition(x, y);
							listItem1.push_back(morningstar1);
							//tickWhip += 1;
							break;
						case daggerInside:
							dagger1->SetState(ITEM_STATE_ACTIVE);
							dagger1->SetPosition(x, y);
							listItem1.push_back(dagger1);
							break;
						case smallheartInside:
							smallheart1 = new SmallHeart(x);
							smallheart1->AddAnimation(482);
							smallheart1->SetState(ITEM_STATE_ACTIVE);
							smallheart1->SetPosition(x, y);
							listItem1.push_back(smallheart1);
							break;

						default:
							break;
							

						}
						listEnemy1.erase(listEnemy1.begin() + i);
						i = i - 1;
					}

					else
						if (dynamic_cast<Ghou *>(listEnemy1.at(i)))
						{
							if (listEnemy1.at(i)->state == GHOU_STATE_ACTIVE_LEFT || listEnemy1.at(i)->state == GHOU_STATE_ACTIVE_RIGHT)
							{
								float x, y;
								OutputDebugString(L"Collision Whip and Ghou \n");
								listEnemy1.at(i)->SetState(TORCH_STATE_INACTIVE);
								listEnemy1.at(i)->GetPosition(x, y);




								switch (listEnemy1.at(i)->itemInside)
								{
								case 0:
									break;
								case bigheartInside:
									bigheart1->SetState(ITEM_STATE_ACTIVE);
									bigheart1->SetPosition(x, y);
									listItem1.push_back(bigheart1);
									//tickHeart += 1;

									break;
								case morningstarInside:
									morningstar1->SetState(ITEM_STATE_ACTIVE);
									morningstar1->SetPosition(x, y);
									listItem1.push_back(morningstar1);
									//tickWhip += 1;
									break;
								case daggerInside:
									dagger1->SetState(ITEM_STATE_ACTIVE);
									dagger1->SetPosition(x, y);
									listItem1.push_back(dagger1);
									break;
								case smallheartInside:
									smallheart1 = new SmallHeart(x);
									smallheart1->AddAnimation(482);
									smallheart1->SetState(ITEM_STATE_ACTIVE);
									smallheart1->SetPosition(x, y);
									listItem1.push_back(smallheart1);
									break;

								default:
									break;
								}
								listEnemy1.erase(listEnemy1.begin() + i);
								i = i - 1;
							}


						}
				}
			}



		}
}

void Scene2::CollisionBetSimonAndItem()
{
	for (UINT i = 0; i < listItem1.size(); i++)
	{
		if (simon1->CheckCollision(listItem1.at(i)) == true)
		{
			if (dynamic_cast<BigHeart *>(listItem1.at(i)))
			{
				if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
				{

					OutputDebugString(L"Simon and BigHeart \n");
					listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
					//simon->heartCount += 5;

				}
			}
			else
				if (dynamic_cast<MorningStar *>(listItem1.at(i)))
				{
					if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
					{
						OutputDebugString(L"Simon and WHIP \n");
						listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
						simon1->whip->levelUpWhip();
					}
				}
				else
					if (dynamic_cast<Dagger1 *>(listItem1.at(i)))
					{
						if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
						{
							OutputDebugString(L"Simon and DAGGER \n");
							listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
							simon1->dagger->turnOnDagger();
							OutputDebugString(L"Dagger on \n");
						}
					}
					else
						if (dynamic_cast<SmallHeart *>(listItem1.at(i)))
						{
							if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
							{
								OutputDebugString(L"Simon and SmallHeart \n");
								listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
							}
						}
					else
						//if (dynamic_cast<Ground *>(Item1.at(i)))
						//{
						//	if (Item1.at(i)->state == INVIS_STATE_NEXT_LVL)
						//	{
						//		OutputDebugString(L"Proceed to lvl 2 \n");
						//		SceneManager::GetInstance()->replaceScene(new Scene2(simon));
						//		/*	delete simon;
						//			for (int i=0;i<2;i++)
						//			delete bigheart[i];
						//			delete dagger;
						//			delete ground;
						//			delete invisBox;
						//			delete invisBox2;
						//			delete camera;
						//			delete map;
						//			delete goldbag;
						//			for (int i = 0; i<2; i++)
						//			delete morningstar[i];*/
						//	}
						//	else
						//		if (Item1.at(i)->state == INVIS_STATE_INVIS_ITEM)
						//		{
						//			OutputDebugString(L"Invis item appear \n");
						//			Item1.at(i)->SetState(INVIS_STATE_INACTIVE);
						//			goldbag->SetPosition(660, 125 + offsetMap);
						//			goldbag->SetState(ITEM_STATE_ACTIVE);
						//			Item1.push_back(goldbag);
						//		}
						//}
						//else
							if (dynamic_cast<GoldBag *>(listItem1.at(i)))
							{
								if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
								{
									OutputDebugString(L"GoldBag \n");
									listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
								}

							}

			listItem1.erase(listItem1.begin() + i);
			i = i - 1;
		
		}
	}
}

void Scene2::CollisionBetSimonAndEnemy()
{
	if (simon1->GetState() != SIMON_STATE_HURT_LEFT || simon1->GetState() != SIMON_STATE_HURT_RIGHT)
	{
		for (UINT i = 0; i < listEnemy1.size(); i++)
		{
			//if (simon1->CheckCollision(listEnemy1.at(i)) == true)
			if (LPCOLLISIONEVENT e = simon1->SweptAABBEx(listEnemy1.at(i)))
			{
				if (e->t > 0 && e->t <= 1.0f)
				{
					if (dynamic_cast<Ghou *>(listEnemy1.at(i)))
					{
						if (e->nx == -1)
						{

							if (listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_LEFT ||
								listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_RIGHT)
							{

								OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n"); 
								if (simon1->isUsingDagger == true)
									simon1->notUseDagger();
								if (simon1->whip->isFinished == false)
									simon1->whip->isFinished = true;
								simon1->SetState(SIMON_STATE_HURT_LEFT);
								
									//	if (simon1->nx = 1)
								//		simon1->SetState(SIMON_STATE_HURT_RIGHT);
							//		else if(simon1->nx=-1)
								//		simon1->SetState(SIMON_STATE_HURT_LEFT);
									//simon->heartCount += 5;

							}
					
						}

						else
							if (e->nx == 1)
							{
								if (listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_LEFT ||
									listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_RIGHT)
								{

									OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
									if (simon1->isUsingDagger == true)
										simon1->notUseDagger();
									if (simon1->whip->isFinished == false)
										simon1->whip->isFinished = true;
									simon1->SetState(SIMON_STATE_HURT_RIGHT);
									

								}
							}
							else
								if (e->nx == 0)
								{
									if (e->ny == -1)
									{
										float x, y; 
										simon1->GetPosition(x, y);
										float x1, y1;
										listEnemy1.at(i)->GetPosition(x1, y1);
										if (x < x1)
										{
											OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
											if (simon1->isUsingDagger == true)
												simon1->notUseDagger();
											if (simon1->whip->isFinished == false)
												simon1->whip->isFinished = true;
											simon1->SetState(SIMON_STATE_HURT_LEFT);
										}
										else 
											if (x >= x1)
											{
												OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
												if (simon1->isUsingDagger == true)
													simon1->notUseDagger();
												if (simon1->whip->isFinished == false)
													simon1->whip->isFinished = true;
												simon1->SetState(SIMON_STATE_HURT_RIGHT);
											
											}
									}
								}
					}
				}
				else 
					{
					float al, at, ar, ab ;
					float bl, bt,  br, bb;
					listEnemy1.at(i)->GetBoundingBox(al, at, ar, ab);
					simon1->GetBoundingBox(bl, bt, br, bb);
					if (game1->AABB(al, at, ar, ab, bl, bt, br, bb)==true)
					{
						float x, y;
						simon1->GetPosition(x, y);
						float x1, y1;
						listEnemy1.at(i)->GetPosition(x1, y1);
						if (x < x1)
						{
							OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
							if (simon1->isUsingDagger == true)
								simon1->notUseDagger();
							if (simon1->whip->isFinished == false)
								simon1->whip->isFinished = true;
							simon1->SetState(SIMON_STATE_HURT_LEFT);
						}
						else
							if (x >= x1)
							{
								OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
								if (simon1->isUsingDagger == true)
									simon1->notUseDagger();
								if (simon1->whip->isFinished == false)
									simon1->whip->isFinished = true;
								simon1->SetState(SIMON_STATE_HURT_RIGHT);

							}
					}
					}
			}
		}
	}
	
}


