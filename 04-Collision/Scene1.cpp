#include "Scene1.h"
#include <iostream>


void Scene1::KeyState(BYTE * states)

{
	if (simon->whip->isFinished == true)
	{

		if (simon->dagger->isFinished == true)
		{
			if (game->IsKeyDown(DIK_RIGHT))
			{

				if (simon->GetState() != SIMON_STATE_JUMP_RIGHT)
					if (simon->isJumping == false)
					{

						if (game->IsKeyDown(DIK_S))
						{
							//if (simon->finishedAttacking == true)
							{

								simon->SetState(SIMON_STATE_ATTACK);
								simon->vx = 0;
								simon->vy = 0;
							}
						}
						else

							if (game->IsKeyDown(DIK_D))
							{
								//if (simon->finishedAttacking == true)

									simon->SetState(SIMON_STATE_THROW);

							}
							else
								simon->SetState(SIMON_STATE_WALKING_RIGHT);
					}
				//else
				//	simon->SetState(SIMON_STATE_JUMP_RIGHT);
			}
			else
				if (game->IsKeyDown(DIK_LEFT))
				{
					if (simon->GetState() != SIMON_STATE_JUMP_LEFT)
						if (simon->isJumping == false)
						{
							if (game->IsKeyDown(DIK_S))
							{
								//if (simon->finishedAttacking == true)
								{
									simon->SetState(SIMON_STATE_ATTACK);
									simon->vx = 0;
									simon->vy = 0;
								}
							}
							else
								if (game->IsKeyDown(DIK_D))
								{
									//if (simon->finishedAttacking == true)
									{
										simon->SetState(SIMON_STATE_THROW);
									}
								}

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
						if (simon->isJumping == false)
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
		if (simon->proceedThruDoor == false)
		{
			if (simon->isOnStairs == false)
			{

				if (simon->isJumping == false)
				{
					if (simon->GetState() == SIMON_STATE_WALKING_LEFT)
						simon->SetState(SIMON_STATE_JUMP_LEFT);
					else
						if (simon->GetState() == SIMON_STATE_WALKING_RIGHT)
							simon->SetState(SIMON_STATE_JUMP_RIGHT);
						else
							simon->SetState(SIMON_STATE_JUMP);
					simon->isJumping = true;
				}
			}
		}
		break;
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
		//if (simon->GetState() ==)
		if (simon->eatingItem == false)
		{
		//	if (simon->finishedAttacking == true)
			{
				if (simon->GetState() == SIMON_STATE_SIT)
				{
					simon->SetState(SIMON_STATE_ATTACK_SITTING);
					simon->whip->CreateWeapon(simon->x, simon->y + 7, simon->nx);
//simon->finishedAttacking = false;
				}

				else
				{
					simon->SetState(SIMON_STATE_ATTACK);
					simon->whip->CreateWeapon(simon->x, simon->y, simon->nx);
					//simon->finishedAttacking = false;

				}
			}
		}



		break;
	case DIK_D:
		//	if (simon->GetState() != SIMON_STATE_WALKING_LEFT && simon->GetState() != SIMON_STATE_WALKING_RIGHT)
		if (simon->eatingItem == false)

		{
		//	if (simon->finishedAttacking == true)
			{
				if (simon->dagger->isOn == true)
				{
					simon->numOfWeapon = 1;
					if (simon->heartCount > 0)
					{
						if (simon->dagger->GetState() == DAGGER_STATE_INACTIVE)
						{
					//		simon->finishedAttacking = false;
							simon->heartCount -= 1;

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
	//Load Sounds
	sound->playSound(eTagSound::Stage1, true);
	readTextureFromFileTxt("textures\\Textures1.txt");
	map = new Map(ID_TEX_MAP1, "textures\\Map\\Map1.csv");
	//Ground 0
	texBoard = textures->Get(ID_TEX_BOARD);
	texEffect = textures->Get(ID_TEX_EFFECT);
	texEffectBrick = textures->Get(ID_TEX_EFFECT1);
	texEffectWater = textures->Get(ID_TEX_EFFECT2);
	texEffectBag = textures->Get(ID_TEX_ITEM_POTION);
	texSimon2 = textures->Get(ID_TEX_SIMON2);
	texMario = textures->Get(ID_TEX_SIMON);
	texMarioDeath = textures->Get(ID_TEX_SIMON_DEATH);
	texTorch = textures->Get(ID_TEX_TORCH);
	texWhip = textures->Get(ID_TEX_WHIP);
	texItemSword = textures->Get(ID_TEX_ITEM_SWORD);
	texAxe = textures->Get(ID_TEX_AXE);
	texHolyWater = textures->Get(ID_TEX_HOLYWATER);
	texItemBigHeart = textures->Get(ID_TEX_ITEM_BIGHEART);
	texItemWhip = textures->Get(ID_TEX_ITEM_WHIP);
	texGoldBag = textures->Get(ID_TEX_ITEM_GOLD);
	texClock = textures->Get(ID_TEX_ITEM_CLOCK);

	readCoordiantionsForSpritesFromFileTxt("textures\\Coordinations1.txt");
	createAnimationsFromFileTxt("textures\\CreateAnimations1.txt");

#pragma region Adding Effects

	effect->AddAnimation(578);

#pragma endregion

	effectBag->AddAnimation(579);
	effectBag->AddAnimation(580);
	effectBag->AddAnimation(581);
	effectBag->AddAnimation(582);
#pragma region Adding Simon

	simon = new Simon();
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

	simon->AddAnimation(332);		// AFK Up right
	simon->AddAnimation(331);		// AFK up left 
	simon->AddAnimation(224);		// AFK down right
	simon->AddAnimation(223);		// AFK down left 

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

#pragma region Adding BigHeart

	bigheart->AddAnimation(765);

#pragma endregion

#pragma region Adding Item Dagger

	simon->dagger->AddAnimation(767); //left
	simon->dagger->AddAnimation(766); //right

	simon->dagger1->AddAnimation(767);
	simon->dagger1->AddAnimation(766);

	dagger->AddAnimation(767);

#pragma endregion

#pragma region Adding Axe

	simon->axe->AddAnimation(254);
	simon->axe->AddAnimation(253);
	simon->axe1->AddAnimation(254);
	simon->axe1->AddAnimation(253);

#pragma endregion

#pragma region Adding HolyWater

	simon->holy->AddAnimation(232);
	simon->holy->AddAnimation(233);
	simon->holy->AddAnimation(234);
	simon->holy1->AddAnimation(232);
	simon->holy1->AddAnimation(233);
	simon->holy1->AddAnimation(234);

#pragma endregion 

#pragma region Adding Item Morning Star

	morningstar = new MorningStar();
	morningstar->AddAnimation(777);

#pragma endregion

#pragma region Adding Item Bag of Gold

	goldbag->AddAnimation(778);
	goldbag->AddAnimation(779);
	goldbag->AddAnimation(780);
	goldbag->AddAnimation(781);

#pragma endregion

	newBoard->SetPosition(0, 0);
	newBoard->typeOfWeaopon = 0;

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

			if ((simon->dagger->x) < x1 || (simon->dagger->x) > (x1 + SCREEN_WIDTH))// set lai dagger is not being used neu bay qua man hinh
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
		{

			sound->GetInstance()->stopSound(eTagSound::Stage1);
			SceneManager::GetInstance()->replaceScene(new Scene2(simon));
		}
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
	sound = SoundManager::GetInstance();
	newGrid = new Grid();
	time = new Time();
	camera = Camera::GetInstance();
	textures = CTextures::GetInstance();
	sprites = CSprites::GetInstance();
	animations = CAnimations::GetInstance();
	proceedToLvl2 = false;
	effect = new EffectFire();
	dagger = new Dagger1();
	goldbag = new GoldBag(3);
	newBoard = new Board();
	bigheart = new BigHeart();
	effectBag = new EffectBag();
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

void Scene1::readTextureFromFileTxt(char * pathOfFile)
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

void Scene1::readCoordiantionsForSpritesFromFileTxt(char * pathOfFile)
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

		case ID_TEX_BOARD:
			temp = texBoard;
			break;
		case ID_TEX_EFFECT:
			temp = texEffect;
			break;
		case ID_TEX_EFFECT1:
			temp = texEffectBrick;
			break;
		case ID_TEX_EFFECT2:
			temp = texEffectWater;
			break;
		case ID_TEX_ITEM_POTION:
			temp = texEffectBag;
			break;
		case ID_TEX_SIMON2:
			temp = texSimon2;
			break;
		case ID_TEX_SIMON:
			temp = texMario;
			break;
		case ID_TEX_SIMON_DEATH:
			temp = texMarioDeath;
			break;
		case ID_TEX_TORCH:
			temp = texTorch;
			break;
		case ID_TEX_WHIP:
			temp = texWhip;
			break;
		case ID_TEX_ITEM_SWORD:
			temp = texItemSword;
			break;
		case ID_TEX_AXE:
			temp = texAxe;
			break;
		case ID_TEX_HOLYWATER:
			temp = texHolyWater;
			break;
		case ID_TEX_ITEM_BIGHEART:
			temp = texItemBigHeart;
			break;
		case ID_TEX_ITEM_WHIP:
			temp = texItemWhip;
			break;
		case ID_TEX_ITEM_GOLD:
			temp = texGoldBag;
			break;
		case ID_TEX_ITEM_CLOCK:
			temp = texClock;
			break;
		default:
			temp = NULL;
			break;
		}


		sprites->Add(ID, left, top, right, bot, temp);

	}

	inp.close();
}

void Scene1::createAnimationsFromFileTxt(char * pathOfFile)
{
	int NumbOfSprites, time, ID;
	int numOfAnimations;

	ifstream inp;
	inp.open(pathOfFile, ios::in);
	inp >> numOfAnimations;
	for (int i = 0; i < numOfAnimations; i++)
	{

		inp >> NumbOfSprites >> time >> ID;
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

					sound->playSound(eTagSound::Hit, false);
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
						sound->playSound(eTagSound::Hit, false);
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

					sound->playSound(eTagSound::CollItem, false);
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
						sound->playSound(eTagSound::COllWeapon, false);
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
							sound->playSound(eTagSound::COllWeapon, false);
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
									sound->playSound(eTagSound::CollItem, false);
									OutputDebugString(L"GoldBag \n");
									listItem.at(i)->SetState(ITEM_STATE_INACTIVE);
									GoldBag *newGoldBag = dynamic_cast<GoldBag *>(listItem.at(i));
									float x, y;
									newGoldBag->GetPosition(x, y);
									effectBag->SetPosition(x + 5, y);
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



