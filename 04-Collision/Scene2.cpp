#include "Scene2.h"
#include "Scene1.h"



CGame *game1 = CGame::GetInstance();
Ground *ground1;
Simon *simon1;
vector<LPGAMEOBJECT> listItem1;
vector<LPGAMEOBJECT> listSurface1;
vector<LPENEMY> listEnemy1;
vector<LPENEMY> listTorches1;
vector<LPSTAIRS> listUpStairs1;
vector<LPSTAIRS> listDownStairs1;
Camera *camera1 = Camera::GetInstance();
Map *map1;
Bat *bat1;
BigHeart *bigheart1;
MorningStar *morningstar1;
Dagger1 *dagger1;
SmallHeart *smallheart1;
Ghou *ghou;
Panther *pant;
Stairs *stairs;
Chicken *chick;
Door *door;
GroundEnemy *groundEnemy;
GoldBag *goldbag1;
Cross1 *cross1;
HolyWater1 *holy1;
Clock1 *clock1;
Axe1 *axe1;

int tickGhou = 300;
int tickBat = 290;
void Scene2::KeyState(BYTE * states)
{
	

	if (simon1->whip->isFinished == true)
	{


		if (game1->IsKeyDown(DIK_RIGHT))
		{
			if (simon1->proceedToNextLevel == false)
			{
				if (simon1->isOnStairs == false)
				{

					if (game1->IsKeyDown(DIK_S))
						simon1->SetState(SIMON_STATE_ATTACK);
					else
						simon1->SetState(SIMON_STATE_WALKING_RIGHT);

				}
				else
					if (simon1->isOnStairs == true)
					{
						if (simon1->directionOnStairs == true)
						{
							if (simon1->nx == 1)
							{
								if (CollisionBetSimonAndUpStairs() == false)
								{
									simon1->SetState(SIMON_STATE_UP_RIGHT);
								}

							}
							else
								if (simon1->nx == -1)
								{
									if (CollisionBetSimonAndUpStairs() == false)
									{
										simon1->directionOnStairs = false;
										simon1->SetState(SIMON_STATE_DOWN_RIGHT);

									}
								}
						}
						else
							if (simon1->directionOnStairs == false)
							{
								if (simon1->nx == 1)
								{
									if (CollisionBetSimonAndDownStairs() == false)
									{
										simon1->SetState(SIMON_STATE_DOWN_RIGHT);
									}
								}
								else
									if (simon1->nx == -1)
									{
										if (CollisionBetSimonAndUpStairs() == false)
										{
											simon1->directionOnStairs = true;
											simon1->SetState(SIMON_STATE_UP_RIGHT);

										}
									}
							}
					}
			}
		}
		else
			if (game1->IsKeyDown(DIK_LEFT))
			{
				if (simon1->proceedToNextLevel == false)
				{
					if (simon1->isOnStairs == false)
					{

						if (game1->IsKeyDown(DIK_S))
							simon1->SetState(SIMON_STATE_ATTACK);
						else
							simon1->SetState(SIMON_STATE_WALKING_LEFT);
					}
					else
						if (simon1->isOnStairs == true)
						{
								if (simon1->directionOnStairs == true)
								{
									
									if (simon1->nx == -1)
									{
										if (CollisionBetSimonAndUpStairs() == false)
										{
											simon1->SetState(SIMON_STATE_UP_LEFT);
										}
									}
									else 
										if (simon1->nx == 1)
										{
											if (CollisionBetSimonAndUpStairs() == false)
											{
												simon1->directionOnStairs = false;
												simon1->SetState(SIMON_STATE_DOWN_LEFT);
												
											}
										}
								}
								else
									if (simon1->directionOnStairs == false)
									{
										if (simon1->nx == -1)
										{
											if (CollisionBetSimonAndDownStairs() == false)
											{

												simon1->SetState(SIMON_STATE_DOWN_LEFT);
											}
										}
										else
											if (simon1->nx == 1)
											{
												if (CollisionBetSimonAndUpStairs() == false)
												{
													simon1->directionOnStairs = true;
													simon1->SetState(SIMON_STATE_UP_LEFT);

												}
											}
									}
							
						
						}
				}
			}
			else
				if (game1->IsKeyDown(DIK_DOWN))
				{
					if (simon1->proceedToNextLevel == false)
					{
						if (simon1->isOnStairs == false)
						{
							if(simon1->isJumping==false)
							{
								if (CollisionBetSimonAndUpStairs() == false)
								{
									simon1->SetState(SIMON_STATE_SIT);
								}
							}
						}
						else
							if (simon1->isOnStairs == true)
							{
								if (CollisionBetSimonAndDownStairs() == false)
								{
									if (simon1->directionOnStairs == false)
									{
										if (simon1->nx == 1)
										{
											simon1->SetState(SIMON_STATE_DOWN_RIGHT);
										}
										else
											if (simon1->nx == -1)
											{
												simon1->SetState(SIMON_STATE_DOWN_LEFT);
											}
									}
									else
										if (simon1->directionOnStairs == true)
										{
											simon1->directionOnStairs = false;
											if (simon1->nx == 1)
											{
												simon1->SetState(SIMON_STATE_DOWN_LEFT);
											}
											else
												if (simon1->nx == -1)
												{
													simon1->SetState(SIMON_STATE_DOWN_RIGHT);
												}
										}
								}
							}
					}
				}
				else
					if (game1->IsKeyDown(DIK_UP))
					{

						if (simon1->proceedToNextLevel == false)
						{
							if (simon1->isOnStairs == false)
							{
								if (simon1->isJumping == false)
								{

									CollisionBetSimonAndDownStairs();
								}
							}
							else
								if (simon1->isOnStairs == true)
								{
									if (CollisionBetSimonAndUpStairs() == false)
									{
										if (simon1->directionOnStairs == true)
										{
											if (simon1->nx == 1)
											{
												simon1->SetState(SIMON_STATE_UP_RIGHT);
											}
											else
												if (simon1->nx == -1)
												{
													simon1->SetState(SIMON_STATE_UP_LEFT);
												}
										}
										else
											if(simon1->directionOnStairs==false)
											{
												simon1->directionOnStairs = true;
												if (simon1->nx == 1)
												{
													simon1->SetState(SIMON_STATE_UP_LEFT);
												}
												else
													if (simon1->nx == -1)
													{
														simon1->SetState(SIMON_STATE_UP_RIGHT);
													}
											}

									}

								}
						}
					}
					else
					{
						if (simon1->isOnStairs == true)
							simon1->SetSpeed(0, 0);

						if (game1->IsKeyDown(DIK_SPACE))
						{
							if (simon1->proceedToNextLevel == false)
							{
								if (simon1->isOnStairs == false)
								{

									if (simon1->isJumping == false)
									{
										simon1->SetState(SIMON_STATE_JUMP);
										simon1->isJumping = true;
									}
								}
							}
						}
						else
						{
							simon1->SetState(SIMON_STATE_IDLE);

						}
					}

	}
}


