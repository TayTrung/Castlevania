#include "Ground.h"

void Ground::Render()
{		
	//if (type == 0)
		RenderBoundingBox(200);
}


void Ground::GetBoundingBox(float &l, float &t, float &r, float &b)
{
	l = x;
	t = y;
	if (type == 0)
	{
		if (Bbox_WIDTH !=335)
			r = x + INVIS_BRICK_BBOX_WIDTH;
		else
			r = x + Bbox_WIDTH;

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
	if (type == 1)
		tag = eTag::GROUND;
	else
		tag = eTag::CHECK_BOX;
	if (type == 0)
	{
		switch (Bbox_WIDTH)
		{
		case 1:
			this->SetState(INVIS_STATE_NEXT_LVL);
			break;
		case 2:
			this->SetState(INVIS_STATE_INVIS_ITEM);
			break;
		case 3:
			this->SetState(INVIS_STATE_OPENDOOR);
			break;
		case 4:
			this->SetState(INVIS_STATE_OPENDOOR2);
			break;
		case 5:
			this->SetState(INVIS_STATE_NEXT_LVL_UNDERGROUND);
			break;
		case 335:
			this->SetState(INVIS_STATE_DIE_BOX);
			break;
		case 7:
			this->SetState(INVIS_STATE_UPPERGROUND);
			break;
		case 8:
			this->SetState(INVIS_STATE_STAGE2);
			break;

		default:
			break;

		}
	}
	else
		this->SetState(GROUND_STATE_ACTIVE);
}

Ground::~Ground()
{

}
