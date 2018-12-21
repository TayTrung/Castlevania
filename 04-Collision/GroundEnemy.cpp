#include "GroundEnemy.h"

void GroundEnemy::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	right = x + BRICK_BBOX_WIDTH;
	bottom = y + BRICK_BBOX_HEIGHT;


}

void GroundEnemy::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	CGameObject::Update(dt, coObjects);



	x += dx;
	y += dy;
}

void GroundEnemy::Render()
{
	if (this->GetState() == GROUND_STATE_ACTIVE)
	{
		animations[0]->Render(x, y);
		//RenderBoundingBox(100);
	}


}

GroundEnemy::GroundEnemy()
{
	tag = eTag::GROUND_ENEMY;
}

GroundEnemy::~GroundEnemy()
{

}