void Scene2::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_1: //On dagger
		simon1->dagger->turnOnDagger();
		simon1->axe->turnOffAxe();
		simon1->holy->turnOffHolyWater();
		simon1->clock->turnOffClock();
		break;
	case DIK_2://On Axe
		simon1->dagger->turnOffDagger();
		simon1->axe->turnOnAxe();
		simon1->holy->turnOffHolyWater();
		simon1->clock->turnOffClock();
		break;
	case DIK_3://On HOly
		simon1->dagger->turnOffDagger();
		simon1->axe->turnOffAxe();
		simon1->holy->turnOnHolyWater();
		simon1->clock->turnOffClock();
		break;
	case DIK_4://On Clock
		simon1->dagger->turnOffDagger();
		simon1->axe->turnOffAxe();
		simon1->holy->turnOffHolyWater();
		simon1->clock->turnOnClock();
		break;
	case DIK_SPACE:
		if (simon1->proceedToNextLevel == false)
		{
			if (simon1->isOnStairs == false)
			{

				if (simon1->isJumping == false)
				{
					simon1->SetState(SIMON_STATE_JUMP);
					simon1->isJumping = true;
				}
			}
		}
		break;
	case DIK_A: // reset
		if (simon1->proceedToNextLevel == false)
		{
			simon1->SetState(SIMON_STATE_IDLE);
			simon1->isOnStairs = false;
			simon1->SetPosition(1190.0f, 0.0f);
			simon1->SetSpeed(0, 0);
			break;
		}
		//case DIK_DOWNARROW:
		//	simon1->SetState(SIMON_STATE_SIT);
		//	break;
	case DIK_S:
		if (simon1->proceedToNextLevel == false)
		{
			if (simon1->isOnStairs == true)
			{
				simon1->SetState(SIMON_STATE_ATTACK_ON_STAIRS);
				simon1->whip->CreateWeapon(simon1->x, simon1->y, simon1->nx);
			}
			else
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
		}
		break;
	case DIK_D:
	//	if (simon1->untouchable == false)
		if (simon1->proceedToNextLevel == false)
	
		{
			if (simon1->dagger->isOn == true && //dagger
				simon1->axe->isOn==false &&
				simon1->holy->isOn == false &&
				simon1->clock->isOn == false)
			{
				if (simon1->dagger->GetState() == DAGGER_STATE_INACTIVE)
				{
					float x, y;
					simon1->GetPosition(x, y);
					if (simon1->isOnStairs == true)
					{
						simon1->dagger->CreateWeapon(x, y, simon1->nx);
						if (simon1->isUsingDagger == false)
						{
							if (simon1->nx > 0)
								simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
							else
								simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
							simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
							simon1->useDagger();

						}
					}
					else
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
			else
				if (simon1->dagger->isOn == false && // axe
					simon1->axe->isOn == true &&
					simon1->holy->isOn == false &&
					simon1->clock->isOn == false)
				{
					if (simon1->axe->GetState() == AXE_STATE_INACTIVE)
					{
						float x, y;
						simon1->GetPosition(x, y);
						if (simon1->isOnStairs == true)
						{
							simon1->axe->CreateWeapon(x, y, simon1->nx);
							if (simon1->isUsingDagger == false)
							{
								if (simon1->nx > 0)
									simon1->axe->SetState(AXE_STATE_ACTIVE_RIGHT);
								else
									simon1->axe->SetState(AXE_STATE_ACTIVE_LEFT);
								simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
								simon1->useDagger();

							}
						}
						else
							if (simon1->GetState() == SIMON_STATE_SIT)
							{
								simon1->axe->CreateWeapon(x, y + 7, simon1->nx);

								if (simon1->isUsingDagger == false)
								{
									if (simon1->nx > 0)
										simon1->axe->SetState(AXE_STATE_ACTIVE_RIGHT);
									else
										simon1->axe->SetState(AXE_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW_SITTING);
									simon1->useDagger();

								}

							}
							else
							{


								simon1->axe->CreateWeapon(x, y, simon1->nx);

								if (simon1->isUsingDagger == false)
								{
									if (simon1->nx > 0)
										simon1->axe->SetState(AXE_STATE_ACTIVE_RIGHT);
									else
										simon1->axe->SetState(AXE_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW);
									simon1->useDagger();

								}

							}

					}

				}
				else
					if (simon1->dagger->isOn == false && //holy
						simon1->axe->isOn == false &&
						simon1->holy->isOn == true &&
						simon1->clock->isOn == false)
					{
						if (simon1->dagger->GetState() == DAGGER_STATE_INACTIVE)
						{
							float x, y;
							simon1->GetPosition(x, y);
							if (simon1->isOnStairs == true)
							{
								simon1->dagger->CreateWeapon(x, y, simon1->nx);
								if (simon1->isUsingDagger == false)
								{
									if (simon1->nx > 0)
										simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
									else
										simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
									simon1->useDagger();

								}
							}
							else
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
					else
						if (simon1->dagger->isOn == false && //clock
							simon1->axe->isOn == false &&
							simon1->holy->isOn == false &&
							simon1->clock->isOn == true  )
						{
							float x, y;
							simon1->GetPosition(x, y);

							simon1->clock->CreateWeapon(x, y, simon1->nx);
							if (simon1->isOnStairs == true)
								{
										simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
										freezeEnemyFunction();
								}
								else
									if (simon1->GetState() == SIMON_STATE_SIT)
									{
											simon1->SetState(SIMON_STATE_THROW_SITTING);
											freezeEnemyFunction();
									}
									else
									{
											simon1->SetState(SIMON_STATE_THROW);
											freezeEnemyFunction();
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
		
			//simon1->SetState(SIMON_STATE_IDLE);
		
		break;
	case DIK_UP:
	
			//simon1->SetState(SIMON_STATE_IDLE);
		
		break;

	}

}

void Scene2::LoadResources()
{
	simon1->proceedToNextLevel = false;
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
	textures->Add(ID_TEX_DOOR, L"textures\\Ground\\Gate1.png", D3DCOLOR_XRGB(255, 0, 255));



	textures->Add(ID_TEX_ITEM_SMALLHEART, L"textures\\Item\\smallheart.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_CROSS, L"textures\\Item\\cross.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_HOLY, L"textures\\Item\\holywater.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_CHICKEN, L"textures\\Item\\10.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_CLOCK, L"textures\\Item\\clock.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_AXE, L"textures\\Item\\7.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_GHOUL, L"textures\\Enemy\\Ghoul.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_BAT, L"textures\\Enemy\\Bat.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_PANTHER, L"textures\\Enemy\\Pant.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_CANDLE, L"textures\\Enemy\\1.png", D3DCOLOR_XRGB(255, 0, 255));

	textures->Add(ID_TEX_GROUND3, L"textures\\Ground\\ground3.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_GROUND4, L"textures\\Ground\\ground4.png", D3DCOLOR_XRGB(176, 224, 248));

#pragma region Co-ordinations of Ground

	
	//Ground 2
	LPDIRECT3DTEXTURE9 texGround = textures->Get(ID_TEX_GROUND);
	sprites->Add(20001, 0, 0, 16, 16, texGround);

	//Ground 2
	LPDIRECT3DTEXTURE9 texGround3 = textures->Get(ID_TEX_GROUND3);
	sprites->Add(20002, 0, 0, 16, 16, texGround3);

	//Ground 2
	LPDIRECT3DTEXTURE9 texGround4 = textures->Get(ID_TEX_GROUND4);
	sprites->Add(20003, 0, 0, 16, 16, texGround4);

#pragma endregion

#pragma region Co-ordinations of Candle

	LPDIRECT3DTEXTURE9 texCandle = textures->Get(ID_TEX_CANDLE);
	sprites->Add(40001, 0, 0, 7, 15, texCandle);
	sprites->Add(40002, 8, 0, 15, 15, texCandle);

#pragma endregion

#pragma region Co-ordinations of Door

	LPDIRECT3DTEXTURE9 texDoor = textures->Get(ID_TEX_DOOR);
	sprites->Add(40011, 1, 0, 8, 47, texDoor);
	sprites->Add(40012, 48, 0, 87, 47, texDoor);

#pragma endregion

#pragma region Co-orrdiantions of Bat

	LPDIRECT3DTEXTURE9 texBat = textures->Get(ID_TEX_BAT);

	sprites->Add(22300, 48, 0, 63, 15, texBat);// left side
	sprites->Add(22301, 32, 0, 47, 15, texBat);
	sprites->Add(22302, 16, 0, 31, 15, texBat);

	sprites->Add(22303, 0, 16, 15, 31, texBat);// right side
	sprites->Add(22304, 16, 16, 31, 31, texBat);
	sprites->Add(22305, 32, 16, 47, 31, texBat);

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

#pragma region Co-ordinations of HolyWater

	LPDIRECT3DTEXTURE9 texHoly = textures->Get(ID_TEX_ITEM_HOLY);
	sprites->Add(23041, 0, 0, 15, 15, texHoly);

#pragma endregion

#pragma region Co-ordinations of Clock

	LPDIRECT3DTEXTURE9 texClock = textures->Get(ID_TEX_ITEM_CLOCK);
	sprites->Add(23541, 0, 0, 14, 15, texClock);

#pragma endregion

#pragma region Co-ordinations of Axe

	LPDIRECT3DTEXTURE9 texAxe = textures->Get(ID_TEX_ITEM_AXE);
	sprites->Add(23641, 0, 0, 14, 13, texAxe);

#pragma endregion

#pragma region Co-ordinations of Cross

	LPDIRECT3DTEXTURE9 texCross = textures->Get(ID_TEX_ITEM_CROSS);
	sprites->Add(23042, 0, 0, 15, 15, texCross);


#pragma endregion

#pragma region Co-ordinations of Chicken

	LPDIRECT3DTEXTURE9 texChicken = textures->Get(ID_TEX_ITEM_CHICKEN);
	sprites->Add(23331, 0, 0, 15, 12, texChicken);

#pragma endregion

	
#pragma region Adding item Clcok

	ani = new CAnimation(100);
	ani->Add(23541);
	animations->Add(426, ani);


#pragma endregion

#pragma region Adding item Axe1

	ani = new CAnimation(100);
	ani->Add(23641);
	animations->Add(427, ani);


#pragma endregion

#pragma region Adding item Cross

	ani = new CAnimation(100);
	ani->Add(23042);
	animations->Add(483, ani);


#pragma endregion

#pragma region Adding item HolyWater

	ani = new CAnimation(100);
	ani->Add(23041);
	animations->Add(491, ani);


#pragma endregion

#pragma region Adding Small Heart

	ani = new CAnimation(100);
	ani->Add(23330);
	animations->Add(482, ani);


#pragma endregion

#pragma region Adding Chicken

	ani = new CAnimation(100);
	ani->Add(23331);
	animations->Add(490, ani);


#pragma endregion

#pragma region Adding Door

	ani = new CAnimation(100);
	ani->Add(40011);
	animations->Add(495, ani);

	ani = new CAnimation(100);
	ani->Add(40012);
	animations->Add(496, ani);
#pragma endregion

#pragma region Adding Bat
	ani = new CAnimation(200);
	ani->Add(22300);
	ani->Add(22301);
	ani->Add(22302);
	animations->Add(020, ani);

	ani = new CAnimation(200);
	ani->Add(22303);
	ani->Add(22304);
	ani->Add(22305);
	animations->Add(021, ani);
	
	ani = new CAnimation(200);
	ani->Add(22300);
	animations->Add(022, ani);

	ani = new CAnimation(200);
	ani->Add(22303);
	animations->Add(023, ani);
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

	ani = new CAnimation(100); //freeze right
	ani->Add(22222);
	animations->Add(533, ani);

	ani = new CAnimation(100);//freeze left
	ani->Add(22220);
	animations->Add(534, ani);

	
#pragma endregion

#pragma region Adding Panther

	ani = new CAnimation(100); //run right
	ani->Add(60000);
	ani->Add(60001);
	ani->Add(60003);
	animations->Add(550, ani);

	ani = new CAnimation(100); //run left
	ani->Add(60010);
	ani->Add(60011);
	ani->Add(60013);
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

		for (int i = 0; i < 5; i++)
		{
		Torch *candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(29+i*(157-29), offsetMap +128);
		listTorches1.push_back(candle);

		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(92 + i * (220 - 92), offsetMap + 97);
		listTorches1.push_back(candle);
		}
		
		Torch *candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(673,offsetMap+39);
		listTorches1.push_back(candle);

		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(735,130+offsetMap);
		listTorches1.push_back(candle);

		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(799,offsetMap+8);
		listTorches1.push_back(candle);

		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(992, offsetMap + 39);
		listTorches1.push_back(candle);
	
		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(929, offsetMap + 130);
		listTorches1.push_back(candle);

		for (int i = 0; i < 4; i++)
		{
			candle = new Torch(1);
			candle->AddAnimation(476);
			candle->SetState(CANDLE_STATE_ACTIVE);
			candle->setItemInside(chickenInside);
			candle->SetPosition(1055+i*64, offsetMap + 130);
			listTorches1.push_back(candle);

		}


		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(1366, offsetMap + 113);
		listTorches1.push_back(candle);
		
		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(1437, offsetMap + 33);
		listTorches1.push_back(candle);

		candle = new Torch(1);
		candle->AddAnimation(476);
		candle->SetState(CANDLE_STATE_ACTIVE);
		candle->setItemInside(chickenInside);
		candle->SetPosition(1502, offsetMap + 4);
		listTorches1.push_back(candle);
#pragma endregion



#pragma region Adding Ground

	ani = new CAnimation(100);
	ani->Add(20001);

	animations->Add(999, ani);

	ani = new CAnimation(100);//ground 3
	ani->Add(20002);
	animations->Add(998, ani);

	ani = new CAnimation(100);//ground 4
	ani->Add(20003);
	animations->Add(997, ani);
	
	

	//2 mieng ground chicken
	groundEnemy = new GroundEnemy();
	groundEnemy->AddAnimation(998);
	groundEnemy->SetPosition(1792, offsetMap + 128);
	groundEnemy->SetState(ITEM_STATE_ACTIVE);
	listEnemy1.push_back(groundEnemy);

	groundEnemy = new GroundEnemy();
	groundEnemy->AddAnimation(997);
	groundEnemy->setItemInside(chickenInside);
	groundEnemy->SetPosition(1792, offsetMap + 128+16);
	groundEnemy->SetState(ITEM_STATE_ACTIVE);
	listEnemy1.push_back(groundEnemy);


	// 3 ground neen
	Ground *ground = new Ground(1, BRICKMAP21_BBOX_WIDTH);
	ground->SetPosition(0, offsetMap + 160);
	listSurface1.push_back(ground);

	ground = new Ground(1, BRICKMAP22_BBOX_WIDTH);
	ground->SetPosition(0 + 17 + BRICKMAP21_BBOX_WIDTH, offsetMap + 160);
	listSurface1.push_back(ground);

	ground = new Ground(1, BRICKMAP23_BBOX_WIDTH);
	ground->SetPosition(0 + 17 * 2 + BRICKMAP21_BBOX_WIDTH + BRICKMAP22_BBOX_WIDTH, offsetMap + 160);
	listSurface1.push_back(ground);

	//3 ground len cau thang 

	ground = new Ground(1, 3 * 16);
	ground->SetPosition(688, offsetMap + 160 - 16 * 4);
	listSurface1.push_back(ground);

	ground = new Ground(1, 10 * 16);
	ground->SetPosition(688 + 4 * 16, offsetMap + 160 - 16 * 6);
	listSurface1.push_back(ground);


	ground = new Ground(1,6 * 16);
	ground->SetPosition(688 + 15 * 16, offsetMap + 160 - 16 * 4);
	listSurface1.push_back(ground);

	//2 ground len thang cuoi

	ground = new Ground(1, 17 * 16);
	ground->SetPosition(1392, offsetMap + 160 - 16 * 6);
	listSurface1.push_back(ground);

	ground = new Ground(1, 3 * 16);
	ground->SetPosition(1392+17*16, offsetMap + 160 - 16 * 4);

	listSurface1.push_back(ground);

	//wall bet 2 lvls
	ground = new Ground(1, 16);
	ground->SetPosition(1528, offsetMap + 96);
	listSurface1.push_back(ground);

	ground = new Ground(1, 16);
	ground->SetPosition(1528, offsetMap + 96+32);
	listSurface1.push_back(ground);
	//Box proceed to next lvl
	ground = new Ground(0, 0);
	ground->SetState(INVIS_STATE_NEXT_LVL);
	ground->SetPosition(1520, offsetMap + 43);
	listItem1.push_back(ground);

	door = new Door();
	door->SetState(DOOR_STATE_ACTIVE_CLOSED);
	door->AddAnimation(495);
	door->AddAnimation(496);
	door->SetPosition(1528, offsetMap + 16);
	listSurface1.push_back(door);
	

#pragma endregion

#pragma region Adding Panther 
	pant = new Panther(15);
	pant->AddAnimation(550);
	pant->AddAnimation(551);

	pant->AddAnimation(552);
	pant->AddAnimation(553);

	pant->AddAnimation(554);
	pant->AddAnimation(555);

	pant->AddAnimation(554);
	pant->AddAnimation(555);

	pant->AddAnimation(554);
	pant->AddAnimation(555);

	pant->AddAnimation(552);//freeze sit right let
	pant->AddAnimation(553);
	pant->setItemInside(randomIteminside());
	pant->SetState(PANTHER_STATE_SIT_LEFT);
	pant->SetPosition(685, 0 + offsetMap);
	listEnemy1.push_back(pant);

	pant = new Panther(8 * 20);
	pant->AddAnimation(550);
	pant->AddAnimation(551);

	pant->AddAnimation(552);
	pant->AddAnimation(553);

	pant->AddAnimation(554);
	pant->AddAnimation(555);

	pant->AddAnimation(554);
	pant->AddAnimation(555);

	pant->AddAnimation(554);
	pant->AddAnimation(555);

	pant->AddAnimation(552);//freeze sit right let
	pant->AddAnimation(553);
	pant->setItemInside(randomIteminside());
	pant->SetState(PANTHER_STATE_SIT_LEFT);
	pant->SetPosition(880, 0 + offsetMap);
	listEnemy1.push_back(pant);

	pant = new Panther(1 * 16);
	pant->AddAnimation(550);//right left
	pant->AddAnimation(551);

	pant->AddAnimation(552);//sit right left
	pant->AddAnimation(553);

	pant->AddAnimation(554);//jump right left
	pant->AddAnimation(555);

	pant->AddAnimation(554);//freeze right left
	pant->AddAnimation(555); 

	pant->AddAnimation(554);//freeze fly right let
	pant->AddAnimation(555);

	pant->AddAnimation(552);//freeze sit right let
	pant->AddAnimation(553);

	pant->setItemInside(randomIteminside());
	pant->SetState(PANTHER_STATE_SIT_LEFT);
	pant->SetPosition(945, 0 + offsetMap);
	listEnemy1.push_back(pant);

#pragma endregion 

		

#pragma region Adding Stairs
		//1=right , 2 = left
		////1st stair
		stairs = new Stairs(1,true);
		stairs->SetPosition(611, offsetMap + 159);
		listDownStairs1.push_back(stairs);

		stairs = new Stairs(2,false);
		stairs->SetPosition(675, offsetMap + 35);
		listUpStairs1.push_back(stairs);

		//2nd stair
		stairs = new Stairs(1, true);
		stairs->SetPosition(707, offsetMap + 95);
		listDownStairs1.push_back(stairs);

		stairs = new Stairs(2, false);
		stairs->SetPosition(752-14, offsetMap + 4);
		listUpStairs1.push_back(stairs);
		//1= right, 2 = left
		////3rd stair
		stairs = new Stairs(1, false);
		stairs->SetPosition(878+20, offsetMap + 4);
		listUpStairs1.push_back(stairs);

		stairs = new Stairs(2, true);
		stairs->SetPosition(928, offsetMap + 95);
		listDownStairs1.push_back(stairs);

		//4th stair
		stairs = new Stairs(1, true);
		stairs->SetPosition(1283, offsetMap + 159);
		listDownStairs1.push_back(stairs);

		stairs = new Stairs(2, false);
		stairs->SetPosition(1392-14, offsetMap + 4);
		listUpStairs1.push_back(stairs);

		//5th stair
		stairs = new Stairs(1, false);
		stairs->SetPosition(1698,  offsetMap + 35);
		listUpStairs1.push_back(stairs);
		//offsetMap + 160 - 16 * 4
		stairs = new Stairs(2, true);
		stairs->SetPosition(1762, offsetMap + 159);
		listDownStairs1.push_back(stairs);

#pragma endregion
}
void Scene2::XuLyPanthera()
{

	


	for (int i = 0; i < listEnemy1.size(); i++)
	{
		if (dynamic_cast<Panther *>(listEnemy1.at(i)))
		{
			
			{
				if ((listEnemy1.at(i)->x - simon1->x) <= 16 * 4)
				{
					if (listEnemy1.at(i)->changeDirection == false)
					{

						if (listEnemy1.at(i)->GetState() == PANTHER_STATE_SIT_LEFT)
							listEnemy1.at(i)->SetState(PANTHER_STATE_ACTIVE_LEFT);
						if (listEnemy1.at(i)->GetState() == PANTHER_STATE_SIT_RIGHT)
							listEnemy1.at(i)->SetState(PANTHER_STATE_ACTIVE_RIGHT);

					}
				}
				if (listEnemy1.at(i)->jumped == true)
				{
					if (listEnemy1.at(i)->GetState() == PANTHER_STATE_ACTIVE_RIGHT ||
						listEnemy1.at(i)->GetState() == PANTHER_STATE_ACTIVE_LEFT)
					{
						if (listEnemy1.at(i)->changeDirection == false)

						{
							listEnemy1.at(i)->changeDirection = true;
							if ((listEnemy1.at(i)->x - simon1->x) > 0)
							{
								listEnemy1.at(i)->SetState(PANTHER_STATE_ACTIVE_LEFT);
							}
							else
								if ((listEnemy1.at(i)->x - simon1->x) < 0)
								{
									listEnemy1.at(i)->SetState(PANTHER_STATE_ACTIVE_RIGHT);
								}
						}

					}
				}
				 }
			

		}
	}

}

void Scene2::Update(DWORD dt)
{

	
 	if (simon1->proceedToNextLevel == false)
	{
		camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
		camera1->Update();
		if (lvl2 == false)
		{
			if (camera1->GetPosition().x > 1191)
				camera1->SetPosition(1190, camera1->GetPosition().y);
		}
		else
			if (camera1->GetPosition().x <1536)
				camera1->SetPosition(1536, camera1->GetPosition().y);
	}
	else
	{
		if (camera1->GetPosition().x <= 1387)
		{
			camera1->SetPosition(camera1->GetPosition().x + 1, camera1->GetPosition().y);
		}
		else
			if (camera1->GetPosition().x > 1387)
			{

				door->SetState(DOOR_STATE_ACTIVE_OPENED);
				simon1->SetState(SIMON_STATE_WALKING_RIGHT);
				if (simon1->x > 1584)
				{
					simon1->SetState(SIMON_STATE_IDLE);

					door->SetState(DOOR_STATE_ACTIVE_CLOSED);
					if (camera1->GetPosition().x < 1536)
						camera1->SetPosition(camera1->GetPosition().x + 1, camera1->GetPosition().y);
					if (camera1->GetPosition().x >= 1536)
					{
						lvl2 = true;

						door->SetState(DOOR_STATE_INACTIVE);
						simon1->proceedToNextLevel = false;
					}
				
				}
			}
	}
		
	
	

	float x1, y1;
	x1 = Camera::GetInstance()->GetPosition().x;
	y1 = Camera::GetInstance()->GetPosition().y;
	
	tickGhou += 1;
	if ((simon1->x < 417 - SIMON_BIG_BBOX_WIDTH) || (simon1->x>1117 && simon1->x<1525))//chi cho ghou xuan hien khi simon trong vung do
	{//spawn every 6 seconds
		if (tickGhou == 360)
		{
			tickGhou = 0;
			spawnGhou(x1 + SCREEN_WIDTH - 60, 125 + offsetMap);
		}
		else if (tickGhou > 360)
			tickGhou = 0;
	}
	tickBat += 1;
	if (simon1->x > 1535 && simon1->x < 1807)//spawn Bat every 5 seconds/ fly speed 3 sec
	{
		if (tickBat == 330)
		{
			tickBat = 0;
			spawnBat(simon1,camera1);
		}
		else if (tickBat > 330)
		{
			tickBat = 0;
		}
	}

	if (simon1->x > 512 && simon1->x < 1120)//chi xu ly khi simon trong vung panter spawn
		XuLyPanthera();
	
	if (simon1->isUsingDagger == true)
	{
		if (simon1->dagger->isOn == true)
		{
			if ((simon1->dagger->GetState() != DAGGER_STATE_INACTIVE) && simon1->dagger->isOn == true && simon1->isUsingDagger == true)
				simon1->dagger->Update(dt, &listSurface1);


			if ((simon1->dagger->x) < x1 || (simon1->dagger->x) > (x1 + SCREEN_WIDTH))// bay ngoai man hinh thi cho dagger inactive
			{
				simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
				simon1->notUseDagger();
			}

		}
		else
			if (simon1->axe->isOn == true)
			{
				if ((simon1->axe->GetState() != DAGGER_STATE_INACTIVE) && simon1->axe->isOn == true && simon1->isUsingDagger == true)
					simon1->axe->Update(dt, &listSurface1);
			
				if (simon1->axe->GetState() == AXE_STATE_INACTIVE)
				{
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

	erasingObjThatInacitve();// xoa may enemy di ra khoi man hinh

	if (simon1->untouchable == false)//bi untouchable thi k va cham voi enemy nua
		CollisionBetSimonAndEnemy();

	CollisionBetSimonAndItem();

	CollisionBetWeaponAndEnemy();

	
		simon1->Update(dt, &listSurface1);
		if (lvl2 == true)
		{
			if (simon1->x < 1536)
				simon1->x = 1536;
			if (groundEnemy->GetState()== GROUND_STATE_INACTIVE)
			{

				if (simon1->x > 1808-16)
					simon1->x=1808-16;
			}
			else
				if (simon1->x > 1792-16)
					simon1->x = 1792-16;
		}
		



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
		for (int i = 0; i < listDownStairs1.size(); i++)
			listDownStairs1[i]->Render();
		for (int i = 0; i < listUpStairs1.size(); i++)
			listUpStairs1[i]->Render();
		for (int i = 0; i < listSurface1.size(); i++)
			listSurface1[i]->Render();
		for (int i = 0; i < listTorches1.size(); i++)
			listTorches1[i]->Render();
		for (int i = 0; i < listEnemy1.size(); i++)
			listEnemy1[i]->Render();
		for (int i = 0; i < listItem1.size(); i++)
			listItem1[i]->Render();

		simon1->Render();
		simon1->dagger->Render();
		simon1->axe->Render();
		simon1->whip->Render();
		spriteHandler->End();
		d3ddv->EndScene();
	}

	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

int Scene2::randomIteminside()
{//ti le la  12 sHeart : 2 bHeart: 2 mStar : 1 hWater : 1 cross
//	: 1 redBag : 1 whiteBag : 1 blueBag : 1 axe : 1 watch :1 dagger : 1chicken
	int randomNumber;
	randomNumber = rand() % 25;
	if (randomNumber == 0 || randomNumber == 1 || randomNumber == 2 || randomNumber == 3 ||
		randomNumber == 18 || randomNumber ==17 || randomNumber == 19 || randomNumber == 20 ||
		randomNumber == 21 || randomNumber == 22 || randomNumber == 23 || randomNumber == 24)
	{
		return smallheartInside;
	}
	else
		if (randomNumber == 4 || randomNumber == 5)
		{
			return bigheartInside;
		}
		else
			if (randomNumber == 6 || randomNumber == 7)
			{
				return morningstarInside;
			}
			else
				if (randomNumber == 8)
				{
					return holywaterInside;
				}
				else
					if (randomNumber == 9)
					{
						return crossInside;
					}
					else
						if (randomNumber == 10)
						{
							return redbagInside;
						}
						else
							if (randomNumber == 11)
							{
								return whitebagInside;
							}
							else
								if (randomNumber == 12)
								{
									return bluebagInside;
								}
								else
									if (randomNumber == 13)
									{
										return axeInside;
									}
									else
										if (randomNumber == 14)
										{
											return clockInside;
										}
										else
											if (randomNumber == 15)
											{
												return daggerInside;
											}
											else
												if (randomNumber == 16)
												{
													return chickenInside;
												}

}



Scene2::Scene2(Simon *simon)
{
	simon1 = simon;
	lvl2 = false;
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
		else
			if (dynamic_cast<Panther *>(listEnemy1.at(i)))
			{
				if (listEnemy1.at(i)->state == PANTHER_STATE_INACTIVE)
				{
					listEnemy1.erase(listEnemy1.begin() + i);
					i = i - 1;
				}
			}
			else
				if (dynamic_cast<Bat *>(listEnemy1.at(i)))
				{
					if (listEnemy1.at(i)->state == BAT_STATE_INACTIVE)
					{
						listEnemy1.erase(listEnemy1.begin() + i);
						i = i - 1;
					}
				}
	
	}
}

void Scene2::spawnGhou(float x,float y)
{
	int xz = 0;
	for (int z = 0; z < listEnemy1.size(); z++)
	{
		if (dynamic_cast<Ghou*>(listEnemy1.at(z)))
		{
			xz = xz + 1;
		}
	}
	if (xz == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			ghou = new Ghou();
			ghou->AddAnimation(531);
			ghou->AddAnimation(532);
			ghou->AddAnimation(533);
			ghou->AddAnimation(534);
			ghou->setItemInside(randomIteminside());
			ghou->SetPosition(x + i * 16, y);
			ghou->SetState(GHOU_STATE_ACTIVE_LEFT);
			listEnemy1.push_back(ghou);
		}
		ghou = new Ghou();
		ghou->AddAnimation(531);
		ghou->AddAnimation(532);
		ghou->AddAnimation(533);
		ghou->AddAnimation(534);
		ghou->setItemInside(randomIteminside());
		ghou->SetPosition(Camera::GetInstance()->GetPosition().x+15, y);
		ghou->SetState(GHOU_STATE_ACTIVE_RIGHT);
		listEnemy1.push_back(ghou);
	}
}

void Scene2::spawnBat(Simon * simon,Camera *camera1)
{
	bat1 = new Bat(simon->y+8);
	bat1->AddAnimation(021);
	bat1->AddAnimation(020);
	bat1->AddAnimation(023);
	bat1->AddAnimation(022);
	bat1->setItemInside(randomIteminside());
	listEnemy1.push_back(bat1);
	if (simon->nx == 1)
	{
		bat1->SetState(BAT_STATE_ACTIVE_LEFT);
		bat1->SetPosition(camera1->GetPosition().x+SCREEN_WIDTH-4, (simon->y + 8));
	}
	else
		if (simon->nx == -1)
		{

			bat1->SetState(BAT_STATE_ACTIVE_RIGHT);
			bat1->SetPosition(camera1->GetPosition().x + 4, (simon->y + 8));
		}


}

void Scene2::freezeEnemyFunction()
{
	for (UINT i = 0; i < listEnemy1.size(); i++)
	{


		if (listEnemy1.at(i)->x > Camera::GetInstance()->GetPosition().x &&
			listEnemy1.at(i)->x<Camera::GetInstance()->GetPosition().x + SCREEN_WIDTH &&
			listEnemy1.at(i)->y>Camera::GetInstance()->GetPosition().y &&
			listEnemy1.at(i)->y < Camera::GetInstance()->GetPosition().y + SCREEN_HEIGHT)
		{
			if (!(dynamic_cast<GroundEnemy *>(listEnemy1.at(i))))
			{

				listEnemy1.at(i)->SetState(ENEMY_STATE_FREEZE);
				listEnemy1.at(i)->StartUntouchable();
			}

		}
	}
}
/*
switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1 = new BigHeart();
								bigheart1->AddAnimation(765);
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								break;
							case morningstarInside:
								morningstar1 = new MorningStar();
								morningstar1->AddAnimation(777);
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								break;
							case daggerInside:
								dagger1 = new Dagger1();
								dagger1->AddAnimation(767);
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
							case crossInside:
								cross1 = new Cross1();
								cross1->AddAnimation(483);
								cross1->SetState(ITEM_STATE_ACTIVE);
								cross1->SetPosition(x, y);
								listItem1.push_back(cross1);
								break;
							case holywaterInside:
								holy1 = new HolyWater1();
								holy1->AddAnimation(491);
								holy1->SetState(ITEM_STATE_ACTIVE);
								holy1->SetPosition(x, y);
								listItem1.push_back(holy1);
								break;
							case whitebagInside:
								goldbag1 = new GoldBag(0);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case redbagInside:
								goldbag1 = new GoldBag(1);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case bluebagInside:
								goldbag1 = new GoldBag(2);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;

							case chickenInside:
								chick = new Chicken();
								chick->AddAnimation(490);
								chick->SetState(ITEM_STATE_ACTIVE);
								chick->SetPosition(x, y);
								listItem1.push_back(chick);
								break;
							case axeInside:
								axe1 = new Axe1();
								axe1->AddAnimation(427);
								axe1->SetState(ITEM_STATE_ACTIVE);
								axe1->SetPosition(x, y);
								listItem1.push_back(axe1);
							default:
								break;
							}

							listEnemy1.erase(listEnemy1.begin() + i);
							i = i-1;
						}
*/
void Scene2::CollisionBetWeaponAndEnemy()
{

	if (simon1->whip->isFinished == false && simon1->whip->isAllowedToCollide == true)
	{
		for (UINT i = 0; i < listEnemy1.size(); i++)
		{
			if (simon1->whip->CheckCollision(listEnemy1.at(i)) == true)
			{
				if (dynamic_cast<Enemy *>(listEnemy1.at(i)))
				{
						if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
						{
							float x, y;
							listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
							listEnemy1.at(i)->GetPosition(x, y);

							switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1 = new BigHeart();
								bigheart1->AddAnimation(765);
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								break;
							case morningstarInside:
								morningstar1 = new MorningStar();
								morningstar1->AddAnimation(777);
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								break;
							case daggerInside:
								dagger1 = new Dagger1();
								dagger1->AddAnimation(767);
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
							case crossInside:
								cross1 = new Cross1();
								cross1->AddAnimation(483);
								cross1->SetState(ITEM_STATE_ACTIVE);
								cross1->SetPosition(x, y);
								listItem1.push_back(cross1);
								break;
							case holywaterInside:
								holy1 = new HolyWater1();
								holy1->AddAnimation(491);
								holy1->SetState(ITEM_STATE_ACTIVE);
								holy1->SetPosition(x, y);
								listItem1.push_back(holy1);
								break;
							case whitebagInside:
								goldbag1 = new GoldBag(0);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case redbagInside:
								goldbag1 = new GoldBag(1);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case bluebagInside:
								goldbag1 = new GoldBag(2);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;

							case chickenInside:
								chick = new Chicken();
								chick->AddAnimation(490);
								chick->SetState(ITEM_STATE_ACTIVE);
								chick->SetPosition(x, y);
								listItem1.push_back(chick);
								break;
							case axeInside:
								axe1 = new Axe1();
								axe1->AddAnimation(427);
								axe1->SetState(ITEM_STATE_ACTIVE);
								axe1->SetPosition(x, y);
								listItem1.push_back(axe1);
							default:
								break;
							}

							listEnemy1.erase(listEnemy1.begin() + i);
							i = i-1;
						}
				}
			
			}
		}
		for (UINT i = 0; i < listTorches1.size(); i++)
		{

			if (simon1->whip->CheckCollision(listTorches1.at(i)) == true)
			{
				if (dynamic_cast<Torch *>(listTorches1.at(i)))
				{
					if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
					{
						float x, y;
						listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
						listTorches1.at(i)->GetPosition(x, y);

						switch (listEnemy1.at(i)->itemInside)
						{
						case 0:
							break;
						case bigheartInside:
							bigheart1 = new BigHeart();
							bigheart1->AddAnimation(765);
							bigheart1->SetState(ITEM_STATE_ACTIVE);
							bigheart1->SetPosition(x, y);
							listItem1.push_back(bigheart1);
							break;
						case morningstarInside:
							morningstar1 = new MorningStar();
							morningstar1->AddAnimation(777);
							morningstar1->SetState(ITEM_STATE_ACTIVE);
							morningstar1->SetPosition(x, y);
							listItem1.push_back(morningstar1);
							break;
						case daggerInside:
							dagger1 = new Dagger1();
							dagger1->AddAnimation(767);
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
						case crossInside:
							cross1 = new Cross1();
							cross1->AddAnimation(483);
							cross1->SetState(ITEM_STATE_ACTIVE);
							cross1->SetPosition(x, y);
							listItem1.push_back(cross1);
							break;
						case holywaterInside:
							holy1 = new HolyWater1();
							holy1->AddAnimation(491);
							holy1->SetState(ITEM_STATE_ACTIVE);
							holy1->SetPosition(x, y);
							listItem1.push_back(holy1);
							break;
						case whitebagInside:
							goldbag1 = new GoldBag(0);
							goldbag1->AddAnimation(778);
							goldbag1->AddAnimation(779);
							goldbag1->AddAnimation(780);
							goldbag1->SetState(ITEM_STATE_ACTIVE);
							goldbag1->SetPosition(x, y);
							listItem1.push_back(goldbag1);
							break;
						case redbagInside:
							goldbag1 = new GoldBag(1);
							goldbag1->AddAnimation(778);
							goldbag1->AddAnimation(779);
							goldbag1->AddAnimation(780);
							goldbag1->SetState(ITEM_STATE_ACTIVE);
							goldbag1->SetPosition(x, y);
							listItem1.push_back(goldbag1);
							break;
						case bluebagInside:
							goldbag1 = new GoldBag(2);
							goldbag1->AddAnimation(778);
							goldbag1->AddAnimation(779);
							goldbag1->AddAnimation(780);
							goldbag1->SetState(ITEM_STATE_ACTIVE);
							goldbag1->SetPosition(x, y);
							listItem1.push_back(goldbag1);
							break;

						case chickenInside:
							chick = new Chicken();
							chick->AddAnimation(490);
							chick->SetState(ITEM_STATE_ACTIVE);
							chick->SetPosition(x, y);
							listItem1.push_back(chick);
							break;
						case axeInside:
							axe1 = new Axe1();
							axe1->AddAnimation(427);
							axe1->SetState(ITEM_STATE_ACTIVE);
							axe1->SetPosition(x, y);
							listItem1.push_back(axe1);
						default:
							break;
						}

						listTorches1.erase(listTorches1.begin() + i);
						i = i - 1;
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
					if (dynamic_cast<Enemy *>(listEnemy1.at(i)))
					{
						simon1->notUseDagger();
						simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
						if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
						{
							float x, y;
							listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
							listEnemy1.at(i)->GetPosition(x, y);

							switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1 = new BigHeart();
								bigheart1->AddAnimation(765);
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								break;
							case morningstarInside:
								morningstar1 = new MorningStar();
								morningstar1->AddAnimation(777);
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								break;
							case daggerInside:
								dagger1 = new Dagger1();
								dagger1->AddAnimation(767);
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
							case crossInside:
								cross1 = new Cross1();
								cross1->AddAnimation(483);
								cross1->SetState(ITEM_STATE_ACTIVE);
								cross1->SetPosition(x, y);
								listItem1.push_back(cross1);
								break;
							case holywaterInside:
								holy1 = new HolyWater1();
								holy1->AddAnimation(491);
								holy1->SetState(ITEM_STATE_ACTIVE);
								holy1->SetPosition(x, y);
								listItem1.push_back(holy1);
								break;
							case whitebagInside:
								goldbag1 = new GoldBag(0);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case redbagInside:
								goldbag1 = new GoldBag(1);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case bluebagInside:
								goldbag1 = new GoldBag(2);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;

							case chickenInside:
								chick = new Chicken();
								chick->AddAnimation(490);
								chick->SetState(ITEM_STATE_ACTIVE);
								chick->SetPosition(x, y);
								listItem1.push_back(chick);
								break;
							case axeInside:
								axe1 = new Axe1();
								axe1->AddAnimation(427);
								axe1->SetState(ITEM_STATE_ACTIVE);
								axe1->SetPosition(x, y);
								listItem1.push_back(axe1);
							default:
								break;
							}

							listEnemy1.erase(listEnemy1.begin() + i);
							i = i - 1;
						}
					}

				}
			}
			for (UINT i = 0; i < listTorches1.size(); i++)
			{
				if (simon1->dagger->CheckCollision(listTorches1.at(i)) == true)
				{
					simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
					simon1->notUseDagger();
					if (dynamic_cast<Torch *>(listTorches1.at(i)))
					{
						if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
						{
							float x, y;
							listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
							listTorches1.at(i)->GetPosition(x, y);

							switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1 = new BigHeart();
								bigheart1->AddAnimation(765);
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								break;
							case morningstarInside:
								morningstar1 = new MorningStar();
								morningstar1->AddAnimation(777);
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								break;
							case daggerInside:
								dagger1 = new Dagger1();
								dagger1->AddAnimation(767);
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
							case crossInside:
								cross1 = new Cross1();
								cross1->AddAnimation(483);
								cross1->SetState(ITEM_STATE_ACTIVE);
								cross1->SetPosition(x, y);
								listItem1.push_back(cross1);
								break;
							case holywaterInside:
								holy1 = new HolyWater1();
								holy1->AddAnimation(491);
								holy1->SetState(ITEM_STATE_ACTIVE);
								holy1->SetPosition(x, y);
								listItem1.push_back(holy1);
								break;
							case whitebagInside:
								goldbag1 = new GoldBag(0);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case redbagInside:
								goldbag1 = new GoldBag(1);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case bluebagInside:
								goldbag1 = new GoldBag(2);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;

							case chickenInside:
								chick = new Chicken();
								chick->AddAnimation(490);
								chick->SetState(ITEM_STATE_ACTIVE);
								chick->SetPosition(x, y);
								listItem1.push_back(chick);
								break;
							case axeInside:
								axe1 = new Axe1();
								axe1->AddAnimation(427);
								axe1->SetState(ITEM_STATE_ACTIVE);
								axe1->SetPosition(x, y);
								listItem1.push_back(axe1);
							default:
								break;
							}

							listTorches1.erase(listTorches1.begin() + i);
							i = i - 1;
						}
					}
				}
			}


		}
		else
		if (simon1->axe->state != AXE_STATE_INACTIVE && simon1->axe->isOn == true && simon1->isUsingDagger == true)
		{
			for (UINT i = 0; i < listEnemy1.size(); i++)
			{
				if (simon1->axe->CheckCollision(listEnemy1.at(i)) == true)
				{
					if (dynamic_cast<Enemy *>(listEnemy1.at(i)))
					{
						simon1->axe->SetState(AXE_STATE_INACTIVE);
						simon1->notUseDagger();
						if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
						{
							float x, y;
							listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
							listEnemy1.at(i)->GetPosition(x, y);

							switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1 = new BigHeart();
								bigheart1->AddAnimation(765);
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								break;
							case morningstarInside:
								morningstar1 = new MorningStar();
								morningstar1->AddAnimation(777);
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								break;
							case daggerInside:
								dagger1 = new Dagger1();
								dagger1->AddAnimation(767);
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
							case crossInside:
								cross1 = new Cross1();
								cross1->AddAnimation(483);
								cross1->SetState(ITEM_STATE_ACTIVE);
								cross1->SetPosition(x, y);
								listItem1.push_back(cross1);
								break;
							case holywaterInside:
								holy1 = new HolyWater1();
								holy1->AddAnimation(491);
								holy1->SetState(ITEM_STATE_ACTIVE);
								holy1->SetPosition(x, y);
								listItem1.push_back(holy1);
								break;
							case whitebagInside:
								goldbag1 = new GoldBag(0);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case redbagInside:
								goldbag1 = new GoldBag(1);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case bluebagInside:
								goldbag1 = new GoldBag(2);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;

							case chickenInside:
								chick = new Chicken();
								chick->AddAnimation(490);
								chick->SetState(ITEM_STATE_ACTIVE);
								chick->SetPosition(x, y);
								listItem1.push_back(chick);
								break;
							case axeInside:
								axe1 = new Axe1();
								axe1->AddAnimation(427);
								axe1->SetState(ITEM_STATE_ACTIVE);
								axe1->SetPosition(x, y);
								listItem1.push_back(axe1);
							default:
								break;
							}

							listEnemy1.erase(listEnemy1.begin() + i);
							i = i - 1;
						}
					}

				}
			}
			for (UINT i = 0; i < listTorches1.size(); i++)
			{
				if (simon1->dagger->CheckCollision(listTorches1.at(i)) == true)
				{
					simon1->axe->SetState(AXE_STATE_INACTIVE);
					simon1->notUseDagger();
					if (dynamic_cast<Torch *>(listTorches1.at(i)))
					{
						if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
						{
							float x, y;
							listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
							listTorches1.at(i)->GetPosition(x, y);

							switch (listEnemy1.at(i)->itemInside)
							{
							case 0:
								break;
							case bigheartInside:
								bigheart1 = new BigHeart();
								bigheart1->AddAnimation(765);
								bigheart1->SetState(ITEM_STATE_ACTIVE);
								bigheart1->SetPosition(x, y);
								listItem1.push_back(bigheart1);
								break;
							case morningstarInside:
								morningstar1 = new MorningStar();
								morningstar1->AddAnimation(777);
								morningstar1->SetState(ITEM_STATE_ACTIVE);
								morningstar1->SetPosition(x, y);
								listItem1.push_back(morningstar1);
								break;
							case daggerInside:
								dagger1 = new Dagger1();
								dagger1->AddAnimation(767);
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
							case crossInside:
								cross1 = new Cross1();
								cross1->AddAnimation(483);
								cross1->SetState(ITEM_STATE_ACTIVE);
								cross1->SetPosition(x, y);
								listItem1.push_back(cross1);
								break;
							case holywaterInside:
								holy1 = new HolyWater1();
								holy1->AddAnimation(491);
								holy1->SetState(ITEM_STATE_ACTIVE);
								holy1->SetPosition(x, y);
								listItem1.push_back(holy1);
								break;
							case whitebagInside:
								goldbag1 = new GoldBag(0);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case redbagInside:
								goldbag1 = new GoldBag(1);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;
							case bluebagInside:
								goldbag1 = new GoldBag(2);
								goldbag1->AddAnimation(778);
								goldbag1->AddAnimation(779);
								goldbag1->AddAnimation(780);
								goldbag1->SetState(ITEM_STATE_ACTIVE);
								goldbag1->SetPosition(x, y);
								listItem1.push_back(goldbag1);
								break;

							case chickenInside:
								chick = new Chicken();
								chick->AddAnimation(490);
								chick->SetState(ITEM_STATE_ACTIVE);
								chick->SetPosition(x, y);
								listItem1.push_back(chick);
								break;
							case axeInside:
								axe1 = new Axe1();
								axe1->AddAnimation(427);
								axe1->SetState(ITEM_STATE_ACTIVE);
								axe1->SetPosition(x, y);
								listItem1.push_back(axe1);
							default:
								break;
							}

							listTorches1.erase(listTorches1.begin() + i);
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
							simon1->axe->turnOffAxe();
							simon1->clock->turnOffClock();
							simon1->holy->turnOffHolyWater();
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
							if (dynamic_cast<Ground *>(listItem1.at(i)))
							{
								if (listItem1.at(i)->state == INVIS_STATE_NEXT_LVL)
								{
									if (simon1->proceedToNextLevel == false)
										simon1->proceedToNextLevel = true;
									
										
								}
							}
							else

								if (dynamic_cast<GoldBag *>(listItem1.at(i)))
								{
									if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
									{
										OutputDebugString(L"GoldBag \n");
										listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
									}

								}
								else

									if (dynamic_cast<Cross1 *>(listItem1.at(i)))
									{
										if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
										{
											OutputDebugString(L"Cross \n");
											listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
											float xc, yc;
											xc=Camera::GetInstance()->GetPosition().x;
											yc= Camera::GetInstance()->GetPosition().y;
											for (UINT i = 0; i < listEnemy1.size(); i++)
											{
												if (listEnemy1.at(i)->x > xc &&
													listEnemy1.at(i)->x<xc + SCREEN_WIDTH &&
													listEnemy1.at(i)->y>yc &&
													listEnemy1.at(i)->y < yc + SCREEN_HEIGHT)
												{
													listEnemy1.at(i)->SetState(200);
													listEnemy1.erase(listEnemy1.begin() + i);
													i = i - 1; //Optional cuz simon only can hit 1 torch at one moment
												}
											}
										}

									}
									else
										if (dynamic_cast<Axe1 *>(listItem1.at(i)))
										{
											if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
											{
												OutputDebugString(L"Simon and Axe \n");
												listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
												simon1->dagger->turnOffDagger();
												simon1->axe->turnOnAxe();
												simon1->clock->turnOffClock();
												simon1->holy->turnOffHolyWater();
												OutputDebugString(L"Axe on \n");
											}
										}
										else
											if (dynamic_cast<HolyWater1 *>(listItem1.at(i)))
											{
												if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
												{
													OutputDebugString(L"Simon and HolyWater \n");
													listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
													simon1->dagger->turnOffDagger();
													simon1->axe->turnOffAxe();
													simon1->clock->turnOffClock();
													simon1->holy->turnOnHolyWater();
													OutputDebugString(L"HolyWater on \n");
												}

											}
											else
												if (dynamic_cast<Clock1 *>(listItem1.at(i)))
												{
													if (listItem1.at(i)->state == ITEM_STATE_ACTIVE)
													{
														OutputDebugString(L"Simon and Clock \n");
														listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
														simon1->dagger->turnOffDagger();
														simon1->axe->turnOffAxe();
														simon1->clock->turnOnClock();
														simon1->holy->turnOffHolyWater();
														OutputDebugString(L"Clock on \n");
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
			LPCOLLISIONEVENT e = simon1->SweptAABBEx(listEnemy1.at(i));
			{
				if (e->t > 0 && e->t <= 1.0f)
				{
					if (dynamic_cast<Enemy *>(listEnemy1.at(i)))
					{
						if (dynamic_cast<GroundEnemy *>(listEnemy1.at(i)))
						{
							//
						}
						else
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
									if (simon1->isOnStairs == true)
									{
										simon1->StartUntouchable();
									}
									else
									{
										simon1->SetState(SIMON_STATE_HURT_LEFT);

									}
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
										if (simon1->isOnStairs == true)
										{
											simon1->StartUntouchable();
										}
										else
										{
											simon1->SetState(SIMON_STATE_HURT_RIGHT);
										}


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
												if (simon1->isOnStairs == true)
												{
													simon1->StartUntouchable();
												}
												else
												{
													simon1->SetState(SIMON_STATE_HURT_LEFT);
												}
											}
											else
												if (x >= x1)
												{
													OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
													if (simon1->isUsingDagger == true)
														simon1->notUseDagger();
													if (simon1->whip->isFinished == false)
														simon1->whip->isFinished = true;

													if (simon1->isOnStairs == true)
													{
														simon1->StartUntouchable();
													}
													else
													{
														simon1->SetState(SIMON_STATE_HURT_RIGHT);
													}

												}
										}
									}
						if (dynamic_cast<Bat *>(listEnemy1.at(i)))
						{
							listEnemy1.at(i)->SetState(BAT_STATE_INACTIVE);
						}
					}
				}
				else
				{
					float al, at, ar, ab;
					float bl, bt, br, bb;
					listEnemy1.at(i)->GetBoundingBox(al, at, ar, ab);
					simon1->GetBoundingBox(bl, bt, br, bb);
					if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
					{
						if (dynamic_cast<GroundEnemy *>(listEnemy1.at(i)))
						{
							//
						}
						else
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
								if (simon1->isOnStairs == true)
								{
									simon1->StartUntouchable();
								}
								else
								{
									simon1->SetState(SIMON_STATE_HURT_LEFT);
								}
							}
							else
								if (x >= x1)
								{
									OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
									if (simon1->isUsingDagger == true)
										simon1->notUseDagger();
									if (simon1->whip->isFinished == false)
										simon1->whip->isFinished = true;
									if (simon1->isOnStairs == true)
									{
										simon1->StartUntouchable();
									}
									else
									{
										simon1->SetState(SIMON_STATE_HURT_RIGHT);
									}
								}
						}
				
						if (dynamic_cast<Bat *>(listEnemy1.at(i)))
						{
							listEnemy1.at(i)->SetState(BAT_STATE_INACTIVE);
						}
					}
				}
			}
		}
	}
	
}

int Scene2::CollisionBetSimonAndUpStairs()
{
	for (UINT i = 0; i < listUpStairs1.size(); i++)
	{

		float al, at, ar, ab;
		float bl, bt, br, bb;
		listUpStairs1.at(i)->GetBoundingBox(al, at, ar, ab);
		simon1->GetBoundingBox(bl, bt, br, bb);
		//1= right, 2 = left
		if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
		{
			if (simon1->isOnStairs == true)
			{
				simon1->SetPosition(simon1->x, simon1->y - 2);
				simon1->dy = 9999999999999999999;
				simon1->SetState(SIMON_STATE_IDLE);
				simon1->isOnStairs = false;
			}
			else
				if (simon1->isOnStairs == false)
				{
						if (simon1->x > listUpStairs1.at(i)->x + 5)
						{
							simon1->SetState(SIMON_STATE_WALKING_LEFT);
						}
						else
							if (simon1->x < listUpStairs1.at(i)->x + 3)
							{
								simon1->SetState(SIMON_STATE_WALKING_RIGHT);
							}
							else
								if (simon1->x >= listUpStairs1.at(i)->x + 3 ||
									simon1->x <= listUpStairs1.at(i)->x + 5)
								{
									if (listUpStairs1.at(i)->getType() == 1)
									{
										simon1->SetState(SIMON_STATE_DOWN_RIGHT);
										simon1->directionOnStairs = false;// true=going up, false=going down
									}
									else
										if (listUpStairs1.at(i)->getType() == 2)
										{
											simon1->SetState(SIMON_STATE_DOWN_LEFT);
											simon1->directionOnStairs = false;
										}
									simon1->isOnStairs = true;
									return true;
								}

						
				}
			return true;
		}
	}
	return false;

}

int Scene2::CollisionBetSimonAndDownStairs()
{
	for (UINT i = 0; i < listDownStairs1.size(); i++)
	{
		float al, at, ar, ab;
		float bl, bt, br, bb;
		listDownStairs1.at(i)->GetBoundingBox(al, at, ar, ab);
		simon1->GetBoundingBox(bl, bt, br, bb);
		//1= right, 2 = left	
		if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
		{
			if (simon1->isOnStairs == true)
			{
				simon1->isOnStairs = false;
			}
			else
				if (simon1->isOnStairs == false)
				{
					if (simon1->x > listDownStairs1.at(i)->x + 7)
					{
						simon1->SetState(SIMON_STATE_WALKING_LEFT);
					}
					else
						if (simon1->x < listDownStairs1.at(i)->x + 5)
						{
							simon1->SetState(SIMON_STATE_WALKING_RIGHT);
						}
						else
							if (simon1->x >= listDownStairs1.at(i)->x + 5 || simon1->x <= listDownStairs1.at(i)->x + 7)
							{
								if (listDownStairs1.at(i)->getType() == 1)
								{

									simon1->SetState(SIMON_STATE_UP_RIGHT);
									simon1->directionOnStairs = true;// true=going up, false=going down
								}
								else
									if (listDownStairs1.at(i)->getType() == 2)
									{
										simon1->SetState(SIMON_STATE_UP_LEFT);
										simon1->directionOnStairs = true;// true=going up, false=going down
									}
								simon1->isOnStairs = true;

					
							}
					return true;
				}
		}
	}
	return false;

}

