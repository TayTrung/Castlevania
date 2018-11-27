#pragma once
#include <Vector>
#include <string>
#include "Game.h"
#include"Textures.h"
#include "Camera.h"
#include <fstream>
#include "define.h"

using namespace std;

class Map
{
private:
	int colOfMap;
	int rowOfMap;
	int rowOfTileSet;
	int colOfTileSet;
	int TileWidth;
	int TileHeight;
	int listTileMap[550][50];
public:
	RECT getTile(int index);
	void loadTileMap(const char* path);
	void drawTileMap(Camera *camera, float ID);
	Map(float ID, const char*path);
	~Map();
};

