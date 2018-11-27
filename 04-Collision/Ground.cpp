#include "Ground.h"

void Ground::Render()
{
	
		//if (this->type == 1 || this->type==21)
		//{
			//{
				//animations[0]->Render(x, y);
			//RenderBoundingBox(255);
			//}
		//}
		//else
		{
			{
				//animations[0]->Render(x, y);
				RenderBoundingBox(150);
			}

		}
	
}


void Ground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	if (type == 11)
	{
		r = x + BRICKMAP11_BBOX_WIDTH;
		b = y + BRICK_BBOX_HEIGHT;
	}
	else 
		if (type == 21)
		{
			r = x + BRICKMAP21_BBOX_WIDTH;
			b = y + BRICK_BBOX_HEIGHT;
		}
		else
			if (type == 22)
			{
				r = x + BRICKMAP22_BBOX_WIDTH;
				b = y + BRICK_BBOX_HEIGHT;

			}
			else
				if (type == 23)
				{
					r = x + BRICKMAP23_BBOX_WIDTH;
					b = y + BRICK_BBOX_HEIGHT;

				}
				else
					if (type == 0)
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
