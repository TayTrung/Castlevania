#pragma once
#include "GameObject.h"
#include "Torch.h"
#include "Ground.h"
#include "GroundEnemy.h"
#include "Camera.h"
#include "debug.h"
#define CELL_WIDTH	(SCREEN_WIDTH/2)
#define CELL_HEIGHT (SCREEN_HEIGHT/2)
class Grid
{
private:
	int count;
public:
	vector <LPGAMEOBJECT> grid[3][25];
	void insertObjectIntoGrid(CGameObject *object);
	void getListOfObjects(vector <LPGAMEOBJECT> &listOfObj,Camera *cam);
	Grid();
	~Grid();
};

