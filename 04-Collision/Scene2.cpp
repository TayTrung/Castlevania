#include "Scene2.h"
#include "Scene1.h"




void Scene2::KeyState(BYTE * states)
{
	
	if (simon1->proceedThruDoor == false)
	{
		if (simon1->whip->isFinished == true)
		{
			if (game1->IsKeyDown(DIK_RIGHT))
			{
				if (simon1->proceedThruDoor == false)
				{
					if (simon1->isOnStairs == false)
					{
						if (simon1->GetState() != SIMON_STATE_JUMP_RIGHT)
							if (simon1->isJumping == false)
							{

								if (game1->IsKeyDown(DIK_S))
									simon1->SetState(SIMON_STATE_ATTACK);
								else

									simon1->SetState(SIMON_STATE_WALKING_RIGHT);
							}

					}
					else
						if (simon1->isOnStairs == true)
						{
							if (simon1->directionOnStairs == true)
							{
								if (simon1->nx == 1)
								{
									if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
									{
										simon1->SetState(SIMON_STATE_UP_RIGHT);
									}

								}
								else
									if (simon1->nx == -1)
									{
										if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
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
										if (CollisionBetSimonAndDownStairs(listDownStairs1) == false)
										{
											simon1->SetState(SIMON_STATE_DOWN_RIGHT);
										}
									}
									else
										if (simon1->nx == -1)
										{
											if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
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
					if (simon1->proceedThruDoor == false)
					{
						if (simon1->isOnStairs == false)
						{
							if (simon1->GetState() != SIMON_STATE_JUMP_LEFT)
								if (simon1->isJumping == false)
								{
									if (game1->IsKeyDown(DIK_S))
										simon1->SetState(SIMON_STATE_ATTACK);
									else
										simon1->SetState(SIMON_STATE_WALKING_LEFT);

								}
							
						}
						else
							if (simon1->isOnStairs == true)
							{
								if (simon1->directionOnStairs == true)
								{

									if (simon1->nx == -1)
									{
										if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
										{
											simon1->SetState(SIMON_STATE_UP_LEFT);
										}
									}
									else
										if (simon1->nx == 1)
										{
											if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
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
											if (CollisionBetSimonAndDownStairs(listDownStairs1) == false)
											{

												simon1->SetState(SIMON_STATE_DOWN_LEFT);
											}
										}
										else
											if (simon1->nx == 1)
											{
												if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
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
						if (simon1->proceedThruDoor == false)
						{
							if (simon1->isOnStairs == false)
							{
								if (simon1->isJumping == false)
								{
									if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
									{
										simon1->SetState(SIMON_STATE_SIT);
									}
								}
							}
							else
								if (simon1->isOnStairs == true)
								{
									if (CollisionBetSimonAndDownStairs(listDownStairs1) == false)
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

							if (simon1->proceedThruDoor == false)
							{
								if (simon1->isOnStairs == false)
								{
									if (simon1->isJumping == false)
									{

										CollisionBetSimonAndDownStairs(listDownStairs1);
									}
								}
								else
									if (simon1->isOnStairs == true)
									{
										if (CollisionBetSimonAndUpStairs(listUpStairs1) == false)
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
												if (simon1->directionOnStairs == false)
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
								if (simon1->proceedThruDoor == false)
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
								if(simon1->isJumping==false)
								simon1->SetState(SIMON_STATE_IDLE);

							}
						}

		}
	}
	else
		simon1->SetState(SIMON_STATE_IDLE);
}


void Scene2::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_X:
		simon1->healthCount = 16;
	case DIK_1: //On dagger
		simon1->dagger->turnOnDagger();
		simon1->axe->turnOffAxe();
		simon1->holy->turnOffHolyWater();
		simon1->clock->turnOffClock();

		board->typeOfWeaopon = 1;
		break;
	case DIK_2://On Axe
		simon1->dagger->turnOffDagger();
		simon1->axe->turnOnAxe();
		simon1->holy->turnOffHolyWater();
		simon1->clock->turnOffClock();
		board->typeOfWeaopon = 2;
		break;
	case DIK_3://On HOly
		simon1->dagger->turnOffDagger();
		simon1->axe->turnOffAxe();
		simon1->holy->turnOnHolyWater();
		simon1->clock->turnOffClock();
		board->typeOfWeaopon = 3;
		break;
	case DIK_4://On Clock
		simon1->dagger->turnOffDagger();
		simon1->axe->turnOffAxe();
		simon1->holy->turnOffHolyWater();
		simon1->clock->turnOnClock();
		board->typeOfWeaopon = 4;
		break;
	case DIK_5:
		if (simon1->shotTwoWeaponOneTime == false)
			simon1->shotTwoWeaponOneTime = true;
		else
			simon1->shotTwoWeaponOneTime = false;
		break;
	case DIK_T:
		if (simon1->proceedThruDoor == false)
		{
			simon1->SetState(SIMON_STATE_IDLE);
			simon1->isOnStairs = false;
			simon1->SetPosition(2400, 0.0f);
			stage = 5;
			simon1->SetSpeed(0, 0);
			break;
		}
	case DIK_Y:
		if (simon1->proceedThruDoor == false)
		{
			simon1->SetState(SIMON_STATE_IDLE);
			simon1->isOnStairs = false;
			simon1->SetPosition(3238, 0.0f);
			stage = 3;
			simon1->SetSpeed(0, 0);
			break;
		}
	case DIK_U:
		if (simon1->proceedThruDoor == false)
		{
			simon1->SetState(SIMON_STATE_IDLE);
			simon1->isOnStairs = false;
			simon1->SetPosition(1690, 0.0f);
			stage = 2;
			simon1->SetSpeed(0, 0);
			break;
		}
		case DIK_J:
		{
			simon1->SetState(SIMON_STATE_DEAD);
			simon1->healthCount = 0;
		}
			
	case DIK_SPACE:
		if (simon1->proceedThruDoor == false)
		{
			if (simon1->isOnStairs == false)
			{

				if (simon1->isJumping == false)
				{
					if (simon1->GetState() == SIMON_STATE_WALKING_LEFT)
						simon1->SetState(SIMON_STATE_JUMP_LEFT);
					else
						if (simon1->GetState() == SIMON_STATE_WALKING_RIGHT)
							simon1->SetState(SIMON_STATE_JUMP_RIGHT);
						else
							simon1->SetState(SIMON_STATE_JUMP);
					simon1->isJumping = true;
				}
			}
		}
		break;
	case DIK_A: // reset
		if (simon1->proceedThruDoor == false)
		{
			simon1->SetState(SIMON_STATE_IDLE);
			simon1->isOnStairs = false;
			simon1->SetPosition(1460, 0.0f);
			simon1->SetSpeed(0, 0);
			break;
		}
		//case DIK_DOWNARROW:
		//	simon1->SetState(SIMON_STATE_SIT);
		//	break;
	case DIK_S:
		if (simon1->proceedThruDoor == false)
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
		if (simon1->proceedThruDoor == false)
	
		{
			if (simon1->dagger->isOn == true && //dagger
				simon1->axe->isOn==false &&
				simon1->holy->isOn == false &&
				simon1->clock->isOn == false)
			{
				if (simon1->heartCount > 0)
				{
				
					if (simon1->dagger->GetState() == DAGGER_STATE_INACTIVE)
					{

						simon1->heartCount -= 1;
						simon1->numOfWeapon = 1;
						float x, y;
						simon1->GetPosition(x, y);
						if (simon1->isOnStairs == true)
						{
							simon1->dagger->CreateWeapon(x, y, simon1->nx);
							if (simon1->isUsing1stWeapon == false)
							{
								if (simon1->nx > 0)
									simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
								else
									simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
								simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
								simon1->useWeapon();

							}
						}
						else
							if (simon1->GetState() == SIMON_STATE_SIT)
							{
								simon1->dagger->CreateWeapon(x, y + 7, simon1->nx);

								if (simon1->isUsing1stWeapon == false)
								{
									if (simon1->nx > 0)
										simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
									else
										simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW_SITTING);
									simon1->useWeapon();

								}

							}
							else
							{


								simon1->dagger->CreateWeapon(x, y, simon1->nx);

								if (simon1->isUsing1stWeapon == false)
								{
									if (simon1->nx > 0)
										simon1->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
									else
										simon1->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW);
									simon1->useWeapon();

								}

							}

					}
					else
						if(simon1->shotTwoWeaponOneTime==true)
						{
							if (simon1->dagger->isFinished == true)
							{
								simon1->numOfWeapon = 2;
								if (simon1->dagger1->GetState() == DAGGER_STATE_INACTIVE)
								{

									simon1->heartCount -= 1;
									float x, y;
									simon1->GetPosition(x, y);
									if (simon1->isOnStairs == true)
									{
										simon1->dagger1->CreateWeapon(x, y, simon1->nx);
										if (simon1->isUsing2ndWeapon == false)
										{
											if (simon1->nx > 0)
												simon1->dagger1->SetState(DAGGER_STATE_ACTIVE_RIGHT);
											else
												simon1->dagger1->SetState(DAGGER_STATE_ACTIVE_LEFT);
											simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
											simon1->useWeapon2();

										}
									}
									else
										if (simon1->GetState() == SIMON_STATE_SIT)
										{
											simon1->dagger1->CreateWeapon(x, y + 7, simon1->nx);

											if (simon1->isUsing2ndWeapon == false)
											{
												if (simon1->nx > 0)
													simon1->dagger1->SetState(DAGGER_STATE_ACTIVE_RIGHT);
												else
													simon1->dagger1->SetState(DAGGER_STATE_ACTIVE_LEFT);
												simon1->SetState(SIMON_STATE_THROW_SITTING);
												simon1->useWeapon2();

											}

										}
										else
										{


											simon1->dagger1->CreateWeapon(x, y, simon1->nx);

											if (simon1->isUsing2ndWeapon == false)
											{
												if (simon1->nx > 0)
													simon1->dagger1->SetState(DAGGER_STATE_ACTIVE_RIGHT);
												else
													simon1->dagger1->SetState(DAGGER_STATE_ACTIVE_LEFT);
												simon1->SetState(SIMON_STATE_THROW);
												simon1->useWeapon2();

											}

										}

								}

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
					if (simon1->heartCount > 0)
					{

						if (simon1->axe->GetState() == AXE_STATE_INACTIVE)
						{

							simon1->heartCount -= 1;
							simon1->numOfWeapon = 1;
							float x, y;
							simon1->GetPosition(x, y);
							if (simon1->isOnStairs == true)
							{
								simon1->axe->CreateWeapon(x, y, simon1->nx);
								if (simon1->isUsing1stWeapon == false)
								{
									if (simon1->nx > 0)
										simon1->axe->SetState(AXE_STATE_ACTIVE_RIGHT);
									else
										simon1->axe->SetState(AXE_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
									simon1->useWeapon();

								}
							}
							else
								if (simon1->GetState() == SIMON_STATE_SIT)
								{
									simon1->axe->CreateWeapon(x, y + 7, simon1->nx);

									if (simon1->isUsing1stWeapon == false)
									{
										if (simon1->nx > 0)
											simon1->axe->SetState(AXE_STATE_ACTIVE_RIGHT);
										else
											simon1->axe->SetState(AXE_STATE_ACTIVE_LEFT);
										simon1->SetState(SIMON_STATE_THROW_SITTING);
										simon1->useWeapon();

									}

								}
								else
								{


									simon1->axe->CreateWeapon(x, y, simon1->nx);

									if (simon1->isUsing1stWeapon == false)
									{
										if (simon1->nx > 0)
											simon1->axe->SetState(AXE_STATE_ACTIVE_RIGHT);
										else
											simon1->axe->SetState(AXE_STATE_ACTIVE_LEFT);
										simon1->SetState(SIMON_STATE_THROW);
										simon1->useWeapon();

									}

								}

						}
						else
							if (simon1->shotTwoWeaponOneTime == true)
							{
								if (simon1->axe->isFinished == true)
								{
									simon1->numOfWeapon = 2;
									if (simon1->axe1->GetState() == AXE_STATE_INACTIVE)
									{
										simon1->heartCount -= 1;
										float x, y;
										simon1->GetPosition(x, y);
										if (simon1->isOnStairs == true)
										{
											simon1->axe1->CreateWeapon(x, y, simon1->nx);
											if (simon1->isUsing2ndWeapon == false)
											{
												if (simon1->nx > 0)
													simon1->axe1->SetState(AXE_STATE_ACTIVE_RIGHT);
												else
													simon1->axe1->SetState(AXE_STATE_ACTIVE_LEFT);
												simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
												simon1->useWeapon2();

											}
										}
										else
											if (simon1->GetState() == SIMON_STATE_SIT)
											{
												simon1->axe1->CreateWeapon(x, y + 7, simon1->nx);

												if (simon1->isUsing2ndWeapon == false)
												{
													if (simon1->nx > 0)
														simon1->axe1->SetState(AXE_STATE_ACTIVE_RIGHT);
													else
														simon1->axe1->SetState(AXE_STATE_ACTIVE_LEFT);
													simon1->SetState(SIMON_STATE_THROW_SITTING);
													simon1->useWeapon2();

												}

											}
											else
											{


												simon1->axe1->CreateWeapon(x, y, simon1->nx);

												if (simon1->isUsing2ndWeapon == false)
												{
													if (simon1->nx > 0)
														simon1->axe1->SetState(AXE_STATE_ACTIVE_RIGHT);
													else
														simon1->axe1->SetState(AXE_STATE_ACTIVE_LEFT);
													simon1->SetState(SIMON_STATE_THROW);
													simon1->useWeapon2();

												}

											}

									}

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
						if (simon1->heartCount > 0)
						{

						if (simon1->holy->GetState() == HOLYWATER_STATE_INACTIVE)
						{

							simon1->heartCount -= 1;
							simon1->numOfWeapon = 1;
							float x, y;
							simon1->GetPosition(x, y);
							if (simon1->isOnStairs == true)
							{
								simon1->holy->CreateWeapon(x, y, simon1->nx);
								if (simon1->isUsing1stWeapon == false)
								{
									if (simon1->nx > 0)
										simon1->holy->SetState(HOLYWATER_STATE_ACTIVE_RIGHT);
									else
										simon1->holy->SetState(HOLYWATER_STATE_ACTIVE_LEFT);
									simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
									simon1->useWeapon();

								}
							}
							else
								if (simon1->GetState() == SIMON_STATE_SIT)
								{
									simon1->holy->CreateWeapon(x, y + 7, simon1->nx);

									if (simon1->isUsing1stWeapon == false)
									{
										if (simon1->nx > 0)
											simon1->holy->SetState(HOLYWATER_STATE_ACTIVE_RIGHT);
										else
											simon1->holy->SetState(HOLYWATER_STATE_ACTIVE_LEFT);
										simon1->SetState(SIMON_STATE_THROW_SITTING);
										simon1->useWeapon();

									}

								}
								else
								{
									simon1->holy->CreateWeapon(x, y, simon1->nx);

									if (simon1->isUsing1stWeapon == false)
									{
										if (simon1->nx > 0)
											simon1->holy->SetState(HOLYWATER_STATE_ACTIVE_RIGHT);
										else
											simon1->holy->SetState(HOLYWATER_STATE_ACTIVE_LEFT);
										simon1->SetState(SIMON_STATE_THROW);
										simon1->useWeapon();

									}

								}

						}
						else
							if (simon1->shotTwoWeaponOneTime == true)
							{
								if (simon1->holy1->isFinished == true)
								{
									simon1->numOfWeapon = 2;
									if (simon1->holy1->GetState() == HOLYWATER_STATE_INACTIVE)
									{
										simon1->heartCount -= 1;
										float x, y;
										simon1->GetPosition(x, y);
										if (simon1->isOnStairs == true)
										{
											simon1->holy1->CreateWeapon(x, y, simon1->nx);
											if (simon1->isUsing2ndWeapon == false)
											{
												if (simon1->nx > 0)
													simon1->holy1->SetState(HOLYWATER_STATE_ACTIVE_RIGHT);
												else						
													simon1->holy1->SetState(HOLYWATER_STATE_ACTIVE_LEFT);
												simon1->SetState(SIMON_STATE_THROW_ON_STAIRS);
												simon1->useWeapon2();

											}
										}
										else
											if (simon1->GetState() == SIMON_STATE_SIT)
											{
												simon1->holy1->CreateWeapon(x, y + 7, simon1->nx);

												if (simon1->isUsing2ndWeapon == false)
												{
													if (simon1->nx > 0)
														simon1->holy1->SetState(HOLYWATER_STATE_ACTIVE_RIGHT);
													else					
														simon1->holy1->SetState(HOLYWATER_STATE_ACTIVE_LEFT);
													simon1->SetState(SIMON_STATE_THROW_SITTING);
													simon1->useWeapon2();

												}

											}
											else
											{


												simon1->holy1->CreateWeapon(x, y, simon1->nx);

												if (simon1->isUsing2ndWeapon == false)
												{
													if (simon1->nx > 0)
														simon1->holy1->SetState(HOLYWATER_STATE_ACTIVE_RIGHT);
													else
														simon1->holy1->SetState(HOLYWATER_STATE_ACTIVE_LEFT);
													simon1->SetState(SIMON_STATE_THROW);
													simon1->useWeapon2();

												}

											}

									}

								}

							}
						}
					}
					else
						if (simon1->dagger->isOn == false && //clock
							simon1->axe->isOn == false &&
							simon1->holy->isOn == false &&
							simon1->clock->isOn == true)
						{
							if (simon1->heartCount > 4)
							{

								simon1->heartCount -= 5;
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
		}
		break;
	case DIK_Z:

		spawnGhou(300 /*SCREEN_WIDTH*/, 50,GHOU_STATE_ACTIVE_RIGHT);
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
	
	readTextureFromFileTxt("textures\\Textures2.txt");
	camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
	/*textures->Add(ID_TEX_MAP2,				"textures\\Map\\Map2.png",			D3DCOLOR_XRGB(5,	5,		5));
	textures->Add(ID_TEX_GROUND,			"textures\\Ground\\ground2.png",	D3DCOLOR_XRGB(176,	224,	248));
	textures->Add(ID_TEX_DOOR,				"textures\\Ground\\Gate1.png",		D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_ITEM_SMALLHEART,	"textures\\Item\\smallheart.png",	D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_ITEM_CROSS,		"textures\\Item\\cross.png",		D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_ITEM_CHICKEN,		"textures\\Item\\10.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_ITEM_AXE,			"textures\\Item\\7.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_ITEM_NUMBAH,		"textures\\Item\\11.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_ITEM_POTION,		"textures\\Item\\potion.png",		D3DCOLOR_XRGB(0,	0,		0));
	textures->Add(ID_TEX_ITEM_HEAL,			"textures\\Item\\13.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_GHOUL,				"textures\\Enemy\\Ghoul.png",		D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_BAT,				"textures\\Enemy\\Bat.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_PANTHER,			"textures\\Enemy\\Pant.png",		D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_CANDLE,			"textures\\Enemy\\1.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_MONSTER,			"textures\\Enemy\\3.png",			D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_FIREBALL,			"textures\\Enemy\\fireball.png",	D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_BOSS,				"textures\\Enemy\\boss.png",		D3DCOLOR_XRGB(255,	0,		255));
	textures->Add(ID_TEX_GROUND3,			"textures\\Ground\\ground3.png",	D3DCOLOR_XRGB(176,	224,	248));
	textures->Add(ID_TEX_GROUND4,			"textures\\Ground\\ground4.png",	D3DCOLOR_XRGB(176,	224,	248));
	textures->Add(ID_TEX_GROUND2,			"textures\\Ground\\ground2.png",	D3DCOLOR_XRGB(176,	224,	248));*/
	
	map1 = new Map(ID_TEX_MAP2, "textures\\Map\\Map2.csv");

	texGround	= textures->Get(ID_TEX_GROUND);
	texGround2	= textures->Get(ID_TEX_GROUND2);
	texGround3	= textures->Get(ID_TEX_GROUND3);
	texGround4	= textures->Get(ID_TEX_GROUND4);
	texHeal		= textures->Get(ID_TEX_ITEM_HEAL);
	texCandle	= textures->Get(ID_TEX_CANDLE);
	texDoor		= textures->Get(ID_TEX_DOOR);
	texBat		= textures->Get(ID_TEX_BAT);
	texBoss		= textures->Get(ID_TEX_BOSS);
	texGhoul	= textures->Get(ID_TEX_GHOUL);
	texPant		= textures->Get(ID_TEX_PANTHER);
	texMonster	= textures->Get(ID_TEX_MONSTER);
	texFire		= textures->Get(ID_TEX_FIREBALL);
	texSHeart	= textures->Get(ID_TEX_ITEM_SMALLHEART);
	texHoly		= textures->Get(ID_TEX_ITEM_HOLY);
	texPotion	= textures->Get(ID_TEX_ITEM_POTION);
	texNum		= textures->Get(ID_TEX_ITEM_NUMBAH);
	texAxe		= textures->Get(ID_TEX_ITEM_AXE);
	texCross	= textures->Get(ID_TEX_ITEM_CROSS);
	texChicken	= textures->Get(ID_TEX_ITEM_CHICKEN);

	//sprites->Add(20001, 0, 0, 16, 16,	texGround);
	//sprites->Add(20004, 0, 0, 16, 16,	texGround);
	//sprites->Add(20002, 0, 0, 16, 16,	texGround3);
	//sprites->Add(20003, 0, 0, 16, 16,	texGround4);
	//sprites->Add(25554, 0, 0, 13, 15,	texHeal);
	//sprites->Add(25555, 14, 0, 27, 15,	texHeal); 
	//sprites->Add(40001, 0, 0, 7, 15,	texCandle);
	//sprites->Add(40002, 8, 0, 15, 15,	texCandle);
	//sprites->Add(40011, 1, 0, 8, 47,	texDoor);
	//sprites->Add(40012, 48, 0, 87, 47,	texDoor);
	//sprites->Add(22300, 48, 0, 63, 15,	texBat);// left side
	//sprites->Add(22301, 32, 0, 47, 15,	texBat);
	//sprites->Add(22302, 16, 0, 31, 15,	texBat);
	//sprites->Add(22303, 0, 16, 15, 31,	texBat);// right side
	//sprites->Add(22304, 16, 16, 31, 31, texBat);
	//sprites->Add(22305, 32, 16, 47, 31, texBat);
	//sprites->Add(26540, 0, 0, 47, 22,	texBoss);
	//sprites->Add(26541, 48, 0, 95, 22,	texBoss);
	//sprites->Add(26542, 96, 0, 143, 22, texBoss);
	//sprites->Add(22220, 0, 0, 15, 31,	texGhoul); //right
	//sprites->Add(22221, 18, 0, 33, 31,	texGhoul);
	//sprites->Add(22222, 0, 32, 15, 63,	texGhoul);	//left
	//sprites->Add(22223, 18, 32, 33, 63, texGhoul);
	//sprites->Add(60000, 64, 18, 95, 33, texPant);	//run right
	//sprites->Add(60001, 32, 18, 63, 33, texPant);
	//sprites->Add(60010, 32, 0, 63, 15,	texPant);	//run left
	//sprites->Add(60011, 64, 0, 95, 15,	texPant);
	//sprites->Add(60002, 96, 18, 127, 33,texPant);	//sit right
	//sprites->Add(60012, 0, 0, 31, 15,	texPant);		//sit left
	//sprites->Add(60003, 0, 18, 31, 33,	texPant);	//jump right
	//sprites->Add(60013, 96, 0, 127, 15, texPant);		//jump left
	//sprites->Add(85555, 0, 0, 15, 31,	texMonster);	//att left
	//sprites->Add(85556, 32, 32, 47, 63, texMonster); //att right
	//sprites->Add(85557, 16, 0, 31, 31,	texMonster);
	//sprites->Add(85558, 32, 0, 47, 31,	texMonster);
	//sprites->Add(85559, 16, 32, 31, 63, texMonster);
	//sprites->Add(85560, 0, 32, 15, 63,	texMonster);
	//sprites->Add(86666, 0, 0, 6, 5,		texFire);	//left
	//sprites->Add(86667, 0, 6, 6, 11, texFire); //right
	//sprites->Add(23330, 0, 0, 8, 8, texSHeart);
	//sprites->Add(23041, 0, 0, 15, 15,	texHoly);
	//sprites->Add(25471, 290, 102, 302,  texPotion);
	//sprites->Add(48954, 0, 0, 13, 15,	texNum);
	//sprites->Add(23641, 0, 0, 14, 13,	texAxe);
	//sprites->Add(23042, 0, 0, 15, 15,	texCross);
	//sprites->Add(23331, 0, 0, 15, 12,	texChicken);
	readCoordiantionsForSpritesFromFileTxt("textures\\Coordinations2.txt");

	createAnimationsFromFileTxt("textures\\CreateAnimations2.txt");
	fire->AddAnimation(899);
	fire->AddAnimation(900);
	
	boss->AddAnimation(333);
	boss->AddAnimation(334);

	boss->SetPosition(2660, 5 + offsetMap);
	boss->setItemInside(healInside);
	boss->SetState(BOSS_STATE_SLEEP);

	effectBag1->AddAnimation(579);
	effectBag1->AddAnimation(580);
	effectBag1->AddAnimation(581);
	effectBag1->AddAnimation(582);
//	
//
//	// ground neen
//	Ground *ground = new Ground(1, BRICKMAP21_BBOX_WIDTH + BRICKMAP22_BBOX_WIDTH + BRICKMAP23_BBOX_WIDTH + 32);
//	ground->SetPosition(0, offsetMap + 160);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//	
//	//Stage 1
//	//3 ground len cau thang 
//
//	ground = new Ground(1, 3 * 16);
//	ground->SetPosition(688, offsetMap + 160 - 16 * 4);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 10 * 16);
//	ground->SetPosition(688 + 4 * 16, offsetMap + 160 - 16 * 6);
//	newGrid1->insertObjectIntoGrid(ground);
//	//listSurface1.push_back(ground);
//
//
//	ground = new Ground(1, 6 * 16);
//	ground->SetPosition(688 + 15 * 16, offsetMap + 160 - 16 * 4);
//	newGrid1->insertObjectIntoGrid(ground);
//	//listSurface1.push_back(ground);
//	
//	//Box proceed to open door
//	ground = new Ground(0, 0);
//	ground->SetState(INVIS_STATE_OPENDOOR);
//	ground->SetPosition(1520, offsetMap + 43);
//	newGrid1->insertObjectIntoGrid(ground);
//	//listItem1.push_back(ground);
//
//	//Door
//	door = new Door();
//	door->SetState(DOOR_STATE_ACTIVE_CLOSED);
//	door->AddAnimation(495);
//	door->AddAnimation(496);
//	door->SetPosition(1528, offsetMap + 16);
//	//listSurface1.push_back(door);
//	newGrid1->insertObjectIntoGrid(door);
//	//listCheckBox1.push_back(door);
//	//Stage 2
//	//2 mieng ground chicken
//	groundEnemy = new GroundEnemy();
//	groundEnemy->AddAnimation(998);
//	groundEnemy->SetPosition(1792, offsetMap + 128);
//	groundEnemy->SetState(ITEM_STATE_ACTIVE);
//	//listEnemy1.push_back(groundEnemy);
//	newGrid1->insertObjectIntoGrid(groundEnemy);
//
//	groundEnemy = new GroundEnemy();
//	groundEnemy->AddAnimation(997);
//	groundEnemy->setItemInside(chickenInside);
//	groundEnemy->SetPosition(1792, offsetMap + 128+16);
//	groundEnemy->SetState(ITEM_STATE_ACTIVE);
//	//listEnemy1.push_back(groundEnemy);
//	newGrid1->insertObjectIntoGrid(groundEnemy);
//
//
//	//2 ground man 2
//
//	ground = new Ground(1, 17 * 16);
//	ground->SetPosition(1392, offsetMap + 160 - 16 * 6);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 3 * 16);
//	ground->SetPosition(1392+17*16, offsetMap + 160 - 16 * 4);
//	newGrid1->insertObjectIntoGrid(ground);
//	//listSurface1.push_back(ground);
//	
//
//
//	//box proceed to level underground
//
//	ground = new Ground(0, 0);
//	ground->SetState(INVIS_STATE_NEXT_LVL_UNDERGROUND);
//	ground->SetPosition(1616, 184+55);
//	//listItem1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//Stage 3
//	//box to get out of level underground
//	ground = new Ground(0, 0);
//	ground->SetState(INVIS_STATE_UPPERGROUND);
	//ground->SetPosition(3192, offsetMap -5);
//	//listItem1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//box to get to stage 2
//	ground = new Ground(0, 0);
//	ground->SetState(INVIS_STATE_STAGE2);
//	ground->SetPosition(3192-320, offsetMap - 5);
//	//listItem1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//	
//	ground = new Ground(0, 335);
//	ground->SetState(INVIS_STATE_DIE_BOX);
//	ground->SetPosition(2990, offsetMap+170);
//	//listItem1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//2910 47
//	//Mieng ground 2 in UNderGround
//	ground = new Ground(1, 16 * 2);
//	ground->SetPosition(2910, offsetMap + 47);
//	listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//MIeng to duoi chan
//	ground = new Ground(1, 16*14);
//	ground->SetPosition(2910-16*6, offsetMap + 47+16*2);
//	//listSurface1.push_back(ground);
//	//listSurfaceUnderGround.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	// Mieng 2 ke ben
//	ground = new Ground(1, 16 * 2);
//	ground->SetPosition(2910 - 16 * 6+16*16, offsetMap + 47 + 16 * 2);
//	//listSurface1.push_back(ground);
//	//listSurfaceUnderGround.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//Mieng 10
//	ground = new Ground(1, 16 * 9);
//	ground->SetPosition(2910 - 16 * 6 + 16 * 20, offsetMap + 47 + 16 * 2);
//	//listSurface1.push_back(ground);
//	//listSurfaceUnderGround.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//Mieng 2
//	ground = new Ground(1, 16 * 2);
//	ground->SetPosition(2910 - 16 * 6 + 16 * 30, offsetMap + 47 + 16 * 4);
//	//listSurface1.push_back(ground);
//	//listSurfaceUnderGround.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//Mieng 2 o duoi cung
//	ground = new Ground(1, 16 * 2);
//	ground->SetPosition(2910 - 16 * 8 + 16 * 30, offsetMap + 47 + 16 * 6);
//	//listSurface1.push_back(ground);
//	//listSurfaceUnderGround.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//1 mieng ground No ITem
//	groundEnemy1 = new GroundEnemy();
//	groundEnemy1->AddAnimation(996);
//	groundEnemy1->SetPosition(2910 - 16 * 7 + 16 * 30, offsetMap + 47 + 16 * 2);
//	groundEnemy1->SetState(ITEM_STATE_ACTIVE);
//	newGrid1->insertObjectIntoGrid(groundEnemy1);
//	//listEnemy1.push_back(groundEnemy1);
//	//listSurface1.push_back(groundEnemy1);
//	//listSurfaceUnderGround.push_back(groundEnemy1);
//
//	//Stage 4
//
//	//box proceed to level underground
//
//	ground = new Ground(0, 0);
//	ground->SetState(INVIS_STATE_NEXT_LVL_UNDERGROUND);
//	ground->SetPosition(1937, 184 + 55);
//	//listItem1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 3 * 16);
//	ground->SetPosition(1888, offsetMap + 160 - 16 * 4);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 6 * 16);
//	ground->SetPosition(1792, offsetMap + 160 - 16 * 5);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 13 * 16);
//	ground->SetPosition(1952, offsetMap + 160 - 16 * 6);
////	listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//
//	//Stage 5
//
//	//Box proceed to open door
//	ground = new Ground(0, 0);
//	ground->SetState(INVIS_STATE_OPENDOOR2);
//	ground->SetPosition(1520 + 514, offsetMap + 43);
//	//listItem1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//Door
//	door1 = new Door();
//	door1->SetState(DOOR_STATE_ACTIVE_CLOSED);
//	door1->AddAnimation(495);
//	door1->AddAnimation(496);
//	door1->SetPosition(1528 + 514, offsetMap + 16);
//	//listSurface1.push_back(door1);
//	newGrid1->insertObjectIntoGrid(door1);
//
//	ground = new Ground(1, 11 * 16);
//	ground->SetPosition(2176, offsetMap + 160 - 16 * 4);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 3 * 16);
//	ground->SetPosition(2768, offsetMap + 160 - 16 * 4);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	ground = new Ground(1, 1 * 16);
//	ground->SetPosition(2720, offsetMap + 160 - 16 * 2);
//	//listSurface1.push_back(ground);
//	newGrid1->insertObjectIntoGrid(ground);
//
//	//1 mieng ground item 2nd
//	groundEnemy1 = new GroundEnemy();
//	groundEnemy1->AddAnimation(996);
//	groundEnemy1->setItemInside(numbahInside);
//	groundEnemy1->SetPosition(2735, offsetMap + 128);
//	groundEnemy1->SetState(ITEM_STATE_ACTIVE);
//
//	newGrid1->insertObjectIntoGrid(groundEnemy1);
//	//listEnemy1.push_back(groundEnemy1);
//	//listSurface1.push_back(groundEnemy1);
//
//#pragma endregion
//
//
//#pragma region Adding Stairs
//		//1=right , 2 = left
//		////1st stair
//		stairs = new Stairs(1,true);
//		stairs->SetPosition(611, offsetMap + 159);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2,false);
//		stairs->SetPosition(675, offsetMap + 35);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		//2nd stair
//		stairs = new Stairs(1, true);
//		stairs->SetPosition(707, offsetMap + 95);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, false);
//		stairs->SetPosition(752-14, offsetMap + 4);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//		//1= right, 2 = left
//		////3rd stair
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(878+20, offsetMap + 4);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(928, offsetMap + 95);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		//4th stair
//		stairs = new Stairs(1, true);
//		stairs->SetPosition(1283, offsetMap + 159);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, false);
//		stairs->SetPosition(1392-14, offsetMap + 4);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		//5th stair
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(1698,  offsetMap + 35);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//		//offsetMap + 160 - 16 * 4
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(1762, offsetMap + 159);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		//Stairs  to underwater
//
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(1698-8*16, offsetMap + 99);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//		
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(2910-16, offsetMap + 46);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		//stairs out underwater
//
//	
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(1888, offsetMap + 99);
//	//	listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(2914 - 16 * 6 + 16 * 27, offsetMap + 46 + 16 * 2);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//
//		//stairs stage 4
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(1924, offsetMap + 35);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(1986, offsetMap +159);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//
//		//stirs stage 5
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(2148, offsetMap + 160 - 16 * 6-61);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(2180, offsetMap + 159- 16 * 4);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//		
//
//		stairs = new Stairs(1, false);
//		stairs->SetPosition(2340, offsetMap + 160 - 16 * 4 - 61);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, true);
//		stairs->SetPosition(2404, offsetMap + 159);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(2, false);
//		stairs->SetPosition(2769-16, offsetMap + 160 - 16 * 4 - 61);
//		//listUpStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//
//		stairs = new Stairs(1, true);
//		stairs->SetPosition(2720, offsetMap + 159-16*2);
//		//listDownStairs1.push_back(stairs);
//		newGrid1->insertObjectIntoGrid(stairs);
//#pragma endregion

newGrid1->readObjectFromTextFile( "textures\\Objects2.txt");
}
void Scene2::XuLyPanthera()
{
	for (int i = 0; i < listPanther.size(); i++)
	{

		{
			
			if (abs(listPanther.at(i)->x - simon1->x) > 16 * 4 && abs(listPanther.at(i)->x - simon1->x) < 16 * 4 + 5)
			{
				if (listPanther.at(i)->changeDirection == false)
				{

					if (listPanther.at(i)->GetState() == PANTHER_STATE_SIT_LEFT)
						listPanther.at(i)->SetState(PANTHER_STATE_ACTIVE_LEFT);
					if (listPanther.at(i)->GetState() == PANTHER_STATE_SIT_RIGHT)
						listPanther.at(i)->SetState(PANTHER_STATE_ACTIVE_RIGHT);

				}
			}
			
			if (listPanther.at(i)->jumped == true)
			{
				if (listPanther.at(i)->GetState() == PANTHER_STATE_ACTIVE_RIGHT ||
					listPanther.at(i)->GetState() == PANTHER_STATE_ACTIVE_LEFT)
				{
					if (listPanther.at(i)->changeDirection == false)

					{
						listPanther.at(i)->changeDirection = true;
						if ((listPanther.at(i)->x - simon1->x) > 0)
						{
							listPanther.at(i)->SetState(PANTHER_STATE_ACTIVE_LEFT);
						}
						else
							if ((listPanther.at(i)->x - simon1->x) < 0)
							{
								listPanther.at(i)->SetState(PANTHER_STATE_ACTIVE_RIGHT);
							}
					}

				}
			}
		}


	}
}



void Scene2::spawnMonster()
{
	DWORD tickTime = GetTickCount();
	if (tickTime % 2==1)
		monster1 = new Monster(simon1->x - 16 * 5);
	else
		monster1 = new Monster(simon1->x + 16 * 5);
	monster1->AddAnimation(846);
	monster1->AddAnimation(845);
	monster1->AddAnimation(847);
	monster1->AddAnimation(848);
	monster1->AddAnimation(849);
	monster1->AddAnimation(850);
	monster1->AddAnimation(849);
	monster1->AddAnimation(847);
	monster1->AddAnimation(848);
	monster1->setItemInside(randomIteminside());
	monster1->SetState(MONSTER_STATE_UNDERWATER);

	effectFire1 = new EffectFire();
	effectFire1->AddAnimation(578);
	effectFire1->AddAnimation(577);
	effectFire1->AddAnimation(576);
	effectFire1->SetState(EFFECT_STATE_ACTIVE);
	effectFire1->itemInside = 0;
	effectFire1->type = 2;
	if (tickTime % 2 == 1)
	{
		monster1->SetPosition(simon1->x - 16 * 5, offsetMap + 150);
	}
	else
	{
		monster1->SetPosition(simon1->x + 16 * 5, offsetMap + 150);
	}

	effectFire1->SetPosition(monster1->x, monster1->y);
	if (monster1->x - simon1->x > 0)
		monster1->nx = -1;
	else
		monster1->nx = 1;

	listEffectFire1.push_back(effectFire1);
	listEnemy1.push_back(monster1);
}

void Scene2::spawnPanther()
{
#pragma region spawnPanther
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
	
	pant->SetPosition(685, 0 + offsetMap);
	if (simon1->x < pant->x)
		pant->SetState(PANTHER_STATE_SIT_LEFT);
	else
		pant->SetState(PANTHER_STATE_SIT_RIGHT);
	listPanther.push_back(pant);
	
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
	pant->SetPosition(880, 0 + offsetMap);

	if (simon1->x < pant->x)
		pant->SetState(PANTHER_STATE_SIT_LEFT);
	else
		pant->SetState(PANTHER_STATE_SIT_RIGHT);
	listPanther.push_back(pant);
	
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
	pant->SetPosition(945, 0 + offsetMap);

	if (simon1->x < pant->x)
		pant->SetState(PANTHER_STATE_SIT_LEFT);
	else
		pant->SetState(PANTHER_STATE_SIT_RIGHT);
	listPanther.push_back(pant);
	


#pragma endregion
}

void Scene2::TinhDiem()
{
	
	{
		if (time1->x != 0)
		{
			time1->x -= 1;
			simon1->score += 100;
		}
		else
			if (simon1->heartCount != 0)
			{
				simon1->heartCount -= 1;
				simon1->score += 1000;
			}
	}
}

void Scene2::spawnFireBall()
{
	if (stage == 3)
	{
		for (UINT i = 0; i < listEnemy1.size(); i++)
		{
			if (dynamic_cast<Monster *>(listEnemy1.at(i)))
			{
				if (listEnemy1.at(i)->GetState() == MONSTER_STATE_FIRE_LEFT)
				{
					if (listEnemy1.at(i)->spawnFireBall == false)
					{
						listEnemy1.at(i)->spawnFireBall = true;
						fire = new FireBall();
						fire->AddAnimation(899);
						fire->AddAnimation(900);
						fire->SetState(FIREBALL_STATE_ACTIVE_LEFT);
						fire->SetPosition(listEnemy1.at(i)->x, listEnemy1.at(i)->y + 5);
						listEnemy1.push_back(fire);
					}
				}
				else
					if (listEnemy1.at(i)->GetState() == MONSTER_STATE_FIRE_RIGHT)
					{
						if (listEnemy1.at(i)->spawnFireBall == false)
						{
							listEnemy1.at(i)->spawnFireBall = true;
							fire = new FireBall();
							fire->AddAnimation(899);
							fire->AddAnimation(900);
							fire->SetState(FIREBALL_STATE_ACTIVE_RIGHT);
							fire->SetPosition(listEnemy1.at(i)->x, listEnemy1.at(i)->y);
							listEnemy1.push_back(fire);
						}
					}

			}
		}

	}
	else
		if (stage == 5)
		{
			if (bossOn == true)
			{
				if (boss->GetState() == BOSS_STATE_AFK)
				{
					if (boss->fired == false)
					{
						fire = new FireBall();
						fire->AddAnimation(899);
						fire->AddAnimation(900);
						fire->SetState(FIREBALL_STATE_ACTIVE_LEFT);
						float x1, y1;
						x1 = (simon1->x-boss->x);
						y1 = abs(simon1->y - boss->y);
						fire->vx = x1 / 1000;
						fire->vy = y1 / 1000;
						fire->SetPosition(boss->x + 24, boss->y + 23);
						listEnemy1.push_back(fire);
						boss->fired = true;
					}	
				}
			}
		}
}


void Scene2::Update(DWORD dt)
{

	if (time1->x == 0)
		simon1->healthCount = 0;
	if (simon1->healthCount <= 0)
	{
			TimeWaitToRefresh += dt;
			if (TimeWaitToRefresh >= SIMON_REFRESH_TIME)
			{
				if (simon1->playerLife > 0)
				{
					simon1->playerLife -= 1;
					simon1->CGameObject::SetState(SIMON_STATE_IDLE);
					simon1->healthCount = 16;
					simon1->whip->type = 1;
					simon1->heartCount = 10;
					simon1->isOnStairs = false;
					simon1->dagger->turnOffDagger();
					simon1->axe->turnOffAxe();
					simon1->clock->turnOffClock();
					simon1->holy->turnOffHolyWater();
					board->typeOfWeaopon = 0;
					if (stage == 1)
					{
						simon1->SetPosition(50, 0);
						time1->x = 300;
					}
					else
						if (stage == 2)
						{
							simon1->SetPosition(1550, 0);
							time1->x = 300;

						}
						else
							if ((stage == 3) || (stage == 4))
							{
								stage = 3;
								simon1->SetPosition(2917, 0);
								time1->x = 300;
							}
							else
								if (stage == 5)
								{
									simon1->SetPosition(2062, 0);
									time1->x = 300;
									bossOn = false;
									boss = new Boss();
									boss->AddAnimation(333);
									boss->AddAnimation(334);
									boss->SetPosition(2660, 5 + offsetMap);
									boss->setItemInside(bluebagInside);
									boss->SetState(BOSS_STATE_SLEEP);
								}
				}
				TimeWaitToRefresh = 0;
			}	
	}
	if (simon1->healthCount > 0)
		time1->Update(dt);
	newGrid1->getListOfObjects(listColliableObjects1, camera1);

	DebugOut(L"[INFO] Number of Objects: %d\n", listColliableObjects1.size());
	listCheckBox1.clear();
	listSurface1.clear();
	listUpStairs1.clear();
	listDownStairs1.clear();
	listTorches1.clear(); 
	//listPanther.clear();
	listGroundEnemy.clear();
	listDoor.clear();
	for (int i = 0; i < listColliableObjects1.size(); i++)
	{
			if (listColliableObjects1.at(i)->tag == eTag::TORCHES)
			{

				Torch *tor = dynamic_cast<Torch *>(listColliableObjects1.at(i));
				listTorches1.push_back(tor);
			
			}
			else
				if (listColliableObjects1.at(i)->tag == eTag::PANT)
				{
					Panther *pant = dynamic_cast<Panther *>(listColliableObjects1.at(i));
					listPanther.push_back(pant);
				}
				else
					if (listColliableObjects1.at(i)->tag == eTag::CHECK_BOX)
					{
						listCheckBox1.push_back(listColliableObjects1.at(i));
					}
					else
						if (listColliableObjects1.at(i)->tag == eTag::GROUND)
					{
							if(listColliableObjects1.at(i)->GetState()==GROUND_STATE_ACTIVE)
							listSurface1.push_back(listColliableObjects1.at(i));
					}
				else
					if (listColliableObjects1.at(i)->tag == eTag::GROUND_ENEMY)
					{
						GroundEnemy *ge = dynamic_cast<GroundEnemy *>(listColliableObjects1.at(i));
						listGroundEnemy.push_back(ge);
					}
					else
						if (listColliableObjects1.at(i)->tag == eTag::STAIR_BOT)
						{
							Stairs *newStair = dynamic_cast<Stairs *>(listColliableObjects1.at(i));
							listDownStairs1.push_back(newStair);
						}
						else
							if (listColliableObjects1.at(i)->tag == eTag::STAIR_TOP)
							{
								Stairs *newStair = dynamic_cast<Stairs *>(listColliableObjects1.at(i));
								listUpStairs1.push_back(newStair);
							}
							else
								if (listColliableObjects1.at(i)->tag == eTag::DOOR)
								{

									listDoor.push_back(listColliableObjects1.at(i));
								}
	}

	if (simon1->shotTwoWeaponOneTime == true)
	{
		board->simonHasNumbah = true;
	}
	board->heartCount = simon1->heartCount;
	board->healthCount = simon1->healthCount;
	board->playerLife = simon1->playerLife;
	board->stage = simon1->stage;
	board->score = simon1->score;
	board->bossHealth = boss->hp;
	board->time = time1->x;
	if (isEatingCross == true)
	{
		TimeWait += dt;
		if (TimeWait >= 1000)
		{

			isEatingCross = false;
			TimeWait = 0;
		}
	}

	if (stage == 1)
	{
		


		if (simon1->x > 1528 && simon1->y > offsetMap + 80)
			simon1->x = 1528;
		
		if (simon1->proceedThruDoor == false)
		{
			camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
			camera1->Update();
			if (camera1->GetPosition().x > 1191+16*2.5)
				camera1->SetPosition(1190+16*2.5, camera1->GetPosition().y);//simon chua qua cua nen set camera di chuyen toi cua th
		}
		else//dung box de bat dau qua cua
		{
			if (camera1->GetPosition().x <= 1387)
			{
				camera1->SetPosition(camera1->GetPosition().x + 1, camera1->GetPosition().y);//di  chuyen camera truoc
				
			}
			if (camera1->GetPosition().x > 1387)// neu camera dat vi tri x thi mo cua ra roi cho simon di qua
			{

				listDoor.at(0)->SetState(DOOR_STATE_ACTIVE_OPENED);
				simon1->SetState(SIMON_STATE_WALKING_RIGHT);
				if (simon1->x > 1584)//neu simon di den 1 doan x thi set ve vi tri idle
				{
					simon1->SetState(SIMON_STATE_IDLE);
					
					listDoor.at(0)->SetState(DOOR_STATE_ACTIVE_CLOSED);//dong cua
					simon1->stage = 02;
					if (camera1->GetPosition().x < 1536)
						camera1->SetPosition(camera1->GetPosition().x + 1, camera1->GetPosition().y);//keo camera qua hoan toan
					if (camera1->GetPosition().x >= 1536)
					{
						listDoor.at(0)->SetState(DOOR_STATE_INACTIVE);
						simon1->proceedThruDoor = false;
						stage = 2;//simon dang o man 2
					}

				}
			}
				
		}
	}
	else
		if (stage == 2)
		{
			if (simon1->x < 1536)
				simon1->x = 1536;
			for (UINT i = 0; i < listGroundEnemy.size(); i++)
			{
				if (listGroundEnemy.at(i)->getItemInside() == chickenInside)
				{
					if (listGroundEnemy.at(1)->GetState() == GROUND_STATE_INACTIVE)
					{

						if (simon1->x > 1808 - 16)
							simon1->x = 1808 - 16;
					}

				}
				else
					if (simon1->x > 1792 - 16)
						simon1->x = 1792 - 16;
			}
			

			if (x == false)
			{
				simon1->SetPosition(1920-320, 220);
				x = true;
			}
			camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
			camera1->Update();
			
			if (camera1->GetPosition().x < 1536)
				camera1->SetPosition(1536, camera1->GetPosition().y);
			
		}
		else
			if (stage == 3)
			{
				if (simon1->x < 2815)
					simon1->x = 2815;
			/*	if (groundEnemy1->GetState() != GROUND_STATE_INACTIVE)
				{
					if (simon1->x < 3294 && simon1->y > offsetMap + 80)
					{
						simon1->x = 3294;
						simon1->y = offsetMap + 80;

					}
				}*/
				if (x == true)
				{
					//Camera::GetInstance()->SetPosition(2814, 0);
					simon1->SetPosition(2975 - 149 + 16 * 2, 35);
					x = false;
				}
				if (y == true)
				{
					//Camera::GetInstance()->SetPosition(2814, 0);
					simon1->SetPosition(2975 - 149 + 16 * 2 + 320, 35);
					y = false;
				}
				camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
				camera1->Update();
				if (camera1->GetPosition().x < 2814)
					camera1->SetPosition(2814, camera1->GetPosition().y);




			}
			else
				if (stage == 4)
				{
					if (simon1->x > 2025 && simon1->y > offsetMap + 78)
					{
						simon1->x = 2025;
					}
					if (simon1->x < 1856 && simon1->y >offsetMap + 96)
					{
						simon1->x = 1856;
					}
					if (simon1->proceedThruDoor == false)
					{
						if (y == false)
						{

							//Camera::GetInstance()->SetPosition(1785, 0);
							simon1->SetPosition(1920, 220);
							y = true;
						}
						camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
						camera1->Update();
						if (camera1->GetPosition().x > 2055 + 8 - SCREEN_WIDTH)
							camera1->SetPosition(2055 + 8 - SCREEN_WIDTH, camera1->GetPosition().y);
						if (simon1->x < 1792 - 16)
							{
							y = false;
							x = true;
							stage = 2;
						}
						}
							
					else//dung box de bat dau qua cua
					{
						if (camera1->GetPosition().x <= 1920)
						{
							camera1->SetPosition(camera1->GetPosition().x + 1, camera1->GetPosition().y);//di  chuyen camera truoc

						}
						if (camera1->GetPosition().x > 1920)// neu camera dat vi tri x thi mo cua ra roi cho simon di qua
						{

							listDoor.at(0)->SetState(DOOR_STATE_ACTIVE_OPENED);
							simon1->SetState(SIMON_STATE_WALKING_RIGHT);
							if (simon1->x > 2081)//neu simon di den 1 doan x thi set ve vi tri idle							{
							{
								simon1->SetState(SIMON_STATE_IDLE);

								listDoor.at(0)->SetState(DOOR_STATE_ACTIVE_CLOSED);//dong cua
								if (camera1->GetPosition().x < 2050)
									camera1->SetPosition(camera1->GetPosition().x + 1, camera1->GetPosition().y);//keo camera qua hoan toan
								if (camera1->GetPosition().x >= 2050)
								{

									listDoor.at(0)->SetState(DOOR_STATE_INACTIVE);
									simon1->proceedThruDoor = false;
									stage = 5;
								}
							}
								

							
						}

					}
				}
				else
					if (stage == 5)
					{
						camera1->SetPosition(simon1->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon1
						camera1->Update();
						if (camera1->GetPosition().x < 2050 )
							camera1->SetPosition(2050, camera1->GetPosition().y);
						if (camera1->GetPosition().x > 2828 - SCREEN_WIDTH)
						{

							camera1->SetPosition(2828 - SCREEN_WIDTH, camera1->GetPosition().y);
							bossOn = true;
						}
						if (bossOn)
						{
							if (camera1->GetPosition().x < 2827 - SCREEN_WIDTH)
							{
								camera1->SetPosition(2827 - SCREEN_WIDTH, camera1->GetPosition().y);

							}
						}
						if (simon1->x > 2809 - 16)
							simon1->x = 2809 - 16;
						if (simon1->x < camera1->GetPosition().x)
						{
							simon1->x = camera1->GetPosition().x;
						}
						
					}

	float x1, y1;
	x1 = Camera::GetInstance()->GetPosition().x;
	y1 = Camera::GetInstance()->GetPosition().y;
	
	if (stage == 1)
	{
		if (simon1->proceedThruDoor == false)
		{

#pragma region spawnGhou
		tickGhou += 1;
		if ((simon1->x < 417 - SIMON_BIG_BBOX_WIDTH) || (simon1->x > 1117 && simon1->x < 1525))//chi cho ghou xuan hien khi simon trong vung do
		{//spawn every 6 seconds
			int xz = 0;
			if (spawnedEnoughGhou == true)
			{
				for (int z = 0; z < listEnemy1.size(); z++)
				{
					if (dynamic_cast<Ghou*>(listEnemy1.at(z)))
					{
						xz = xz + 1;
					}
				}
				if(xz==0)
				{
					spawnedEnoughGhou = false;
				}
			}
			else
			{
				if (tickGhou == 420 /*|| tickGhou == 460*/)
				{
				//	spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 125 + offsetMap, GHOU_STATE_ACTIVE_LEFT);
				}
				else
				//	if (tickGhou == 500)
				//	{
				//		spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 125 + offsetMap, GHOU_STATE_ACTIVE_LEFT);
				//		spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 125 + offsetMap, GHOU_STATE_ACTIVE_RIGHT);

				//		spawnedEnoughGhou=true;
				//	}
				//	else
						if (tickGhou > 420)
							tickGhou = 0;
			}

		}



		//Ghou part 2 solution
		if (x1 > 1160)
		{
			for (UINT i = 0; i < listEnemy1.size(); i++)
			{
				if (dynamic_cast<Ghou *>(listEnemy1.at(i)))
				{
					if (simon1->proceedThruDoor == false)
						if (listEnemy1.at(i)->x <= x1 + 5 && listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_LEFT)
							listEnemy1.at(i)->SetState(GHOU_STATE_ACTIVE_RIGHT);

					if (listEnemy1.at(i)->x > (1510) && listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_RIGHT)
						listEnemy1.at(i)->SetState(GHOU_STATE_ACTIVE_LEFT);
				}
			}
		}
#pragma endregion


		}

		if (simon1->x < 400 || simon1->x > 1129)//
		{	
			if (listPanther.size() == 0)
				spawnPanther();
		
		}
		for (UINT i = 0; i < listPanther.size(); i++)
			//if (abs(simon1->x - listPanther.at(i)->x) > 550)
				//listPanther.at(i)->StartUntouchable();
		if (simon1->x > 537 && simon1->x < 1120)//chi xu ly khi simon trong vung panter spawn
			XuLyPanthera();
	}
	else
	if (stage == 2 ||stage ==4)
	{
		if (simon1->proceedThruDoor == false)
		{

#pragma region spawnBat
			tickBat += 1;
			if (simon1->x > 1535 && simon1->x < 2048)//spawn Bat every 5 seconds/ fly speed 3 sec
			{
				if (tickBat == 330)
				{
					tickBat = 0;
					spawnBat(simon1, camera1);
				}
				else if (tickBat > 330)
				{
					tickBat = 0;
				}
			}
			if (x1 > 1702)
			{
				for (UINT i = 0; i < listEnemy1.size(); i++)
				{
					if (dynamic_cast<Bat *>(listEnemy1.at(i)))
					{
						if (listEnemy1.at(i)->x >= 2040 && listEnemy1.at(i)->GetState() == BAT_STATE_ACTIVE_RIGHT)
							listEnemy1.at(i)->SetState(BAT_STATE_INACTIVE);


					}
				}
			}
#pragma endregion
		}

	
	}
	else
		if (stage == 3)
		{

#pragma region spawnMonster
			int j = 0;
			for (UINT i = 0; i < listEnemy1.size(); i++)
			{
				if (dynamic_cast<Monster *>(listEnemy1.at(i)))
				{
					j = j + 1;
				}
			}
			//if (j < 2)
				//spawnMonster();

			tickMonster += 1;
			{//spawn every 6 seconds
				int xz = 0;
				if (spawnedEnoughMonster == true)
				{
					for (int z = 0; z < listEnemy1.size(); z++)
					{
						if (dynamic_cast<Monster*>(listEnemy1.at(z)))
						{
							xz = xz + 1;
						}
					}
					if (xz <2 )
					{
						spawnedEnoughMonster = false;
					}
				}
				else
				{
					if (tickMonster == 420)
					{
					//spawnMonster();
					}
					else
						if (tickMonster == 440)
						{
							//spawnMonster();
							spawnedEnoughMonster = true;
						}
						else
							if (tickMonster > 440)
								tickMonster = 0;
				}
			}

			spawnFireBall();


#pragma endregion

			
		}
		else
			if(stage == 5)
			{
				if (simon1->x > 2069 && simon1->x < 2496 - 16)
				{
					if (simon1->x <= 2210) //spawn 2 tang ghou
					{
#pragma region spawnGhou
						tickGhou += 1;
						{//spawn every 6 seconds
					
							{
								if (floor1 == false)
								{

									if (tickGhou == 420 || tickGhou == 460)
									{
										spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 60 + offsetMap, GHOU_STATE_ACTIVE_LEFT);
									}
									else
										if (tickGhou == 500)
										{
											spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 125 + offsetMap, GHOU_STATE_ACTIVE_LEFT);

											floor1 = true;
										}
										else
											if (tickGhou > 500)
												tickGhou = 0;
								}
								else
									if (floor1 == true)
									{
										if (tickGhou == 420 || tickGhou == 460)
										{
											spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 125 + offsetMap, GHOU_STATE_ACTIVE_LEFT);

										}
										else
											if (tickGhou == 500)
											{
												spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 60 + offsetMap, GHOU_STATE_ACTIVE_LEFT);
												floor1 = false;

											}
											else
												if (tickGhou > 500)
													tickGhou = 0;
									}
							}

						}



#pragma endregion

					}
					if (simon1->x > 2210)//spawn 1 tagn ghou
					{
						tickGhou += 1;
						if (tickGhou == 420 || tickGhou == 460)
						{
							spawnGhou(x1 + SCREEN_WIDTH - 60 + 30, 125 + offsetMap, GHOU_STATE_ACTIVE_LEFT);
						}
						else
							if (tickGhou == 500)
							{
								spawnGhou(x1 + SCREEN_WIDTH, 125 + offsetMap, GHOU_STATE_ACTIVE_RIGHT);
							}
							else
								if (tickGhou > 500)
									tickGhou = 0;
					}
				}
				spawnFireBall();
			}

	//if (simon1->isUsing1stWeapon == true || simon1->isUsing2ndWeapon==true)
	{

		if ((simon1->dagger->GetState() != DAGGER_STATE_INACTIVE))
			simon1->dagger->Update(dt, &listSurface1);
		if ((simon1->dagger1->GetState() != DAGGER_STATE_INACTIVE))
			simon1->dagger1->Update(dt, &listSurface1);
		if (simon1->dagger->isOn == true)
		{
			if ((simon1->dagger->x) < x1 || (simon1->dagger->x) > (x1 + SCREEN_WIDTH))// bay ngoai man hinh thi cho dagger inactive
			{
				simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
				simon1->notUseWeapon();
			}
			if (simon1->shotTwoWeaponOneTime == true)
			{
				

				if ((simon1->dagger1->x) < x1 || (simon1->dagger1->x) > (x1 + SCREEN_WIDTH))// bay ngoai man hinh thi cho dagger inactive
				{
					simon1->dagger1->SetState(DAGGER_STATE_INACTIVE);
					simon1->notUseWeapon2();
				}
			}

		}


		if ((simon1->axe->GetState() != AXE_STATE_INACTIVE))
			simon1->axe->Update(dt, &listSurface1);
		if ((simon1->axe1->GetState() != AXE_STATE_INACTIVE))
			simon1->axe1->Update(dt, &listSurface1);
		if (simon1->axe->isOn == true)
		{
			if (simon1->axe->GetState() == AXE_STATE_INACTIVE)
			{
				simon1->notUseWeapon();
			}
			if (simon1->shotTwoWeaponOneTime == true)
			{


				if (simon1->axe1->GetState() == AXE_STATE_INACTIVE)
				{
					simon1->notUseWeapon2();
				}
			}
		}

		

			if ((simon1->holy->GetState() != HOLYWATER_STATE_INACTIVE))
				simon1->holy->Update(dt, &listSurface1);
			if ((simon1->holy1->GetState() != HOLYWATER_STATE_INACTIVE))
				simon1->holy1->Update(dt, &listSurface1);
			if (simon1->holy->isOn == true)
			{


				if (simon1->holy->GetState() == HOLYWATER_STATE_INACTIVE)
				{
					simon1->notUseWeapon();
				}

				if (simon1->shotTwoWeaponOneTime == true)
				{
					if (simon1->holy1->GetState() == HOLYWATER_STATE_INACTIVE)
					{
						simon1->notUseWeapon2();
					}
				}
			}
		
				
	}
	//if (simon1->dagger->GetState() == DAGGER_STATE_INACTIVE)
	//	simon1->dagger->isFinished = true;

	//if (simon1->dagger1->GetState() == DAGGER_STATE_INACTIVE)
	//	simon1->dagger1->isFinished = true;

	if (simon1->axe->GetState() == AXE_STATE_INACTIVE)
		simon1->axe->isFinished = true;

	//if (simon1->axe1->GetState() == AXE_STATE_INACTIVE)
	//	simon1->axe1->isFinished = true;

	if (simon1->holy->GetState() == HOLYWATER_STATE_INACTIVE)
		simon1->holy->isFinished = true;

	if (simon1->holy1->GetState() == HOLYWATER_STATE_INACTIVE)
		simon1->holy1->isFinished = true;
	for (int i = 0; i < listItem1.size(); i++)
	{
		listItem1.at(i)->Update(dt, &listSurface1);
	}

	for (int i = 0; i < listEffectFire1.size(); i++)
	{
		listEffectFire1.at(i)->Update(dt, &listSurface1);
	}

	for (int i = 0; i < listEffectBag1.size(); i++)//render ietms
		listEffectBag1[i]->Update(dt);
	spawnItemsAfterEffect();
	if (stage == 5)
		boss->Update(dt, simon1);
	for (int i = 0; i < listEnemy1.size(); i++)
		listEnemy1[i]->Update(dt, &listSurface1);
	for (int i = 0; i < listPanther.size(); i++)
		if (abs(simon1->x - listPanther[i]->x) < 220)
			listPanther[i]->Update(dt, &listSurface1);

	for (int i = 0; i < listGroundEnemy.size(); i++)
		listGroundEnemy[i]->Update(dt, &listSurface1);

	erasingObjThatInacitve();// xoa may enemy di ra khoi man hinh

	if (simon1->proceedThruDoor == false)//dang qua cua k xet va cham
		if (simon1->untouchable == false)//bi untouchable thi k va cham voi enemy nua
			if (simon1->isInvis == false)
				CollisionBetSimonAndEnemy();
	CollisionBetSimonAndCheckBox();
	CollisionBetSimonAndItem();

	CollisionBetWeaponAndEnemy();

	simon1->Update(dt, &listSurface1);
	TimeWaitToChangeColor += dt;
	
	if (boss->GetState() == BOSS_STATE_INACTIVE)
	{
		TimeWaitToCount += dt;
		if (TimeWaitToCount >= 200)
		{
			TimeWaitToCount = TimeWaitToCount % 200;
			TinhDiem();
		}
	}
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
		if (isEatingCross)
		{
			if (TimeWaitToChangeColor >50)
			{
				if (changedColor == true)
				{
					d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR2);
					changedColor = false;
					

				}
				else
			
				{
					d3ddv->ColorFill(bb, NULL, BACKGROUND_COLOR);
					changedColor = true;
				}
				TimeWaitToChangeColor = 0;
			}
			
		}

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
		board->Render();
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
		for (int i = 0; i < listDoor.size(); i++)
			listDoor[i]->Render();
		simon1->Render();
		for (int i = 0; i < listEffectBag1.size(); i++)//render ietms
			listEffectBag1[i]->Render();
		for (int i = 0; i < listItem1.size(); i++)
			listItem1[i]->Render();
		for (int i = 0; i < listPanther.size(); i++)
			listPanther[i]->Render();
		
		for (int i = 0; i < listGroundEnemy.size(); i++)
			listGroundEnemy[i]->Render();
		boss->Render();
		for (int i = 0; i < listEffectFire1.size(); i++)
			listEffectFire1[i]->Render();
		simon1->dagger->Render();
		simon1->axe->Render();
		simon1->holy->Render();
		simon1->whip->Render();
		if(simon1->shotTwoWeaponOneTime==true)
		{
			simon1->dagger1->Render();
			simon1->axe1->Render();
			simon1->holy1->Render();
		}
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
		randomNumber == 18 || randomNumber == 17 || randomNumber == 19 || randomNumber == 20 ||
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
	stage = 1;
	newGrid1 = new Grid();
	time1 = new Time();
	boss = new Boss();
	simon1->proceedThruDoor = false;
	fire = new FireBall();
	effectBag1 = new EffectBag();
	camera1 = Camera::GetInstance();
	textures = CTextures::GetInstance();
	sprites	= CSprites::GetInstance();
	animations	= CAnimations::GetInstance();
	simon1->SetPosition(50, 0);
	board = new Board();
	if (simon1->dagger->isOn)
		board->typeOfWeaopon = 1;
	else
		if (simon1->axe->isOn)
			board->typeOfWeaopon = 2;
		else
			if (simon1->holy->isOn)
				board->typeOfWeaopon = 3;
			else
				if (simon1->clock->isOn)
					board->typeOfWeaopon = 4;
	board->SetPosition(0, 0);
	LoadResources();
	isEatingCross = false;
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
			if (dynamic_cast<Bat *>(listEnemy1.at(i)))
			{
				if (listEnemy1.at(i)->GetState() == BAT_STATE_INACTIVE)
				{
					listEnemy1.erase(listEnemy1.begin() + i);
					i = i - 1;
				}
			}
			else
				if (dynamic_cast<Monster *>(listEnemy1.at(i)))
				{
					if (listEnemy1.at(i)->GetState() == MONSTER_STATE_INACTIVE)
					{
						listEnemy1.erase(listEnemy1.begin() + i);
						i = i - 1;
					}
				}
				else
					if (dynamic_cast<FireBall *>(listEnemy1.at(i)))
					{
						if (listEnemy1.at(i)->GetState() == FIREBALL_STATE_INACTIVE)
						{
							listEnemy1.erase(listEnemy1.begin() + i);
							i = i - 1;
						}
					}
					else
						if (dynamic_cast<GroundEnemy *>(listEnemy1.at(i)))
						{
							if (listEnemy1.at(i)->GetState() == GROUND_STATE_INACTIVE)
							{
								listEnemy1.erase(listEnemy1.begin() + i);
								i = i - 1;
							}
						}


	}
	for (UINT i = 0; i < listItem1.size(); i++)
	{
		if (listItem1.at(i)->state == ITEM_STATE_INACTIVE)
		{
			listItem1.erase(listItem1.begin() + i);
			i = i - 1;
		}
	}
	for (UINT i = 0; i < listPanther.size(); i++)
	{
		if (listPanther.at(i)->GetState() == PANTHER_STATE_INACTIVE)
		{
			listPanther.erase(listPanther.begin() + i);
			i = i - 1;
		}

	}
}

void Scene2::spawnGhou(float x,float y,int state)
{
	
	
		ghou = new Ghou();
		ghou->AddAnimation(531);
		ghou->AddAnimation(532);
		ghou->AddAnimation(533);
		ghou->AddAnimation(534);
		ghou->SetState(state);
		if (state == GHOU_STATE_ACTIVE_LEFT)
			ghou->SetPosition(x , y);
		else
			if (state == GHOU_STATE_ACTIVE_RIGHT)
			{
				ghou->SetPosition(Camera::GetInstance()->GetPosition().x + 10, y);

			}
		
		ghou->setItemInside(randomIteminside());
		listEnemy1.push_back(ghou);
	
}

void Scene2::spawnBat(Simon * simon,Camera *camera1)
{
	bat1 = new Bat(simon->y+8);
	bat1->AddAnimation(521);
	bat1->AddAnimation(520);
	bat1->AddAnimation(523);
	bat1->AddAnimation(522);
	bat1->setItemInside(randomIteminside());
	
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
	listEnemy1.push_back(bat1);

}

void Scene2::freezeEnemyFunction()
{
	for (UINT i = 0; i < listEnemy1.size(); i++)
	{

		float x1 = Camera::GetInstance()->GetPosition().x;
			float y1 = Camera::GetInstance()->GetPosition().y;
		if (listEnemy1.at(i)->x > x1 &&
			listEnemy1.at(i)->x<x1 + SCREEN_WIDTH &&
			listEnemy1.at(i)->y>y1 &&
			listEnemy1.at(i)->y < y1 + SCREEN_HEIGHT)
		{
			if (!(dynamic_cast<GroundEnemy *>(listEnemy1.at(i))))
			{

				//listEnemy1.at(i)->SetState(ENEMY_STATE_FREEZE);
				//listEnemy1.at(i)->freezed = true;
				listEnemy1.at(i)->StartUntouchable();
			}

		}
	}
	for (UINT i = 0; i < listPanther.size(); i++)
	{
		float x1 = Camera::GetInstance()->GetPosition().x;
		float y1 = Camera::GetInstance()->GetPosition().y;
		if (listPanther.at(i)->x > x1 &&
			listPanther.at(i)->x<x1 + SCREEN_WIDTH &&
			listPanther.at(i)->y>y1 &&
			listPanther.at(i)->y < y1 + SCREEN_HEIGHT)
		{
			if (!(dynamic_cast<GroundEnemy *>(listEnemy1.at(i))))
			{

				//listEnemy1.at(i)->SetState(ENEMY_STATE_FREEZE);
				//listEnemy1.at(i)->freezed = true;
				listPanther.at(i)->StartUntouchable();
			}

		}
	}
}
void Scene2::CollisionBetWeaponAndEnemy()
{

	if (simon1->whip->isFinished == false && simon1->whip->isAllowedToCollide == true)
	{
		for (UINT i = 0; i < listEnemy1.size(); i++)
		{
			if (simon1->whip->CheckCollision(listEnemy1.at(i)) == true)
			{
					if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
					{
						float x, y;
						listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
						listEnemy1.at(i)->GetPosition(x, y);

						effectFire1 = new EffectFire();
						effectFire1->AddAnimation(578);
						effectFire1->AddAnimation(577);
						effectFire1->AddAnimation(576);
						effectFire1->SetState(EFFECT_STATE_ACTIVE);
						effectFire1->itemInside = listEnemy1.at(i)->itemInside;
						effectFire1->SetPosition(x, y);
						effectFire1->type = 0;
						listEffectFire1.push_back(effectFire1);
						listEnemy1.erase(listEnemy1.begin() + i);
						i = i - 1;
					}

				}

			
		}
		for (UINT i = 0; i < listTorches1.size(); i++)
		{

			if (simon1->whip->CheckCollision(listTorches1.at(i)) == true)
			{
				
				{
					if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
					{
						float x, y;
						listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
						listTorches1.at(i)->GetPosition(x, y);
						effectFire1 = new EffectFire();
						effectFire1->AddAnimation(578);
						effectFire1->AddAnimation(577);
						effectFire1->AddAnimation(576);
						effectFire1->SetState(EFFECT_STATE_ACTIVE);
						effectFire1->type = 0;
						effectFire1->itemInside = listTorches1.at(i)->itemInside;
						effectFire1->SetPosition(x, y);
						listEffectFire1.push_back(effectFire1);

						listTorches1.erase(listTorches1.begin() + i);
						i = i - 1;
					}
				}


			}
		}
		if (simon1->whip->CheckCollision(boss) == true)
		{
			if (boss->untouchable == false)
			{
				float x, y;
				boss->GetPosition(x, y);
				boss->StartUntouchable();
				if (simon1->whip->type = VAMPIRE_KILLER)
					boss->hp -= 1;
				else
					boss->hp -= 2;


				effectFire1 = new EffectFire();
				effectFire1->AddAnimation(578);
				effectFire1->AddAnimation(577);
				effectFire1->AddAnimation(576);
				effectFire1->SetState(EFFECT_STATE_ACTIVE);
				if (boss->hp == 0)
					effectFire1->itemInside = boss->itemInside;
				effectFire1->SetPosition(x, y);
				effectFire1->type = 0;


				listEffectFire1.push_back(effectFire1);


			}



		}
		for (UINT i = 0; i < listGroundEnemy.size(); i++)
		{

			if (simon1->whip->CheckCollision(listGroundEnemy.at(i)) == true)
			{

				{
					if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
					{
						if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
						{
							for (UINT xz = 0; xz < listSurface1.size(); xz++)
							{
								if (listSurface1.at(xz)->x == listGroundEnemy.at(i)->x)
								{
									listSurface1.at(xz)->SetState(GROUND_STATE_INACTIVE);
								}
							}
							float x, y;
							listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
							listGroundEnemy.at(i)->GetPosition(x, y);
							effectFire1 = new EffectFire();
							effectFire1->AddAnimation(578);
							effectFire1->AddAnimation(577);
							effectFire1->AddAnimation(576);
							effectFire1->SetState(EFFECT_STATE_ACTIVE);
							effectFire1->type = 0;
							effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
							effectFire1->SetPosition(x - 35, y - 5);
							effectFire1->type = 1;
							listEffectFire1.push_back(effectFire1);
							listGroundEnemy.erase(listGroundEnemy.begin() + i);
							i = i - 1;
						}
					
					}
				}
			}
		}
		for (UINT i = 0; i < listPanther.size(); i++)
		{
			if (simon1->whip->CheckCollision(listPanther.at(i)) == true)
			{
				if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
				{
					float x, y;
					listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
					listPanther.at(i)->GetPosition(x, y);

					effectFire1 = new EffectFire();
					effectFire1->AddAnimation(578);
					effectFire1->AddAnimation(577);
					effectFire1->AddAnimation(576);
					effectFire1->SetState(EFFECT_STATE_ACTIVE);
					effectFire1->itemInside = listPanther.at(i)->itemInside;
					effectFire1->SetPosition(x, y);
					effectFire1->type = 0;
					listEffectFire1.push_back(effectFire1);
					listPanther.erase(listPanther.begin() + i);
					i = i - 1;
				}

			}
		}

	}
	else
		if (simon1->dagger->state != DAGGER_STATE_INACTIVE && simon1->dagger->isOn == true && simon1->isUsing1stWeapon == true)
		{
			for (UINT i = 0; i < listEnemy1.size(); i++)
			{
				if (simon1->dagger->CheckCollision(listEnemy1.at(i)) == true)
				{
					if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
					{

						simon1->notUseWeapon();
						simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
						float x, y;
						listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
						listEnemy1.at(i)->GetPosition(x, y);

						effectFire1 = new EffectFire();
						effectFire1->AddAnimation(578);
						effectFire1->AddAnimation(577);
						effectFire1->AddAnimation(576);
						effectFire1->SetPosition(x, y);
						effectFire1->SetState(EFFECT_STATE_ACTIVE);
						effectFire1->itemInside = listEnemy1.at(i)->itemInside;
						listEffectFire1.push_back(effectFire1);

						listEnemy1.erase(listEnemy1.begin() + i);
						i = i - 1;
					}
				}

			}
			for (UINT i = 0; i < listTorches1.size(); i++)
			{
				if (simon1->dagger->CheckCollision(listTorches1.at(i)) == true)
				{
					if (listTorches1.at(i)->state == TORCH_STATE_ACTIVE)
					{
						simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
						simon1->notUseWeapon();
						float x, y;
						listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
						listTorches1.at(i)->GetPosition(x, y);

						effectFire1 = new EffectFire();
						effectFire1->AddAnimation(578);
						effectFire1->AddAnimation(577);
						effectFire1->AddAnimation(576);
						effectFire1->SetPosition(x, y);
						effectFire1->SetState(EFFECT_STATE_ACTIVE);
						effectFire1->itemInside = listTorches1.at(i)->itemInside;
						listEffectFire1.push_back(effectFire1);

						listTorches1.erase(listTorches1.begin() + i);
						i = i - 1;
					}

				}
			}
			if (simon1->dagger->CheckCollision(boss) == true)
			{
				if (boss->untouchable == false)
				{
					float x, y;
					boss->GetPosition(x, y);
					boss->StartUntouchable();
						boss->hp -= 2;


					effectFire1 = new EffectFire();
					effectFire1->AddAnimation(578);
					effectFire1->AddAnimation(577);
					effectFire1->AddAnimation(576);
					effectFire1->SetState(EFFECT_STATE_ACTIVE);
					if (boss->hp == 0)
						effectFire1->itemInside = boss->itemInside;
					effectFire1->SetPosition(x, y);
					effectFire1->type = 0;


					listEffectFire1.push_back(effectFire1);


				}



			}
			for (UINT i = 0; i < listGroundEnemy.size(); i++)
			{

				if (simon1->dagger->CheckCollision(listGroundEnemy.at(i)) == true)
				{

					{
						if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
						{
							if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
							{
								float x, y;
								listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
								listGroundEnemy.at(i)->GetPosition(x, y);
								effectFire1 = new EffectFire();
								effectFire1->AddAnimation(578);
								effectFire1->AddAnimation(577);
								effectFire1->AddAnimation(576);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								effectFire1->type = 0;
								effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
								effectFire1->SetPosition(x - 35, y - 5);
								effectFire1->type = 1;
								listEffectFire1.push_back(effectFire1);
								listGroundEnemy.erase(listGroundEnemy.begin() + i);
								i = i - 1;
							}

						}
					}
				}
			}
			for (UINT i = 0; i < listPanther.size(); i++)
			{
				if (simon1->dagger->CheckCollision(listPanther.at(i)) == true)
				{
					if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
					{

						simon1->notUseWeapon();
						simon1->dagger->SetState(DAGGER_STATE_INACTIVE);
						float x, y;
						listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
						listPanther.at(i)->GetPosition(x, y);

						effectFire1 = new EffectFire();
						effectFire1->AddAnimation(578);
						effectFire1->AddAnimation(577);
						effectFire1->AddAnimation(576);
						effectFire1->SetPosition(x, y);
						effectFire1->SetState(EFFECT_STATE_ACTIVE);
						effectFire1->itemInside = listPanther.at(i)->itemInside;
						listEffectFire1.push_back(effectFire1);

						listPanther.erase(listPanther.begin() + i);
						i = i - 1;
					}
				}

			}

		}
		else
			if (simon1->dagger1->state != DAGGER_STATE_INACTIVE && simon1->isUsing2ndWeapon == true)
			{
				for (UINT i = 0; i < listEnemy1.size(); i++)
				{
					if (simon1->dagger1->CheckCollision(listEnemy1.at(i)) == true)
					{
					{
							simon1->notUseWeapon2();
							simon1->dagger1->SetState(DAGGER_STATE_INACTIVE);
							if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
							{
								float x, y;
								listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
								listEnemy1.at(i)->GetPosition(x, y);

								effectFire1->SetPosition(x, y);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								effectFire1->itemInside = listEnemy1.at(i)->itemInside;
								listEffectFire1.push_back(effectFire1);

								listEnemy1.erase(listEnemy1.begin() + i);
								i = i - 1;
							}
						}

					}
				}
				for (UINT i = 0; i < listTorches1.size(); i++)
				{
					if (simon1->dagger1->CheckCollision(listTorches1.at(i)) == true)
					{
						if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
							{
								simon1->dagger1->SetState(DAGGER_STATE_INACTIVE);
								simon1->notUseWeapon2();
								float x, y;
								listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
								listTorches1.at(i)->GetPosition(x, y);
								effectFire1 = new EffectFire();
								effectFire1->AddAnimation(578);
								effectFire1->AddAnimation(577);
								effectFire1->AddAnimation(576);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								effectFire1->SetPosition(x, y);
								effectFire1->itemInside = listTorches1.at(i)->itemInside;
								listEffectFire1.push_back(effectFire1);

								listTorches1.erase(listTorches1.begin() + i);
								i = i - 1;
							}
						}
					}
				if (simon1->dagger1->CheckCollision(boss) == true)
				{
					if (boss->untouchable == false)
					{
						float x, y;
						boss->GetPosition(x, y);
						boss->StartUntouchable();
						boss->hp -= 2;


						effectFire1 = new EffectFire();
						effectFire1->AddAnimation(578);
						effectFire1->AddAnimation(577);
						effectFire1->AddAnimation(576);
						effectFire1->SetState(EFFECT_STATE_ACTIVE);
						if (boss->hp == 0)
							effectFire1->itemInside = boss->itemInside;
						effectFire1->SetPosition(x, y);
						effectFire1->type = 0;


						listEffectFire1.push_back(effectFire1);


					}



				}
				for (UINT i = 0; i < listGroundEnemy.size(); i++)
				{

					if (simon1->dagger1->CheckCollision(listGroundEnemy.at(i)) == true)
					{

						{
							if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
							{
								if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
								{
									float x, y;
									listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
									listGroundEnemy.at(i)->GetPosition(x, y);
									effectFire1 = new EffectFire();
									effectFire1->AddAnimation(578);
									effectFire1->AddAnimation(577);
									effectFire1->AddAnimation(576);
									effectFire1->SetState(EFFECT_STATE_ACTIVE);
									effectFire1->type = 0;
									effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
									effectFire1->SetPosition(x - 35, y - 5);
									effectFire1->type = 1;
									listEffectFire1.push_back(effectFire1);
									listGroundEnemy.erase(listGroundEnemy.begin() + i);
									i = i - 1;
								}

							}
						}
					}
				}
				for (UINT i = 0; i < listPanther.size(); i++)
				{
					if (simon1->dagger1->CheckCollision(listPanther.at(i)) == true)
					{
						{
							simon1->notUseWeapon2();
							simon1->dagger1->SetState(DAGGER_STATE_INACTIVE);
							if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
							{
								float x, y;
								listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
								listPanther.at(i)->GetPosition(x, y);
								effectFire1 = new EffectFire();
								effectFire1->AddAnimation(578);
								effectFire1->AddAnimation(577);
								effectFire1->AddAnimation(576);
								effectFire1->SetPosition(x, y);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								effectFire1->itemInside = listPanther.at(i)->itemInside;
								listEffectFire1.push_back(effectFire1);

								listPanther.erase(listPanther.begin() + i);
								i = i - 1;
							}
						}

					}
				}

			}
			else
				if (simon1->axe->state != AXE_STATE_INACTIVE && simon1->axe->isOn == true && simon1->isUsing1stWeapon == true)
				{
					for (UINT i = 0; i < listEnemy1.size(); i++)
					{
						if (simon1->axe->CheckCollision(listEnemy1.at(i)) == true)
						{
							{

								if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
								{
									simon1->axe->SetState(AXE_STATE_INACTIVE);
									simon1->notUseWeapon();
									float x, y;
									listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
									listEnemy1.at(i)->GetPosition(x, y);
									effectFire1 = new EffectFire();
									effectFire1->AddAnimation(578);
									effectFire1->AddAnimation(577);
									effectFire1->AddAnimation(576);
									effectFire1->SetPosition(x, y);
									effectFire1->SetState(EFFECT_STATE_ACTIVE);
									effectFire1->itemInside = listEnemy1.at(i)->itemInside;
									listEffectFire1.push_back(effectFire1);

									listEnemy1.erase(listEnemy1.begin() + i);
									i = i - 1;
								}
							}

						}
					}
					for (UINT i = 0; i < listTorches1.size(); i++)
					{
						if (simon1->axe->CheckCollision(listTorches1.at(i)) == true)
						{

							if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
							{
								simon1->axe->SetState(AXE_STATE_INACTIVE);
								simon1->notUseWeapon();

								float x, y;
								listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
								listTorches1.at(i)->GetPosition(x, y); 
								effectFire1 = new EffectFire();
								effectFire1->AddAnimation(578);
								effectFire1->AddAnimation(577);
								effectFire1->AddAnimation(576);
								effectFire1->SetPosition(x, y);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								effectFire1->itemInside = listTorches1.at(i)->itemInside;
								listEffectFire1.push_back(effectFire1);

								listTorches1.erase(listTorches1.begin() + i);
								i = i - 1;
							}
						}

					}
					if (simon1->axe->CheckCollision(boss) == true)
					{
						if (boss->untouchable == false)
						{
							simon1->axe->SetState(AXE_STATE_INACTIVE);
							simon1->notUseWeapon();
							float x, y;
							boss->GetPosition(x, y);
							boss->StartUntouchable();
							boss->hp -= 2;


							effectFire1 = new EffectFire();
							effectFire1->AddAnimation(578);
							effectFire1->AddAnimation(577);
							effectFire1->AddAnimation(576);
							effectFire1->SetState(EFFECT_STATE_ACTIVE);
							if (boss->hp == 0)
								effectFire1->itemInside = boss->itemInside;
							effectFire1->SetPosition(x, y);
							effectFire1->type = 0;


							listEffectFire1.push_back(effectFire1);


						}



					}
					for (UINT i = 0; i < listGroundEnemy.size(); i++)
					{

						if (simon1->axe->CheckCollision(listGroundEnemy.at(i)) == true)
						{

							{
								if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
								{
									if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
									{
										simon1->axe->SetState(AXE_STATE_INACTIVE);
										simon1->notUseWeapon();
										float x, y;
										listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
										listGroundEnemy.at(i)->GetPosition(x, y);
										effectFire1 = new EffectFire();
										effectFire1->AddAnimation(578);
										effectFire1->AddAnimation(577);
										effectFire1->AddAnimation(576);
										effectFire1->SetState(EFFECT_STATE_ACTIVE);
										effectFire1->type = 0;
										effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
										effectFire1->SetPosition(x - 35, y - 5);
										effectFire1->type = 1;
										listEffectFire1.push_back(effectFire1);
										listGroundEnemy.erase(listGroundEnemy.begin() + i);
										i = i - 1;
									}

								}
							}
						}
					}
					for (UINT i = 0; i < listPanther.size(); i++)
					{
						if (simon1->axe->CheckCollision(listPanther.at(i)) == true)
						{
							{

								if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
								{
									simon1->axe->SetState(AXE_STATE_INACTIVE);
									simon1->notUseWeapon();
									float x, y;
									listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
									listPanther.at(i)->GetPosition(x, y);

									effectFire1 = new EffectFire();
									effectFire1->AddAnimation(578);
									effectFire1->AddAnimation(577);
									effectFire1->AddAnimation(576);
									effectFire1->SetPosition(x, y);
									effectFire1->SetState(EFFECT_STATE_ACTIVE);
									effectFire1->itemInside = listPanther.at(i)->itemInside;
									listEffectFire1.push_back(effectFire1);

									listPanther.erase(listPanther.begin() + i);
									i = i - 1;
								}
							}

						}
					}

				}
				else
				if (simon1->axe1->state != AXE_STATE_INACTIVE  && simon1->isUsing2ndWeapon == true)
				{
					for (UINT i = 0; i < listEnemy1.size(); i++)
					{
						if (simon1->axe1->CheckCollision(listEnemy1.at(i)) == true)
						{
							{

								if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
								{
									simon1->axe1->SetState(AXE_STATE_INACTIVE);
									simon1->notUseWeapon2();
									float x, y;
									listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
									listEnemy1.at(i)->GetPosition(x, y);

									effectFire1 = new EffectFire();
									effectFire1->AddAnimation(578);
									effectFire1->AddAnimation(577);
									effectFire1->AddAnimation(576);
									effectFire1->SetPosition(x, y);
									effectFire1->SetState(EFFECT_STATE_ACTIVE);
									effectFire1->itemInside = listEnemy1.at(i)->itemInside;
									listEffectFire1.push_back(effectFire1);

									listEnemy1.erase(listEnemy1.begin() + i);
									i = i - 1;
								}
							}

						}
					}
					for (UINT i = 0; i < listTorches1.size(); i++)
					{
						if (simon1->axe1->CheckCollision(listTorches1.at(i)) == true)
						{

							if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
							{
								simon1->axe1->SetState(AXE_STATE_INACTIVE);
								simon1->notUseWeapon2();

								float x, y;
								listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
								listTorches1.at(i)->GetPosition(x, y);

								effectFire1 = new EffectFire();
								effectFire1->AddAnimation(578);
								effectFire1->AddAnimation(577);
								effectFire1->AddAnimation(576);
								effectFire1->SetPosition(x, y);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								effectFire1->itemInside = listTorches1.at(i)->itemInside;
								listEffectFire1.push_back(effectFire1);

								listTorches1.erase(listTorches1.begin() + i);
								i = i - 1;
							}
						}

					}
					if (simon1->axe1->CheckCollision(boss) == true)
					{
						if (boss->untouchable == false)
						{
							simon1->axe1->SetState(AXE_STATE_INACTIVE);
							simon1->notUseWeapon2();
							float x, y;
							boss->GetPosition(x, y);
							boss->StartUntouchable();
							boss->hp -= 2;


							effectFire1 = new EffectFire();
							effectFire1->AddAnimation(578);
							effectFire1->AddAnimation(577);
							effectFire1->AddAnimation(576);
							effectFire1->SetState(EFFECT_STATE_ACTIVE);
							if (boss->hp == 0)
								effectFire1->itemInside = boss->itemInside;
							effectFire1->SetPosition(x, y);
							effectFire1->type = 0;


							listEffectFire1.push_back(effectFire1);


						}



					}
					for (UINT i = 0; i < listGroundEnemy.size(); i++)
					{

						if (simon1->axe1->CheckCollision(listGroundEnemy.at(i)) == true)
						{

							{
								if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
								{
									if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
									{
										simon1->axe1->SetState(AXE_STATE_INACTIVE);
										simon1->notUseWeapon2();
										float x, y;
										listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
										listGroundEnemy.at(i)->GetPosition(x, y);
										effectFire1 = new EffectFire();
										effectFire1->AddAnimation(578);
										effectFire1->AddAnimation(577);
										effectFire1->AddAnimation(576);
										effectFire1->SetState(EFFECT_STATE_ACTIVE);
										effectFire1->type = 0;
										effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
										effectFire1->SetPosition(x - 35, y - 5);
										effectFire1->type = 1;
										listEffectFire1.push_back(effectFire1);
										listGroundEnemy.erase(listGroundEnemy.begin() + i);
										i = i - 1;
									}

								}
							}
						}
					}
					for (UINT i = 0; i < listPanther.size(); i++)
					{
						if (simon1->axe1->CheckCollision(listPanther.at(i)) == true)
						{
							{

								if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
								{
									simon1->axe1->SetState(AXE_STATE_INACTIVE);
									simon1->notUseWeapon2();
									float x, y;
									listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
									listPanther.at(i)->GetPosition(x, y);

									effectFire1 = new EffectFire();
									effectFire1->AddAnimation(578);
									effectFire1->AddAnimation(577);
									effectFire1->AddAnimation(576);
									effectFire1->SetPosition(x, y);
									effectFire1->SetState(EFFECT_STATE_ACTIVE);
									effectFire1->itemInside = listPanther.at(i)->itemInside;
									listEffectFire1.push_back(effectFire1);

									listPanther.erase(listEnemy1.begin() + i);
									i = i - 1;
								}
							}

						}
					}

				}
				else
					if (simon1->holy->state != HOLYWATER_STATE_INACTIVE && simon1->holy->isOn == true && simon1->isUsing1stWeapon == true)
					{
						for (UINT i = 0; i < listEnemy1.size(); i++)
						{
							if (simon1->holy->CheckCollision(listEnemy1.at(i)) == true)
							{
								{
									if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
									{
										//simon1->notUseWeapon();

										float x, y;
										listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
										listEnemy1.at(i)->GetPosition(x, y);

										effectFire1 = new EffectFire();
										effectFire1->AddAnimation(578);
										effectFire1->AddAnimation(577);
										effectFire1->AddAnimation(576);
										effectFire1->SetPosition(x, y);
										effectFire1->SetState(EFFECT_STATE_ACTIVE);
										effectFire1->itemInside = listEnemy1.at(i)->itemInside;
										listEffectFire1.push_back(effectFire1);

										listEnemy1.erase(listEnemy1.begin() + i);
										i = i - 1;
									}
								}

							}
						}
						for (UINT i = 0; i < listTorches1.size(); i++)
						{
							if (simon1->holy->CheckCollision(listTorches1.at(i)) == true)
							{
								{
									if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)
									{
									//	simon1->notUseWeapon();
										float x, y;
										listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
										listTorches1.at(i)->GetPosition(x, y);
										effectFire1 = new EffectFire();
										effectFire1->AddAnimation(578);
										effectFire1->AddAnimation(577);
										effectFire1->AddAnimation(576);
										effectFire1->SetPosition(x, y);
										effectFire1->SetState(EFFECT_STATE_ACTIVE);
										effectFire1->itemInside = listTorches1.at(i)->itemInside;
										listEffectFire1.push_back(effectFire1);

										listTorches1.erase(listTorches1.begin() + i);
										i = i - 1;
									}
								}
							}
						}
						if (simon1->holy->CheckCollision(boss) == true)
						{
							if (boss->untouchable == false)
							{
							//	simon1->notUseWeapon();
								float x, y;
								boss->GetPosition(x, y);
								boss->StartUntouchable();
								boss->hp -= 2;


								effectFire1 = new EffectFire();
								effectFire1->AddAnimation(578);
								effectFire1->AddAnimation(577);
								effectFire1->AddAnimation(576);
								effectFire1->SetState(EFFECT_STATE_ACTIVE);
								if (boss->hp == 0)
									effectFire1->itemInside = boss->itemInside;
								effectFire1->SetPosition(x, y);
								effectFire1->type = 0;


								listEffectFire1.push_back(effectFire1);


							}



						}
						for (UINT i = 0; i < listGroundEnemy.size(); i++)
						{

							if (simon1->holy->CheckCollision(listGroundEnemy.at(i)) == true)
							{

								{
									if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
									{
										if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
										{
										//	simon1->notUseWeapon();
											float x, y;
											listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
											listGroundEnemy.at(i)->GetPosition(x, y);
											effectFire1 = new EffectFire();
											effectFire1->AddAnimation(578);
											effectFire1->AddAnimation(577);
											effectFire1->AddAnimation(576);
											effectFire1->SetState(EFFECT_STATE_ACTIVE);
											effectFire1->type = 0;
											effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
											effectFire1->SetPosition(x - 35, y - 5);
											effectFire1->type = 1;
											listEffectFire1.push_back(effectFire1);
											listGroundEnemy.erase(listGroundEnemy.begin() + i);
											i = i - 1;
										}

									}
								}
							}
						}
						for (UINT i = 0; i < listPanther.size(); i++)
						{
							if (simon1->holy->CheckCollision(listPanther.at(i)) == true)
							{
								{
									if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
									{
										//simon1->notUseWeapon();

										float x, y;
										listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
										listPanther.at(i)->GetPosition(x, y);

										effectFire1 = new EffectFire();
										effectFire1->AddAnimation(578);
										effectFire1->AddAnimation(577);
										effectFire1->AddAnimation(576);
										effectFire1->SetPosition(x, y);
										effectFire1->SetState(EFFECT_STATE_ACTIVE);
										effectFire1->itemInside = listPanther.at(i)->itemInside;
										listEffectFire1.push_back(effectFire1);

										listPanther.erase(listPanther.begin() + i);
										i = i - 1;
									}
								}

							}
						}

					}
					else
						if (simon1->holy1->state != HOLYWATER_STATE_INACTIVE &&  simon1->isUsing2ndWeapon == true)
						{
							for (UINT i = 0; i < listEnemy1.size(); i++)
							{
								if (simon1->holy->CheckCollision(listEnemy1.at(i)) == true)
								{
									{
									//	simon1->notUseWeapon2();
										if (listEnemy1.at(i)->state != GHOU_STATE_INACTIVE)
										{

											float x, y;
											listEnemy1.at(i)->SetState(GHOU_STATE_INACTIVE);
											listEnemy1.at(i)->GetPosition(x, y);

											effectFire1 = new EffectFire();
											effectFire1->AddAnimation(578);
											effectFire1->AddAnimation(577);
											effectFire1->AddAnimation(576);
											effectFire1->SetPosition(x, y);
											effectFire1->SetState(EFFECT_STATE_ACTIVE);
											effectFire1->itemInside = listEnemy1.at(i)->itemInside;
											listEffectFire1.push_back(effectFire1);

											listEnemy1.erase(listEnemy1.begin() + i);
											i = i - 1;
										}
									}

								}
							}
							for (UINT i = 0; i < listTorches1.size(); i++)
							{
								if (simon1->holy1->CheckCollision(listTorches1.at(i)) == true)
								{
									{
										if (listTorches1.at(i)->state != TORCH_STATE_INACTIVE)

										{
										//	simon1->notUseWeapon2();
											float x, y;
											listTorches1.at(i)->SetState(TORCH_STATE_INACTIVE);
											listTorches1.at(i)->GetPosition(x, y);

											effectFire1 = new EffectFire();
											effectFire1->AddAnimation(578);
											effectFire1->AddAnimation(577);
											effectFire1->AddAnimation(576);
											effectFire1->SetPosition(x, y);
											effectFire1->SetState(EFFECT_STATE_ACTIVE);
											effectFire1->itemInside = listTorches1.at(i)->itemInside;
											listEffectFire1.push_back(effectFire1);

											listTorches1.erase(listTorches1.begin() + i);
											i = i - 1;
										}
									}
								}
							}
							if (simon1->holy1->CheckCollision(boss) == true)
							{
								if (boss->untouchable == false)
								{
								//	simon1->notUseWeapon2();
									float x, y;
									boss->GetPosition(x, y);
									boss->StartUntouchable();
									boss->hp -= 2;


									effectFire1 = new EffectFire();
									effectFire1->AddAnimation(578);
									effectFire1->AddAnimation(577);
									effectFire1->AddAnimation(576);
									effectFire1->SetState(EFFECT_STATE_ACTIVE);
									if (boss->hp == 0)
										effectFire1->itemInside = boss->itemInside;
									effectFire1->SetPosition(x, y);
									effectFire1->type = 0;


									listEffectFire1.push_back(effectFire1);


								}



							}
							for (UINT i = 0; i < listGroundEnemy.size(); i++)
							{

								if (simon1->holy1->CheckCollision(listGroundEnemy.at(i)) == true)
								{

									{
										if (listGroundEnemy.at(i)->tag == eTag::GROUND_ENEMY)
										{
											if (listGroundEnemy.at(i)->GetState() != TORCH_STATE_INACTIVE)
											{
										//		simon1->notUseWeapon2();
												float x, y;
												listGroundEnemy.at(i)->SetState(TORCH_STATE_INACTIVE);
												listGroundEnemy.at(i)->GetPosition(x, y);
												effectFire1 = new EffectFire();
												effectFire1->AddAnimation(578);
												effectFire1->AddAnimation(577);
												effectFire1->AddAnimation(576);
												effectFire1->SetState(EFFECT_STATE_ACTIVE);
												effectFire1->type = 0;
												effectFire1->itemInside = listGroundEnemy.at(i)->itemInside;
												effectFire1->SetPosition(x - 35, y - 5);
												effectFire1->type = 1;
												listEffectFire1.push_back(effectFire1);
												listGroundEnemy.erase(listGroundEnemy.begin() + i);
												i = i - 1;
											}

										}
									}
								}
							}
							for (UINT i = 0; i < listPanther.size(); i++)
							{
								if (simon1->holy->CheckCollision(listPanther.at(i)) == true)
								{
									{
										//	simon1->notUseWeapon2();
										if (listPanther.at(i)->state != GHOU_STATE_INACTIVE)
										{

											float x, y;
											listPanther.at(i)->SetState(GHOU_STATE_INACTIVE);
											listPanther.at(i)->GetPosition(x, y);

											effectFire1 = new EffectFire();
											effectFire1->AddAnimation(578);
											effectFire1->AddAnimation(577);
											effectFire1->AddAnimation(576);
											effectFire1->SetPosition(x, y);
											effectFire1->SetState(EFFECT_STATE_ACTIVE);
											effectFire1->itemInside = listPanther.at(i)->itemInside;
											listEffectFire1.push_back(effectFire1);

											listPanther.erase(listPanther.begin() + i);
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
				if (listItem1.at(i)->GetState() == ITEM_STATE_DROPPED)
				{

					OutputDebugString(L"Simon and BigHeart \n");
					listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
					simon1->heartCount += 5;
					//if (!dynamic_cast<Ground *>(listItem1.at(i)))//Khong xoa checkbox di de co the di len cau thang qua man khac lai
					{
						listItem1.erase(listItem1.begin() + i);
						i = i - 1;
					}
				}
			}
			else
				if (dynamic_cast<MorningStar *>(listItem1.at(i)))
				{
					if (listItem1.at(i)->GetState() == ITEM_STATE_DROPPED)
					{
						OutputDebugString(L"Simon and WHIP \n");
						listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
						if (simon1->nx == 1)
							simon1->SetState(SIMON_STATE_EAT_RIGHT);
						else
							simon1->SetState(SIMON_STATE_EAT_LEFT);
						simon1->whip->levelUpWhip();
						//if (!dynamic_cast<Ground *>(listItem1.at(i)))//Khong xoa checkbox di de co the di len cau thang qua man khac lai
						{
							listItem1.erase(listItem1.begin() + i);
							i = i - 1;
						}
					}
				}
				else
					if (dynamic_cast<Dagger1 *>(listItem1.at(i)))
					{
						if (listItem1.at(i)->GetState() == ITEM_STATE_DROPPED)
						{
							OutputDebugString(L"Simon and DAGGER \n");
							listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
							simon1->dagger->turnOnDagger();
							simon1->axe->turnOffAxe();
							simon1->clock->turnOffClock();
							simon1->holy->turnOffHolyWater();
							board->typeOfWeaopon = 1;
							OutputDebugString(L"Dagger on \n");
							//if (!dynamic_cast<Ground *>(listItem1.at(i)))//Khong xoa checkbox di de co the di len cau thang qua man khac lai
							{
								listItem1.erase(listItem1.begin() + i);
								i = i - 1;
							}
						}
					}
					else
						if (dynamic_cast<SmallHeart *>(listItem1.at(i)))
						{
							if (listItem1.at(i)->GetState() == ITEM_STATE_DROPPED)
							{
								OutputDebugString(L"Simon and SmallHeart \n");
								listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);

								simon1->heartCount += 1;
								//if (!dynamic_cast<Ground *>(listItem1.at(i)))//Khong xoa checkbox di de co the di len cau thang qua man khac lai
								{
									listItem1.erase(listItem1.begin() + i);
									i = i - 1;
								}
							}
						}
						else
							if (dynamic_cast<GoldBag *>(listItem1.at(i)))
								{
									if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
									{
										OutputDebugString(L"GoldBag \n");
										listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
										GoldBag *newGoldBag = dynamic_cast<GoldBag *>(listItem1.at(i));
										effectBag1->SetPosition(x + 5, y);
										effectBag1->type = newGoldBag->type;
										effectBag1->SetState(EFFECT_STATE_ACTIVE);
										listEffectBag1.push_back(effectBag1);
										if (newGoldBag->type == 0)
										{
											simon1->score += 700;
										}
										else
											if (newGoldBag->type == 1)
											{
												simon1->score += 100;
											}
											else
												if (newGoldBag->type == 2)
												{
													simon1->score += 400;
												}
												else
													if (newGoldBag->type == 3)
													{
														simon1->score += 1000;
													}
										
											listItem1.erase(listItem1.begin() + i);
											i = i - 1;
										
									}

								}
								else
									if (dynamic_cast<Cross1 *>(listItem1.at(i)))
									{
										if (listItem1.at(i)->GetState() == ITEM_STATE_DROPPED)
										{
											OutputDebugString(L"Cross \n");
											listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
											float xc, yc;
											isEatingCross = true;
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
											
												listItem1.erase(listItem1.begin() + i);
												i = i - 1;
											
										}

									}
									else
										if (dynamic_cast<Axe1 *>(listItem1.at(i)))
										{
											if (listItem1.at(i)->GetState() == ITEM_STATE_DROPPED)
											{
												OutputDebugString(L"Simon and Axe \n");
												listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
												simon1->dagger->turnOffDagger();
												simon1->axe->turnOnAxe();
												simon1->clock->turnOffClock();
												simon1->holy->turnOffHolyWater();
												board->typeOfWeaopon = 2;
												OutputDebugString(L"Axe on \n");
												
													listItem1.erase(listItem1.begin() + i);
													i = i - 1;
												
											}
										}
										else
											if (dynamic_cast<HolyWater1 *>(listItem1.at(i)))
											{
												if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
												{
													OutputDebugString(L"Simon and HolyWater \n");
													listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
													simon1->dagger->turnOffDagger();
													simon1->axe->turnOffAxe();
													simon1->clock->turnOffClock();
													simon1->holy->turnOnHolyWater();
													board->typeOfWeaopon = 3;
													OutputDebugString(L"HolyWater on \n");
													
														listItem1.erase(listItem1.begin() + i);
														i = i - 1;
													
												}

											}
											else
												if (dynamic_cast<Clock1 *>(listItem1.at(i)))
												{
													if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
													{
														OutputDebugString(L"Simon and Clock \n");
														listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
														simon1->dagger->turnOffDagger();
														simon1->axe->turnOffAxe();
														simon1->clock->turnOnClock();
														simon1->holy->turnOffHolyWater();
														board->typeOfWeaopon = 4;
														OutputDebugString(L"Clock on \n");
														
															listItem1.erase(listItem1.begin() + i);
															i = i - 1;
														
													}

												}
												else
													if (dynamic_cast<Chicken *>(listItem1.at(i)))
													{
														if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
														{
															OutputDebugString(L"Chicken \n");
															listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
															if (simon1->healthCount <= 14)
																simon1->healthCount += 2;
															else
																if (simon1->healthCount = 15)
																	simon1->healthCount += 1;
															
																
																listItem1.erase(listItem1.begin() + i);
																i = i - 1;
															
														}

													}
													else
														if (dynamic_cast<Numbah *>(listItem1.at(i)))
														{
															if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
															{
																OutputDebugString(L"Numbah \n");
																listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
																simon1->shotTwoWeaponOneTime = true;
															
																	listItem1.erase(listItem1.begin() + i);
																	i = i - 1;
																
															}

														}
														else
															if (dynamic_cast<Potion *>(listItem1.at(i)))
															{
																if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
																{
																	OutputDebugString(L"Numbah \n");
																	listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
																	simon1->StartInvisTime();

																
																		listItem1.erase(listItem1.begin() + i);
																		i = i - 1;
																	
																}

															}
															else
																if (dynamic_cast<Heal *>(listItem1.at(i)))
																{
																	if (listItem1.at(i)->state == ITEM_STATE_DROPPED)
																	{
																		OutputDebugString(L"Numbah \n");
																		listItem1.at(i)->SetState(ITEM_STATE_INACTIVE);
																		simon1->healthCount = simon1->healthCount + (16 - simon1->healthCount);

																		
																			listItem1.erase(listItem1.begin() + i);
																			i = i - 1;
																		
																	}

																}

													

												
	
		}
	}
}

void Scene2::spawnItemsAfterEffect()
{
	for (UINT i = 0; i < listEffectFire1.size(); i++)
	{

		if (listEffectFire1.at(i)->state == EFFECT_STATE_INACTIVE)
		{
			float x, y;
			listEffectFire1.at(i)->GetPosition(x, y);
			if (listEffectFire1.at(i)->type != 0)
			{
				x = x + 35;
				y = y -25;
			}
			switch (listEffectFire1.at(i)->itemInside)
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
				break;
			case numbahInside:
				num = new Numbah();
				num->AddAnimation(935);
				num->SetState(ITEM_STATE_ACTIVE);
				num->SetPosition(x, y);
				listItem1.push_back(num);
				break;
			case potionInside:
				potion = new Potion();
				potion->AddAnimation(987);
				potion->SetState(ITEM_STATE_ACTIVE);
				potion->SetPosition(x, y);
				listItem1.push_back(potion);
				break;
			case healInside:
				heal = new Heal();
				heal->AddAnimation(682);
				heal->SetState(ITEM_STATE_ACTIVE);
				heal->SetPosition(x, y);
				listItem1.push_back(heal);
			default:
				break;
			}

			listEffectFire1.erase(listEffectFire1.begin() + i);// Delete it from effect since Simion killed it
			i = i - 1; // Push back 1 cuz after deleting i+1 will replace i

		}
	}
}

void Scene2::CollisionBetSimonAndEnemy()
{
	//with enemy
	if (simon1->GetState() != SIMON_STATE_HURT_LEFT || simon1->GetState() != SIMON_STATE_HURT_RIGHT)
	{
		for (UINT i = 0; i < listEnemy1.size(); i++)
		{
			float al, at, ar, ab;
			float bl, bt, br, bb;
			listEnemy1.at(i)->GetBoundingBox(al, at, ar, ab);
			simon1->GetBoundingBox(bl, bt, br, bb);

			LPCOLLISIONEVENT e = simon1->SweptAABBEx(listEnemy1.at(i));

			if (e->t > 0 && e->t <= 1.0f)
			{
				{
					
					if (e->nx == -1)
						{

							if (listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_LEFT ||
								listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_RIGHT)
							{

								OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
								if (simon1->isUsing1stWeapon == true)
									simon1->notUseWeapon();
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

						}

						else
							if (e->nx == 1)
							{
								if (listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_LEFT ||
									listEnemy1.at(i)->GetState() == GHOU_STATE_ACTIVE_RIGHT)
								{

									OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
									//if (simon1->isUsingDagger == true)
									//simon1->notUseDagger();
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
											//if (simon1->isUsingDagger == true)
											//	simon1->notUseDagger();
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
												//if (simon1->isUsingDagger == true)
												//	simon1->notUseDagger();
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
				if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
				{
				
					{
						float x, y;
						simon1->GetPosition(x, y);
						float x1, y1;
						listEnemy1.at(i)->GetPosition(x1, y1);
						if (x < x1)
						{
							OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
							if (simon1->isUsing1stWeapon == true)
								simon1->notUseWeapon();
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
								if (simon1->isUsing1stWeapon == true)
									simon1->notUseWeapon();
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
						//simon1->healthCount -= 2;
					}

					if (dynamic_cast<Bat *>(listEnemy1.at(i)))
					{
						listEnemy1.at(i)->SetState(BAT_STATE_INACTIVE);
					}
					if (dynamic_cast<FireBall *> (listEnemy1.at(i)))
					{
						listEnemy1.at(i)->SetState(FIREBALL_STATE_INACTIVE);
					}
				}
		}

		//withboss
		//if (boss->GetState() != BOSS_STATE_INACTIVE)
		//{
		//	float al, at, ar, ab;
		//	float bl, bt, br, bb;
		//	boss->GetBoundingBox(al, at, ar, ab);
		//	simon1->GetBoundingBox(bl, bt, br, bb);

		//	LPCOLLISIONEVENT e = simon1->SweptAABBEx(boss);

		//	if (e->t > 0 && e->t <= 1.0f)
		//	{
		//		if (e->nx == -1)
		//		{

		//			OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
		//			if (simon1->whip->isFinished == false)
		//				simon1->whip->isFinished = true;
		//			if (simon1->isOnStairs == true)
		//			{
		//				simon1->StartUntouchable();
		//			}
		//			else
		//			{
		//				simon1->SetState(SIMON_STATE_HURT_LEFT);

		//			}
		//			//	if (simon1->nx = 1)
		//			//		simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//			//		else if(simon1->nx=-1)
		//			//		simon1->SetState(SIMON_STATE_HURT_LEFT);
		//			//simon->heartCount += 5;


		//		}

		//		else
		//			if (e->nx == 1)
		//			{
		//				OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
		//				//if (simon1->isUsingDagger == true)
		//				//simon1->notUseDagger();
		//				if (simon1->whip->isFinished == false)
		//					simon1->whip->isFinished = true;
		//				if (simon1->isOnStairs == true)
		//				{
		//					simon1->StartUntouchable();
		//				}
		//				else
		//				{
		//					simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//				}
		//			}
		//			else
		//				if (e->nx == 0)
		//				{
		//					if (e->ny == -1)
		//					{
		//						float x, y;
		//						simon1->GetPosition(x, y);
		//						float x1, y1;
		//						boss->GetPosition(x1, y1);
		//						if (x < x1)
		//						{
		//							OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
		//							//if (simon1->isUsingDagger == true)
		//							//	simon1->notUseDagger();
		//							if (simon1->whip->isFinished == false)
		//								simon1->whip->isFinished = true;
		//							if (simon1->isOnStairs == true)
		//							{
		//								simon1->StartUntouchable();
		//							}
		//							else
		//							{
		//								simon1->SetState(SIMON_STATE_HURT_LEFT);
		//							}
		//						}
		//						else
		//							if (x >= x1)
		//							{
		//								OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
		//								//if (simon1->isUsingDagger == true)
		//								//	simon1->notUseDagger();
		//								if (simon1->whip->isFinished == false)
		//									simon1->whip->isFinished = true;

		//								if (simon1->isOnStairs == true)
		//								{
		//									simon1->StartUntouchable();
		//								}
		//								else
		//								{
		//									simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//								}

		//							}
		//					}
		//				}


		//	}
		//	else
		//		if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
		//		{

		//			float x, y;
		//			simon1->GetPosition(x, y);
		//			float x1, y1;
		//			boss->GetPosition(x1, y1);
		//			if (x < x1)
		//			{
		//				OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
		//				//	if (simon1->isUsing1stWeapon == true)
		//				//		simon1->notUseWeapon();
		//				if (simon1->whip->isFinished == false)
		//					simon1->whip->isFinished = true;
		//				if (simon1->isOnStairs == true)
		//				{
		//					simon1->StartUntouchable();
		//				}
		//				else
		//				{
		//					simon1->SetState(SIMON_STATE_HURT_LEFT);
		//				}
		//			}
		//			else
		//				if (x >= x1)
		//				{
		//					OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
		//					//	if (simon1->isUsing1stWeapon == true)
		//					//		simon1->notUseWeapon();
		//					if (simon1->whip->isFinished == false)
		//						simon1->whip->isFinished = true;
		//					if (simon1->isOnStairs == true)
		//					{
		//						simon1->StartUntouchable();
		//					}
		//					else
		//					{
		//						simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//					}
		//				}
		//		}
		//}
		//for (UINT i = 0; i < listPanther.size(); i++)
		//{
		//	float al, at, ar, ab;
		//	float bl, bt, br, bb;
		//	listPanther.at(i)->GetBoundingBox(al, at, ar, ab);
		//	simon1->GetBoundingBox(bl, bt, br, bb);
		//	if (listPanther.at(i)->GetState() == GHOU_STATE_ACTIVE_LEFT ||
		//		listPanther.at(i)->GetState() == GHOU_STATE_ACTIVE_RIGHT)
		//	{
		//		LPCOLLISIONEVENT e = simon1->SweptAABBEx(listPanther.at(i));

		//		if (e->t > 0 && e->t <= 1.0f)
		//		{
		//			if (dynamic_cast<Enemy *>(listPanther.at(i)))
		//			{
		//				if (e->nx == -1)
		//				{


		//					{

		//						OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
		//						//if (simon1->isUsing1stWeapon == true)
		//						//	simon1->notUseWeapon();
		//						if (simon1->whip->isFinished == false)
		//							simon1->whip->isFinished = true;
		//						if (simon1->isOnStairs == true)
		//						{
		//							simon1->StartUntouchable();
		//						}
		//						else
		//						{
		//							simon1->SetState(SIMON_STATE_HURT_LEFT);

		//						}
		//						//	if (simon1->nx = 1)
		//						//		simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//						//		else if(simon1->nx=-1)
		//						//		simon1->SetState(SIMON_STATE_HURT_LEFT);
		//						//simon->heartCount += 5;

		//					}

		//				}

		//				else
		//					if (e->nx == 1)
		//					{

		//						{

		//							OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
		//							//if (simon1->isUsingDagger == true)
		//							//simon1->notUseDagger();
		//							if (simon1->whip->isFinished == false)
		//								simon1->whip->isFinished = true;
		//							if (simon1->isOnStairs == true)
		//							{
		//								simon1->StartUntouchable();
		//							}
		//							else
		//							{
		//								simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//							}


		//						}
		//					}
		//					else
		//						if (e->nx == 0)
		//						{
		//							if (e->ny == -1)
		//							{
		//								float x, y;
		//								simon1->GetPosition(x, y);
		//								float x1, y1;
		//								listPanther.at(i)->GetPosition(x1, y1);
		//								if (x < x1)
		//								{
		//									OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
		//									//if (simon1->isUsingDagger == true)
		//									//	simon1->notUseDagger();
		//									if (simon1->whip->isFinished == false)
		//										simon1->whip->isFinished = true;
		//									if (simon1->isOnStairs == true)
		//									{
		//										simon1->StartUntouchable();
		//									}
		//									else
		//									{
		//										simon1->SetState(SIMON_STATE_HURT_LEFT);
		//									}
		//								}
		//								else
		//									if (x >= x1)
		//									{
		//										OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
		//										//if (simon1->isUsingDagger == true)
		//										//	simon1->notUseDagger();
		//										if (simon1->whip->isFinished == false)
		//											simon1->whip->isFinished = true;

		//										if (simon1->isOnStairs == true)
		//										{
		//											simon1->StartUntouchable();
		//										}
		//										else
		//										{
		//											simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//										}

		//									}
		//							}
		//						}
		//			}
		//		}
		//		else
		//			if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
		//			{

		//				{
		//					float x, y;
		//					simon1->GetPosition(x, y);
		//					float x1, y1;
		//					listPanther.at(i)->GetPosition(x1, y1);
		//					if (x < x1)
		//					{
		//						OutputDebugString(L"RIGHT SIDE: Simon and GHOU  \n");
		//						if (simon1->isUsing1stWeapon == true)
		//							simon1->notUseWeapon();
		//						if (simon1->whip->isFinished == false)
		//							simon1->whip->isFinished = true;
		//						if (simon1->isOnStairs == true)
		//						{
		//							simon1->StartUntouchable();
		//						}
		//						else
		//						{
		//							simon1->SetState(SIMON_STATE_HURT_LEFT);
		//						}
		//					}
		//					else
		//						if (x >= x1)
		//						{
		//							OutputDebugString(L"LEFT SIDE: Simon and GHOU  \n");
		//							if (simon1->isUsing1stWeapon == true)
		//								simon1->notUseWeapon();
		//							if (simon1->whip->isFinished == false)
		//								simon1->whip->isFinished = true;
		//							if (simon1->isOnStairs == true)
		//							{
		//								simon1->StartUntouchable();
		//							}
		//							else
		//							{
		//								simon1->SetState(SIMON_STATE_HURT_RIGHT);
		//							}
		//						}
		//					//simon1->healthCount -= 2;
		//				}
		//			}

		//	}
		//}

	}
	
	


}

int Scene2::CollisionBetSimonAndUpStairs(vector<LPSTAIRS> xStair)
{
	for (UINT i = 0; i < xStair.size(); i++)
	{

		float al, at, ar, ab;
		float bl, bt, br, bb;
		xStair.at(i)->GetBoundingBox(al, at, ar, ab);
		simon1->GetBoundingBox(bl, bt, br, bb);
		//1= right, 2 = left
			if (game1->AABB(al, at, ar, ab, bl, bt, br, bb) == true)
			{
				if (simon1->isOnStairs == true)
				{
					simon1->SetPosition(simon1->x, simon1->y - 2);
					simon1->SetState(SIMON_STATE_IDLE);
					simon1->isOnStairs = false;
				}
				else
					if (simon1->isOnStairs == false)
					{
						if(simon1->y > xStair.at(i)->y+STAIRS_BBOX_HEIGHT-5)
						{
							if (simon1->x > xStair.at(i)->x + 5)
							{
								simon1->SetState(SIMON_STATE_WALKING_LEFT);
							}
							else
								if (simon1->x < xStair.at(i)->x + 3)
								{
									simon1->SetState(SIMON_STATE_WALKING_RIGHT);
								}
								else
									if (simon1->x >= xStair.at(i)->x + 3 ||
										simon1->x <= xStair.at(i)->x + 5)
									{
										if (xStair.at(i)->getType() == 1)
										{
											simon1->SetState(SIMON_STATE_DOWN_RIGHT);
											simon1->directionOnStairs = false;// true=going up, false=going down
										}
										else
											if (xStair.at(i)->getType() == 2)
											{
												simon1->SetState(SIMON_STATE_DOWN_LEFT);
												simon1->directionOnStairs = false;
											}
										simon1->isOnStairs = true;
										return true;
									}

						}
						

					}
				return true;
			}
		}
			return false;

}

int Scene2::CollisionBetSimonAndDownStairs(vector<LPSTAIRS> xStair)
{
	for (UINT i = 0; i < xStair.size(); i++)
	{
		float al, at, ar, ab;
		float bl, bt, br, bb;
		xStair.at(i)->GetBoundingBox(al, at, ar, ab);
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
					if (simon1->x > xStair.at(i)->x + 7)
					{
						simon1->SetState(SIMON_STATE_WALKING_LEFT);
					}
					else
						if (simon1->x < xStair.at(i)->x + 5)
						{
							simon1->SetState(SIMON_STATE_WALKING_RIGHT);
						}
						else
							if (simon1->x >= xStair.at(i)->x + 5 || simon1->x <= xStair.at(i)->x + 7)
							{
								if (xStair.at(i)->getType() == 1)
								{

									simon1->SetState(SIMON_STATE_UP_RIGHT);
									simon1->directionOnStairs = true;// true=going up, false=going down
								}
								else
									if (xStair.at(i)->getType() == 2)
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

void Scene2::CollisionBetSimonAndCheckBox()
{
	for (UINT i = 0; i < listCheckBox1.size(); i++)
	{
		if (simon1->CheckCollision(listCheckBox1.at(i)) == true)
		{

			if (listCheckBox1.at(i)->GetState() == INVIS_STATE_OPENDOOR)
			{

				if (simon1->proceedThruDoor == false)
					simon1->proceedThruDoor = true;



			}
			else
				if (listCheckBox1.at(i)->GetState() == INVIS_STATE_NEXT_LVL_UNDERGROUND)
				{
					if (simon1->GetState() == SIMON_STATE_DOWN_RIGHT)
						stage = 3;

				}
				else
					if (listCheckBox1.at(i)->GetState() == INVIS_STATE_UPPERGROUND)
					{
						if (simon1->GetState() == SIMON_STATE_UP_LEFT)
							stage = 4;
					}
					else
						if (listCheckBox1.at(i)->GetState() == INVIS_STATE_STAGE2)
						{
							if (simon1->GetState() == SIMON_STATE_UP_LEFT)
								stage = 2;
						}
						else
							if (listCheckBox1.at(i)->GetState() == INVIS_STATE_OPENDOOR2)
							{
								if (simon1->proceedThruDoor == false)
									simon1->proceedThruDoor = true;
							}
							else
								if (listCheckBox1.at(i)->GetState() == INVIS_STATE_DIE_BOX)
								{
									simon1->healthCount = 0;
								}
			

		}
	}
}

void Scene2::readTextureFromFileTxt(char * pathOfFile)
{
	int numOfTex, red, green, blue, IDofTex;
	char pathToTexture[1000];

	ifstream inp;
	inp.open(pathOfFile, ios::in);
	inp >> numOfTex;
	for (int i = 0; i < numOfTex; i++)
	{
		//getline(inp, pathToTexString);
		inp.ignore();
		inp.getline(pathToTexture, 1000);
		inp >> red >> green >> blue >> IDofTex;
		textures->Add(IDofTex, pathToTexture, D3DCOLOR_XRGB(red, green, blue));
	}

	inp.close();
}

void Scene2::readCoordiantionsForSpritesFromFileTxt(char * pathOfFile)
{
	int ID, left, top, right, bot, IDofTex;
	int numOfLines;


	ifstream inp;
	inp.open(pathOfFile, ios::in);
	inp >> numOfLines;
	for (int i = 0; i < numOfLines; i++)
	{

		inp >> ID >> left >> top >> right >> bot >> IDofTex;
		LPDIRECT3DTEXTURE9 temp;
		switch (IDofTex)
		{
			
		case ID_TEX_GROUND:
			temp = texGround;
			break;
		case ID_TEX_GROUND2:
			temp = texGround2;
			break;
		case ID_TEX_GROUND3:
			temp = texGround3;
			break;
		case ID_TEX_GROUND4:
			temp = texGround4;
			break;
		case ID_TEX_ITEM_HEAL:
			temp = texHeal;
			break;
			
		case ID_TEX_CANDLE:
			temp = texCandle;
			break;	
		case ID_TEX_DOOR:
			temp = texDoor;
			break;
		case ID_TEX_BAT:
			temp = texBat;
			break;
		case ID_TEX_BOSS:
			temp = texBoss;
			break;
		case ID_TEX_GHOUL:
			temp = texGhoul;
			break;
		case ID_TEX_PANTHER:
			temp = texPant;
			break;
		case ID_TEX_MONSTER:
			temp = texMonster;
			break;
		case ID_TEX_FIREBALL:
			temp = texFire;
			break;
		case ID_TEX_ITEM_SMALLHEART:
			temp = texSHeart;
			break;
		case ID_TEX_ITEM_HOLY:
			temp = texHoly;
			break;
		case ID_TEX_ITEM_POTION:
			temp = texPotion;
			break;
		case ID_TEX_ITEM_NUMBAH:
			temp = texNum;
			break;
		case ID_TEX_ITEM_AXE:
			temp = texAxe;
			break;
		case ID_TEX_ITEM_CROSS:
			temp = texCross;
			break;
		case ID_TEX_ITEM_CHICKEN:
			temp = texChicken;
			break;
		default:
			temp = NULL;
			break;
		}


		sprites->Add(ID, left, top, right, bot, temp);

	}

	inp.close();
}

void Scene2::createAnimationsFromFileTxt(char * pathOfFile)
{
	int NumbOfSprites, time, ID;
	int numOfAnimations;

	ifstream inp;
	inp.open(pathOfFile, ios::in);
	inp >> numOfAnimations;
	for (int i = 0; i < numOfAnimations; i++)
	{

		inp >> NumbOfSprites >> time >> ID;


		//if (ID == 476)
		//{
		//	int xsadasd = 0;
		//}
		int *x = new int[NumbOfSprites];
		for (int i = 0; i < NumbOfSprites; i++)
		{
			inp >> x[i];
		}

		ani = new CAnimation(time);
		for (int i = 0; i < NumbOfSprites; i++)
		{
			ani->Add(x[i]);
		}
		animations->Add(ID, ani);

	}

	inp.close();
}


