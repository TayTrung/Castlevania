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
	/*if (dynamic_cast<Torch *>(object))
	{
		Torch *newTorch = dynamic_cast<Torch *>(object);
		if (newTorch->type == 0)
		{
			x2 = x1 + TORCH_BBOX_WIDTH;
			y2 = y1 + TORCH_BBOX_HEIGHT;
		}
		else
		{
			x2 = x1 + CANDLE_BBOX_WIDTH;
			y2 = y1 + CANDLE_BBOX_HEIGHT;

		}
	}
	else
		if (dynamic_cast<Ground *>(object))
		{
			Ground *newGround = dynamic_cast<Ground *>(object);
			if (newGround->type == 0)
			{
				x2 = x1 + INVIS_BRICK_BBOX_WIDTH;
				y2 = y1 + INVIS_BRICK_BBOX_HEIGHT;

			}
			else
			{
				x2 = x1 + newGround->Bbox_WIDTH;
				y2 = y1 + BRICK_BBOX_HEIGHT;
			}
		}
		else
			if (dynamic_cast<GroundEnemy *>(object))
			{
				x2 = x1 + BRICK_BBOX_WIDTH;
				y2 = y1 + BRICK_BBOX_HEIGHT;
			}*/
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
