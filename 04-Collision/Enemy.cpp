#include "Enemy.h"



void Enemy::setItemInside(int Item)
{
	itemInside = Item;
}

int Enemy::getItemInside()
{
return itemInside;
}

Enemy::Enemy()
{
	itemInside = 0;//has nothing inside
}


Enemy::~Enemy()
{
}
