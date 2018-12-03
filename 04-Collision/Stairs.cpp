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
	r = x + STAIRS_BBOX_WIDTH;
	b = y + STAIRS_BBOX_HEIGHT;


}

int Stairs::getType()
{
	return type;
}

Stairs::Stairs(float xtype)
{
	type = xtype;
}

Stairs::~Stairs()
{
}
