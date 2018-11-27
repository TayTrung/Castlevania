#include "Scene1.h"


CGame *game = CGame::GetInstance();
Ground *ground, *invisBox, *invisBox2;
Camera *camera;
Simon *simon;
Map *map;
vector<LPGAMEOBJECT> Enemy;
int tickHeart;
int tickWhip;
vector<LPGAMEOBJECT> Item;
vector<LPGAMEOBJECT> Surface;
GoldBag *goldbag;
Torch *torch;
Dagger1 *dagger;
MorningStar	*morningstar;
BigHeart *bigheart;

void Scene1::KeyState(BYTE * states)

{
	if (simon->whip->isFinished == true)
	{


		if (game->IsKeyDown(DIK_RIGHT))
		{
			if (game->IsKeyDown(DIK_S))
				simon->SetState(SIMON_STATE_ATTACK);
			else
				simon->SetState(SIMON_STATE_WALKING_RIGHT);
		}
		else
			if (game->IsKeyDown(DIK_LEFT))
			{
				if (game->IsKeyDown(DIK_S))
					simon->SetState(SIMON_STATE_ATTACK);
				else
					simon->SetState(SIMON_STATE_WALKING_LEFT);
			}
			else
				if (game->IsKeyDown(DIK_DOWN))
				{
					/*	if (game->IsKeyDown(DIK_S))
					simon->SetState(SIMON_STATE_ATTACK_SITTING);
					else*/
					simon->SetState(SIMON_STATE_SIT);
				}
				else
					if (game->IsKeyDown(DIK_SPACE))
					{
						if (simon->isJumping == false)
						{
							simon->SetState(SIMON_STATE_JUMP);
							simon->isJumping = true;
						}
					}
					else
					{
						simon->SetState(SIMON_STATE_IDLE);

					}
	}

}

