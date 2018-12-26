#pragma once
#include "GameObject.h"
#include "Torch.h"
#include "Ground.h"
#include "GroundEnemy.h"
#include "Camera.h"
#include "debug.h"
#include "Stairs.h"
#include "Door.h"
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
	void readObjectFromTextFile(vector <LPGAMEOBJECT> &listOfObject, char * pathOfFile);
	CGameObject * getTypeObject(int tag, int nx, int x, int y, int itemInside, int type, int groundBBOX);
	int randomIteminside();
	Grid();
	~Grid();
};

