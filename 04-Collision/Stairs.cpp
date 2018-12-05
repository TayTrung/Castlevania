#include "Stairs.h"

void Stairs::Render()
{
	{
		{
			//animations[0]->Render(x, y);
			RenderBoundingBox(150);
		}

	}

}


void Stairs::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	if (isDownStairs == false)
	{

		r = x + STAIRS_BBOX_WIDTH;
		b = y + STAIRS_BBOX_HEIGHT;
	}
	else
		if (isDownStairs == true)
		{

			r = x + STAIRS_BBOX_WIDTH;
			b = y + STAIRS_BBOX_HEIGHT/2;
		}


}

int Stairs::getType()
{
	return type;
}

Stairs::Stairs(float xtype,bool x)
{
	type = xtype;
	isDownStairs = x;
}

Stairs::~Stairs()
{
}
