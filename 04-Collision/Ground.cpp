#include "Ground.h"

void Ground::Render()
{
	
		if (this->type == 1)
		{
			{
				//animations[0]->Render(x, y);
				//RenderBoundingBox(255);
			}
		}
		else
		{
			{
				animations[0]->Render(x, y);
				//RenderBoundingBox(50);
			}

		}
	
}


void Ground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	if (type == 0 || type == 2)
	{


		r = x + BRICK_BBOX_WIDTH;
		b = y + BRICK_BBOX_HEIGHT;
	}
	else 
	{
		r = x + INVIS_BRICK_BBOX_WIDTH;
		b = y + INVIS_BRICK_BBOX_HEIGHT;

	}
}

Ground::Ground(int x)
{
	type = x;
}

Ground::~Ground()
{
}
