#include "Ground.h"

void Ground::Render()
{		
	if (type == 0)
		RenderBoundingBox(150);
}


void Ground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	if (type == 0)
	{
		r = x + INVIS_BRICK_BBOX_WIDTH;
		b = y + INVIS_BRICK_BBOX_HEIGHT;
	}
	else 
		if (type == 1)
		{
			r = x + Bbox_WIDTH;
			b = y + BRICK_BBOX_HEIGHT;
		}
	
				
}

Ground::Ground(int xtype,int xbbox_WIDTH)
{
	type = xtype;
	Bbox_WIDTH = xbbox_WIDTH;
}

Ground::~Ground()
{
}
