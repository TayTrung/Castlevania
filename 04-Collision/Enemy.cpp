#include "Enemy.h"



void Enemy::setItemInside(int Item)
{
	itemInside = Item;
}

void Enemy::getItemInside(int Item)
{
	Item = itemInside;
}

Enemy::Enemy()
{
	itemInside = 0;//has nothing inside
}


Enemy::~Enemy()
{
}
