#include "Torch.h"

void Torch::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	left = x;
	top = y;
	if (type == 0)
	{

		right = x + TORCH_BBOX_WIDTH;
		bottom = y + TORCH_BBOX_HEIGHT;

	}
	else
		if (type == 1)
		{

			right = x + CANDLE_BBOX_WIDTH;
			bottom = y + CANDLE_BBOX_HEIGHT;

		}
}

void Torch::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	CGameObject::Update(dt, coObjects);

 

	x += dx;
	y += dy;
}

void Torch::Render()
{
	if (this->GetState() == TORCH_STATE_ACTIVE)
	{
		animations[0]->Render(x, y);
	//RenderBoundingBox(100);
	}

	
}

Torch::Torch(int type1)
{
	type = type1;
	if (type == 0)
		state = TORCH_STATE_ACTIVE;
	else
		state = CANDLE_STATE_ACTIVE;
	tag = eTag::TORCHES;
	//isKilled = false;
}

Torch::~Torch()
{
}