void Scene1::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
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
		if (simon->GetState() == SIMON_STATE_SIT)
		{
			simon->SetState(SIMON_STATE_ATTACK_SITTING);
			simon->whip->CreateWeapon(simon->x, simon->y+7, simon->nx);

		}
		else
		{
			simon->SetState(SIMON_STATE_ATTACK);
			simon->whip->CreateWeapon(simon->x, simon->y, simon->nx);

		}
			
		break;
	case DIK_D:
		if (simon->dagger->isOn == true)
		{
			if (simon->dagger->GetState() == DAGGER_STATE_INACTIVE)
			{

				float x, y;
				simon->GetPosition(x, y);
				if (simon->GetState() == SIMON_STATE_SIT)
				{
					simon->dagger->CreateWeapon(x, y+7, simon->nx);

					if (simon->isUsingDagger == false)
					{
						if (simon->nx > 0)
							simon->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
						else
							simon->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
						simon->SetState(SIMON_STATE_THROW_SITTING);
						simon->useDagger();

					}
				
				}
				else
				{


					simon->dagger->CreateWeapon(x, y, simon->nx);

					if (simon->isUsingDagger == false)
					{
						if (simon->nx > 0)
							simon->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
						else
							simon->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
						simon->SetState(SIMON_STATE_THROW);
						simon->useDagger();

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


	tickHeart = 0;
	tickWhip = 0;
	camera = Camera::GetInstance();
	CTextures * textures = CTextures::GetInstance();
	CSprites * sprites = CSprites::GetInstance();
	CAnimations * animations = CAnimations::GetInstance();
	LPANIMATION ani;
	textures->Add(ID_TEX_MAP1, L"textures\\Map\\Map1.png", D3DCOLOR_XRGB(255, 0, 255));
	map = new Map(ID_TEX_MAP1, "textures\\Map\\Map1.csv");


	//Objects
	textures->Add(ID_TEX_SIMON, L"textures\\simon.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_GROUND, L"textures\\Ground\\ground1.png", D3DCOLOR_XRGB(176, 224, 248));
	textures->Add(ID_TEX_TORCH, L"textures\\Enemy\\0.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_WHIP, L"textures\\Weapon\\morningstar.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_BBOX, L"textures\\bbox.png", D3DCOLOR_XRGB(255, 255, 255));
	//Items
	textures->Add(ID_TEX_ITEM_BIGHEART, L"textures\\Item\\1.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_WHIP, L"textures\\Item\\3.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_SWORD, L"textures\\Item\\4.png", D3DCOLOR_XRGB(255, 0, 255));
	textures->Add(ID_TEX_ITEM_GOLD, L"textures\\Item\\2.png", D3DCOLOR_XRGB(255, 0, 255));

#pragma region Co-ordinations of Simon
	LPDIRECT3DTEXTURE9 texMario = textures->Get(ID_TEX_SIMON);
	
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



	/*Idle left
	sprites->Add(10011, 12, 2, 43, 63, texMario);

	Walking left		
	sprites->Add(10003, 78, 2, 109, 63, texMario);
	sprites->Add(10004, 134, 2, 165, 63, texMario);
	sprites->Add(10005, 196, 2, 227, 63, texMario);

	Sitting left
	sprites->Add(10007, 252, 2, 283, 63, texMario);

	Attacking left
	sprites->Add(10101, 312, 2, 359, 63, texMario);
	sprites->Add(10102, 373, 2, 404, 63, texMario);
	sprites->Add(10103, 421, 2, 463, 63, texMario);

	Sitting Attacking left
	sprites->Add(10201, 432, 69, 480, 130, texMario);
	sprites->Add(10202, 11, 133, 42, 194, texMario);
	sprites->Add(10203, 62, 133, 104, 194, texMario);

	 Right
	idle right
	sprites->Add(10012, 436, 200, 467, 261, texMario);

	Walking right		
	sprites->Add(10013, 378, 200, 409, 261, texMario);
	sprites->Add(10014, 314, 200, 345, 261, texMario);
	sprites->Add(10015, 252, 200, 291, 261, texMario);

	Sitting right
	sprites->Add(10017, 196, 200, 227, 261, texMario);

	Attacking right
	sprites->Add(10104, 120, 200, 167, 261, texMario);
	sprites->Add(10105, 75, 200, 106, 261, texMario);
	sprites->Add(10106, 16, 200, 58, 261, texMario);

	Sitting Attacking right 
	sprites->Add(10204, 0, 266, 47, 327, texMario);
	sprites->Add(10205, 437, 332, 468, 393, texMario);
	sprites->Add(10206, 375, 332, 418, 393, texMario);*/

#pragma endregion

#pragma region Co-ordinations of Ground

	LPDIRECT3DTEXTURE9 texGround = textures->Get(ID_TEX_GROUND);
	sprites->Add(20001, 0, 0, 16, 16, texGround);

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

	////VAMPIRE_KILLLER
	////LEFT
	//sprites->Add(30000, 136, 18, 151, 65, texWhip);
	//sprites->Add(30001, 280, 12, 311, 49, texWhip);
	//sprites->Add(30002, 352, 16, 395, 31, texWhip);

	////RIGHT
	//sprites->Add(30003, 488, 222, 503, 269, texWhip);
	//sprites->Add(30004, 328, 216, 359, 253, texWhip);
	//sprites->Add(30005, 244, 220, 287, 237, texWhip);
	////NOTHING
	//sprites->Add(30006, 0, 0, 1, 1, texWhip);




	////CHAIN WHIP
	////LEFT
	//sprites->Add(30010, 136, 86, 151, 133, texWhip);
	//sprites->Add(30011, 280, 80, 311, 117, texWhip);
	//sprites->Add(30012, 352, 90, 397, 101, texWhip);

	////RIGHT
	//sprites->Add(30013, 488, 290, 503, 337, texWhip);
	//sprites->Add(30014, 328, 284, 359, 321, texWhip);
	//sprites->Add(30015, 244, 294, 287, 305, texWhip);

	////MORNING_STAR
	////LEFT
	//sprites->Add(30020, 136, 154, 151, 201, texWhip);
	//sprites->Add(30021, 280, 148, 311, 185, texWhip);
	//sprites->Add(30022, 320, 158, 400, 169, texWhip);

	////RIGHT
	//sprites->Add(30023, 488, 358, 503, 405, texWhip);
	//sprites->Add(30024, 328, 352, 359, 389, texWhip);
	//sprites->Add(30025, 244, 362, 319, 373, texWhip);
#pragma endregion

#pragma region Co-ordinations of Dagger and Item Dagger

	LPDIRECT3DTEXTURE9 texItemSword = textures->Get(ID_TEX_ITEM_SWORD);
	sprites->Add(00002, 0, 0, 16, 8, texItemSword);//right


	sprites->Add(00003, 0, 9, 17, 18, texItemSword);//left

#pragma endregion	

#pragma region Co-ordinations of Item Big Heart

	LPDIRECT3DTEXTURE9 texItemBigHeart = textures->Get(ID_TEX_ITEM_BIGHEART);
	sprites->Add(00000, 0, 0, 12, 10, texItemBigHeart);

#pragma endregion

#pragma region Co-ordinations of Item Morning Star

	LPDIRECT3DTEXTURE9 texItemWhip = textures->Get(ID_TEX_ITEM_WHIP);
	sprites->Add(00001, 0, 0, 16, 16, texItemWhip);

#pragma endregion	

#pragma region Co-ordinations of Bag of Gold

	LPDIRECT3DTEXTURE9 texGoldBag = textures->Get(ID_TEX_ITEM_GOLD);
	sprites->Add(00004, 0, 0, 14, 14, texGoldBag); //red gold
	sprites->Add(00005, 15, 0, 29, 14, texGoldBag); // white gold
	sprites->Add(00006, 30, 0, 44, 14, texGoldBag); // blue gold

#pragma endregion

#pragma region Adding Animations for Simon

	ani = new CAnimation(300);	// idle right
	ani->Add(10012);
	animations->Add(400, ani);

	ani = new CAnimation(300);	// idle left
	ani->Add(10011);
	animations->Add(401, ani);

	ani = new CAnimation(300);	// Walking right
	ani->Add(10013);
	ani->Add(10014);
	ani->Add(10015);
	animations->Add(402, ani);

	ani = new CAnimation(300);	// Walking left
	ani->Add(10003);
	ani->Add(10004);
	ani->Add(10005);
	animations->Add(403, ani);

	ani = new CAnimation(300);	// Sitting right
	ani->Add(10017);
	animations->Add(500, ani);

	ani = new CAnimation(300);	// Sitting left
	ani->Add(10007);
	animations->Add(501, ani);


	ani = new CAnimation(300);	// Jumping right
	ani->Add(10017);
	animations->Add(600, ani);

	ani = new CAnimation(300);	// Jumping left
	ani->Add(10007);
	animations->Add(601, ani);

	ani = new CAnimation(300);	// Attacking right
	ani->Add(10104);
	ani->Add(10105);
	ani->Add(10106);
	ani->Add(10012);
	animations->Add(700, ani);

	ani = new CAnimation(300);	// Attacking left
	ani->Add(10101);
	ani->Add(10102);
	ani->Add(10103);
	ani->Add(10011);
	animations->Add(701, ani);

	ani = new CAnimation(300);	// Sitting Attacking right
	ani->Add(10204);
	ani->Add(10205);
	ani->Add(10206);
	ani->Add(10017);
	animations->Add(800, ani);

	ani = new CAnimation(300);	// Sitting Attacking left
	ani->Add(10201);
	ani->Add(10202);
	ani->Add(10203);
	ani->Add(10007);
	animations->Add(801, ani);



#pragma region Adding Animation for Whip //de trong simon vì bên duoi co new simon
	// lvl1
	ani = new CAnimation(300); //Left
	ani->Add(30000);
	ani->Add(30001);
	ani->Add(30002);
	ani->Add(30006);
	animations->Add(710, ani);

	ani = new CAnimation(300); //Right
	ani->Add(30003);
	ani->Add(30004);
	ani->Add(30005);
	ani->Add(30006);
	animations->Add(711, ani);


	//lvl2
	ani = new CAnimation(300); //Left
	ani->Add(30010);
	ani->Add(30011);
	ani->Add(30012);
	ani->Add(30006);
	animations->Add(712, ani);

	ani = new CAnimation(300); //Right
	ani->Add(30013);
	ani->Add(30014);
	ani->Add(30015);
	ani->Add(30006);
	animations->Add(713, ani);
	//lvl3
	ani = new CAnimation(300); //Left
	ani->Add(30020);
	ani->Add(30021);
	ani->Add(30022);
	ani->Add(30006);
	animations->Add(714, ani);

	ani = new CAnimation(300); //Right
	ani->Add(30023);
	ani->Add(30024);
	ani->Add(30025);
	ani->Add(30006);
	animations->Add(715, ani);



	//whip[0]->AddAnimation(700);
	//whip[0]->AddAnimation(701);
	//whip[0]->AddAnimation(706);

	//whip[1]->AddAnimation(702);
	//whip[1]->AddAnimation(703);
	//whip[1]->AddAnimation(706);

	//whip[2]->AddAnimation(704);
	//whip[2]->AddAnimation(705);
	//whip[2]->AddAnimation(706);


#pragma endregion	

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

	simon->SetPosition(50.0f, 0);
	//objects.push_back(mario);
#pragma endregion 	

#pragma region Adding Ground

	ani = new CAnimation(100);
	ani->Add(20001);


	animations->Add(999, ani);

	for (int i = 0; i < 65; i++)
	{
		ground = new Ground(0);
		ground->AddAnimation(999);
		ground->SetPosition(0 + i * 16.0f, offsetMap+144);
		Surface.push_back(ground);
	}
	invisBox = new Ground(1);
	invisBox->AddAnimation(999);
	invisBox->SetPosition(689, 125+offsetMap);
	invisBox->SetState(INVIS_STATE_NEXT_LVL);
	Item.push_back(invisBox);

	invisBox2 = new Ground(1);
	invisBox2->AddAnimation(999);
	invisBox2->SetPosition(MAP1_WIDTH - 24, offsetMap + 140);
	invisBox2->SetState(INVIS_STATE_INVIS_ITEM);
	Item.push_back(invisBox2);


#pragma endregion

#pragma region Adding Torch

	ani = new CAnimation(100);
	ani->Add(40001);
	ani->Add(40002);
	animations->Add(901, ani);

	for (int i = 0; i < 5; i++)
	{
		torch = new Torch(0);
		torch->AddAnimation(901);

		
			torch->SetPosition(110 + i * 130, offsetMap + 144 - TORCH_BBOX_HEIGHT);
			if (i == 0 || i == 3)
				torch->setItemInside(bigheartInside);

			if (i == 1 || i == 2)
				torch->setItemInside(morningstarInside);

			if (i == 4)
				torch->setItemInside(daggerInside);

			
		Enemy.push_back(torch);
	}


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

	dagger = new Dagger1();
	dagger->AddAnimation(767);

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


	goldbag = new GoldBag();
	goldbag->AddAnimation(778);
	

#pragma endregion
}

void Scene1::Update(DWORD dt)
{
	float x1, y1;
	x1 = Camera::GetInstance()->GetPosition().x;
	y1 = Camera::GetInstance()->GetPosition().y;

	if ((simon->dagger->x)<x1 || (simon->dagger->x)>(x1 + SCREEN_WIDTH))// set lai dagger is not being used neu bay qua man hinh
	{
	//	simon->dagger->SetState(DAGGER_STATE_INACTIVE);
		simon->notUseDagger();
	}

	CollisionBetWeaponAndEnemy();
	for (int i = 0; i < Item.size(); i++)
	{
		if (Item.at(i)->GetState() == ITEM_STATE_ACTIVE);
		Item.at(i)->Update(dt, &Surface);
	}
	
	if (goldbag->GetState() == ITEM_STATE_ACTIVE)
		goldbag->Update(dt, &Surface);

	simon->Update(dt, &Surface);
	
	if ((simon->dagger->GetState() != DAGGER_STATE_INACTIVE) && simon->dagger->isOn == true && simon->isUsingDagger == true)//updating dagger when being used
		simon->dagger->Update(dt, &Surface);

	camera->SetPosition(simon->x - SCREEN_WIDTH / 2, 0); // cho camera chay theo simon
	camera->Update();
	CollisionBetSimonAndItem();

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
		map->drawTileMap(camera, ID_TEX_MAP1);
		//All items are rendered if state = active
		for (int i = 0; i < Surface.size(); i++)//render surface
			Surface[i]->Render();

		for (int i = 0; i < Enemy.size(); i++)//render torches
			Enemy[i]->Render();

		for (int i = 0; i < Item.size(); i++)//render ietms
			Item[i]->Render();

		goldbag->Render();
		//
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

Scene1::Scene1()
{
	LoadResources();
}


Scene1::~Scene1()
{

}

void Scene1::CollisionBetWeaponAndEnemy()
{


	if (simon->whip->isFinished == false && simon->whip->isAllowedToCollide == true)
	{
		for (UINT i = 0; i < Enemy.size(); i++)
		{

			if (simon->whip->CheckCollision(Enemy.at(i)) == true)
			{
				if (Enemy.at(i)->state == TORCH_STATE_ACTIVE)
				{
					float x, y;
					OutputDebugString(L"Collision Whip and Candle \n");
					Enemy.at(i)->SetState(TORCH_STATE_INACTIVE);
					Enemy.at(i)->GetPosition(x, y);

					
					
					
					switch (Enemy.at(i)->itemInside)
					{
					case 0:
						break;
					case bigheartInside:
						bigheart->SetState(ITEM_STATE_ACTIVE);
						bigheart->SetPosition(x, y);
						Item.push_back(bigheart);
	//					tickHeart += 1;
				
						break;
					case morningstarInside:
						morningstar->SetState(ITEM_STATE_ACTIVE);
						morningstar->SetPosition(x, y);
						Item.push_back(morningstar);
		//				tickWhip += 1;
						break;
					case daggerInside:
						dagger->SetState(ITEM_STATE_ACTIVE);
						dagger->SetPosition(x, y);
						Item.push_back(dagger);
						break;
					case smallheartInside:
						break;
					default:
						break;
					}


					Enemy.erase(Enemy.begin() + i);// Delete it from enemy since Simion killed it

					i = i - 1; // Push back 1 cuz after deleting i+1 will replace i

				}

			}
		}
	}
	else 
		if (simon->dagger->state != DAGGER_STATE_INACTIVE && simon->dagger->isOn == true && simon->isUsingDagger == true)
		{
			for (UINT i = 0; i < Enemy.size(); i++)
			{

				if (simon->dagger->CheckCollision(Enemy.at(i)) == true)
				{
					if (Enemy.at(i)->state == TORCH_STATE_ACTIVE)
					{
						float x, y;
						OutputDebugString(L"Collision Dagger and Candle \n");
						Enemy.at(i)->SetState(TORCH_STATE_INACTIVE);
						Enemy.at(i)->GetPosition(x, y);
						simon->dagger->SetState(DAGGER_STATE_INACTIVE);
						simon->notUseDagger();


						switch (Enemy.at(i)->itemInside)
						{
						case 0:
							break;
						case bigheartInside:
							bigheart->SetState(ITEM_STATE_ACTIVE);
							bigheart->SetPosition(x, y);
							Item.push_back(bigheart);
							tickHeart += 1;
							break;
						case morningstarInside:
							morningstar->SetState(ITEM_STATE_ACTIVE);
							morningstar->SetPosition(x, y);
							Item.push_back(morningstar);
							tickWhip += 1;
							break;
						case daggerInside:
							dagger->SetState(ITEM_STATE_ACTIVE);
							dagger->SetPosition(x, y);
							Item.push_back(dagger);
							break;
						case smallheartInside:
							break;
						default:
							break;
						}
						Enemy.erase(Enemy.begin() + i);// Delete it from enemy since Simion killed it

						i = i - 1; // Push back 1 cuz after deleting i+1 will replace i
					}

				}
			}
		}
}




void Scene1::CollisionBetSimonAndItem()
{
	for (UINT i = 0; i < Item.size(); i++)
	{
		if (simon->CheckCollision(Item.at(i)) == true)
		{
			if (dynamic_cast<BigHeart *>(Item.at(i)))
			{
				if (Item.at(i)->state == ITEM_STATE_ACTIVE)
				{

					OutputDebugString(L"Simon and BigHeart \n");
					Item.at(i)->SetState(ITEM_STATE_INACTIVE);
					//simon->heartCount += 5;

				}
			}
			else
				if (dynamic_cast<MorningStar *>(Item.at(i)))
				{
					if (Item.at(i)->state == ITEM_STATE_ACTIVE)
					{
						OutputDebugString(L"Simon and WHIP \n");
						Item.at(i)->SetState(ITEM_STATE_INACTIVE);
						simon->whip->levelUpWhip();
					}
				}
				else
					if (dynamic_cast<Dagger1 *>(Item.at(i)))
					{
						if (Item.at(i)->state == ITEM_STATE_ACTIVE)
						{
							OutputDebugString(L"Simon and DAGGER \n");
							Item.at(i)->SetState(ITEM_STATE_INACTIVE);
							simon->dagger->turnOnDagger();
							OutputDebugString(L"Dagger on \n");
						}
					}
					else
						if (dynamic_cast<Ground *>(Item.at(i)))
						{
							if (Item.at(i)->state == INVIS_STATE_NEXT_LVL)
							{
								
								OutputDebugString(L"Proceed to lvl 2 \n");
								SceneManager::GetInstance()->replaceScene(new Scene2(simon));
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
								if (Item.at(i)->state == INVIS_STATE_INVIS_ITEM)
								{
									OutputDebugString(L"Invis item appear \n");
									Item.at(i)->SetState(INVIS_STATE_INACTIVE);
									goldbag->SetPosition(660, 125 + offsetMap);
									goldbag->SetState(ITEM_STATE_ACTIVE);
									Item.push_back(goldbag);
								}
						}
						else
							if (dynamic_cast<GoldBag *>(Item.at(i)))
							{
								if (Item.at(i)->state == ITEM_STATE_ACTIVE)
								{
									OutputDebugString(L"GoldBag \n");
									Item.at(i)->SetState(ITEM_STATE_INACTIVE);
								}
							
							}
			Item.erase(Item.begin() + i);
			i = i - 1;
		}
	}
}



