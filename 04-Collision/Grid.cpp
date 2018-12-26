#include "Grid.h"



Grid::Grid()
{
	count = 0;
}


Grid::~Grid()
{
}

void Grid::insertObjectIntoGrid(CGameObject * object)
{
	count++;
	object->id = count;

	float x1, y1, x2, y2;
	object->GetPosition(x1, y1);
	// lay bounding box de biet diem right bot nam o dau de xac dinh o cuoi
	object->GetBoundingBox(x1, y1, x2, y2);
	int cellCol1, cellRow1,cellCol2,cellRow2;
	// xac dinh diem top left nam trong cell nao cua grid
	cellCol1 = x1 / CELL_WIDTH;
	cellRow1 = y1 / CELL_HEIGHT;
	//same with right bot
	
	cellCol2 = x2 / CELL_WIDTH;
	cellRow2 = y2 / CELL_HEIGHT;

	//if (fmod(x2, CELL_WIDTH) == 2)
	//	cellCol2 = cellCol2 - 1;

//	if (fmod(y2, CELL_HEIGHT) == 0)
	//	cellRow2 = cellRow2 - 1;
	//loop to pushback object
	for (int i = cellCol1; i <= cellCol2; i++)
	{
		for (int j = cellRow1; j <= cellRow2; j++)
		{
			grid[j][i].push_back(object);
		}
	}
	


}

void Grid::getListOfObjects(vector<LPGAMEOBJECT>& listOfObj, Camera * cam)
{
	listOfObj.clear();//cler list moi lan lay lai danh sách possible collision

	unordered_map<int, LPGAMEOBJECT> luoi;
	
	float xCam, yCam,xCam2,yCam2;
	xCam=cam->GetPosition().x;
	yCam = cam->GetPosition().y;
	xCam2 = xCam + SCREEN_WIDTH;
	yCam2 = yCam + SCREEN_HEIGHT;

	int camPosX, camPosY, camPosX2, camPosY2;
	//position của diem left top camera trong grid
	camPosX = xCam / CELL_WIDTH;
	camPosY = yCam / CELL_HEIGHT;
	//position của diem right bot camera trong grid
	camPosX2 = xCam2 / CELL_WIDTH;
	camPosY2 = yCam2 / CELL_HEIGHT;

	if (fmod(xCam2, CELL_WIDTH) == 0)
	{
		camPosX2 -= 1;
	}
	if (fmod(yCam2, CELL_HEIGHT) == 0)
	{
		camPosY2 -= 1;
	}


	//push tung object trong tung cell vao listObject
	for (int i = camPosX; i <= camPosX2; i++)
	{
		for (int j = camPosY; j <= camPosY2; j++)
		{
			for (int z = 0; z < grid[j][i].size(); z++)
			{
				if (luoi.find(grid[j][i].at(z)->id) == luoi.end())
					luoi[grid[j][i].at(z)->id] = grid[j][i].at(z);
			}
		}
	}

	for (auto& obj : luoi)
	{
		listOfObj.push_back(obj.second);
	}
	
}

void Grid::readObjectFromTextFile(vector<LPGAMEOBJECT>& listOfObject, char * pathOfFile)
{
	FILE* file;
	file = fopen(pathOfFile, "r");
	int numOfObj, tag, nx, x, y,itemInside, type,groundBBOX;
	fscanf(file, "%d", &numOfObj);
	for (int i = 0; i < numOfObj; i++)
	{
		fscanf(file, "%d %d %d %d %d %d %d", &tag, &nx, &x, &y,&itemInside, &type, &groundBBOX);
		insertObjectIntoGrid(getTypeObject(tag, nx, x, y, itemInside, type, groundBBOX));
	}
	//	ifstream file;
	fclose(file);
}

CGameObject* Grid::getTypeObject(int tag, int nx, int x, int y, int itemInside, int type,int groundBBOX)
{
	switch (tag)
	{
	case eTag::STAIR:
	{
		if (nx == 1)
			nx = 1;//1=right,2=left
		else
			nx = 2;
		if (type == 0)//type=0->false => IsUpStair
			type = 0;
		else
			type = 1;
		Stairs *stairs = new Stairs(nx, type);
		stairs->SetPosition(x, offsetMap+y);
		return stairs;
		break;
	}
	
	case eTag::TORCHES:
	{
		Torch *candle = new Torch(1);
		//		candle->AddAnimation(476);
		//		candle->setItemInside(clockInside);
		//		candle->SetPosition(29+i*(157-29), offsetMap +128);
		Torch * torch = new Torch(type);
		if (type == 1)
			torch->AddAnimation(476);
		else
			torch->AddAnimation(901);
		if (itemInside == -1)
			torch->setItemInside(randomIteminside());
		else
			torch->setItemInside(itemInside);
		torch->SetPosition(x, offsetMap+y);
		return torch;
		break;
	}
	case eTag::MainGround:
	{
		Ground *ground = new Ground(type, groundBBOX);
		ground->SetPosition(x, offsetMap+y);
		return ground;
		break;
		
	}
	case eTag::GROUND_ENEMY:
	{
		GroundEnemy *groundenemy = new GroundEnemy();
		groundenemy->AddAnimation(998);
		groundenemy->SetPosition(x, offsetMap + y);
		return groundenemy;
		break;
	}
	
	case eTag::DOOR:
	{
		Door *door = new Door();
		door->AddAnimation(495);
		door->AddAnimation(496);
		door->SetPosition(x, offsetMap + y);
		return door;
		break;
	}
	
	default:
		break;

	}

}

int Grid::randomIteminside()
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
