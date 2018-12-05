#include "Map.h"




Map::Map(float ID, const char*path)
{

	loadTileMap(path);
}


RECT Map::getTile(int index)
{
	RECT rect;
	rect.top = index / colOfMap * TileHeight;
	rect.left = index % colOfMap* TileWidth;
	rect.bottom = rect.top + TileHeight;
	rect.right = rect.left + TileWidth;
	return rect;
}

void Map::loadTileMap(const char* path)
{
	FILE* file;
	file = fopen(path, "r");
	fscanf(file, "%d %d %d %d %d %d", &rowOfMap, &colOfMap, &rowOfTileSet, &colOfTileSet, &TileWidth, &TileHeight);
//	ifstream file;
	for (int i = 0; i < rowOfMap; i++)
	{
		for (int j = 0; j < colOfMap; j++)
		{
			fscanf(file, "%d", &listTileMap[i][j]);

		}
	}
	fclose(file);
}

void Map::drawTileMap(Camera *camera, float ID)
{
	int numCol = camera->GetPosition().x / TileWidth;
	int numRow = camera->GetPosition().y / TileHeight;

	int disX = (int)camera->GetPosition().x % TileWidth;
	int disY = (int)camera->GetPosition().y % TileHeight;

	for(int i=0;i<SCREEN_HEIGHT/ TileHeight;i++)
	{
		for (int j = 0; j <= SCREEN_WIDTH/ TileWidth; j++)
		{
			RECT rect = getTile(listTileMap[i+ numRow][j+ numCol]);
			CGame::GetInstance()->Draw(j*TileWidth  -disX, i*TileHeight - disY + offsetMap,
				CTextures::GetInstance()->Get(ID), rect.left, rect.top, rect.right, rect.bottom, 255);
		}
	}
}

Map::~Map()
{
}
