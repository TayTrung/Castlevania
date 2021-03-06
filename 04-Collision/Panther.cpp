#include "Panther.h"



void Panther::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + PANTHER_BBOX_WIDTH;
	bottom = y + PANTHER_BBOX_HEIGHT;
}

void Panther::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

	CGameObject::Update(dt);

	// Simple fall down

	if (freezed == false)
		vy += ITEM_GRAVITY / 1.1 * dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	if (offCollision == true)
		if ((y > offsetMap + 140-20)&& (y<offsetMap+140))
			offCollision = false;

	if(offCollision==false)
		CalcPotentialCollisions(coObjects, coEvents);

	if (GetTickCount() - freezeTime_Start > ENEMY_FREEZE_TIME)
	{
		if (freezed == true)
		{

			freezeTime_Start = 0;
			freezed = false;
		}
	}
	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		if (freezed == false)
		{
			x += dx;
			y += dy;
		}
	}
	else
	{
		
			float min_tx, min_ty, nx = 0, ny;

			FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

			// block 
			x += min_tx * dx + nx * 0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
			y += min_ty * dy + ny * 0.4f;

			if (nx != 0) vx = 0;
			if (ny != 0)
			{
				vy = 0;

				if (this->GetState() == PANTHER_STATE_JUMPING_LEFT)
					this->SetState(PANTHER_STATE_ACTIVE_LEFT);
				if (this->GetState() == PANTHER_STATE_JUMPING_RIGHT)
					this->SetState(PANTHER_STATE_ACTIVE_RIGHT);

			}

	}

	if (this->GetState() == PANTHER_STATE_ACTIVE_LEFT || this->GetState() == PANTHER_STATE_ACTIVE_RIGHT)
	{
		if (jumped == false)
		{
			if (((abs(x - X)) < distanceToJump) && ((abs(x - X)) > distanceToJump -2))
			{
				if (nx == 1)
					this->SetState(PANTHER_STATE_JUMPING_RIGHT);

				else
					if (nx == -1)
						this->SetState(PANTHER_STATE_JUMPING_LEFT);

				jumped = true;
				offCollision = true;
			}
				

		}
	}
	//clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
	float x1, y1;
	x1 = Camera::GetInstance()->GetPosition().x;
	if (jumped == true)
		if (x<x1 || x>x1 + SCREEN_WIDTH)
		this->SetState(PANTHER_STATE_INACTIVE);
}

void Panther::Render()
{
	int ani;
	if (vx != 0)
	{
		if (this->freezed == true)
		{
			if (jumped == true && offCollision == false)// dang duoi dat di
			{
				if (this->nx == 1)
				{

					ani = PANTHER_ANI_FREEZE_RIGHT;
					animations[ani]->Render(x, y);
				}
				else
					if (this->nx == -1)
					{
						ani = PANTHER_ANI_FREEZE_LEFT;
						animations[ani]->Render(x, y);
					}
			}
			else
				if (jumped == true && offCollision == true)//dang bay
				{
					if (this->nx == 1)
					{

						ani = PANTHER_ANI_FREEZE_RIGHT_FLY;
						animations[ani]->Render(x, y);
					}
					else
						if (this->nx == -1)
						{
							ani = PANTHER_ANI_FREEZE_LEFT_FLY;
							animations[ani]->Render(x, y);
						}
				}
				else
					if (jumped == false && offCollision == false && this->x == this->X)//dang sit
					{

						if (this->nx == 1)
						{

							ani = PANTHER_ANI_FREEZE_RIGHT_SIT;
							animations[ani]->Render(x, y);
						}
						else
							if (this->nx == -1)
							{
								ani = PANTHER_ANI_FREEZE_LEFT_SIT;
								animations[ani]->Render(x, y);
							}
					}
					else
						if (jumped == false && offCollision == false)//dang chay ma chua nhay
						{

							if (this->nx == 1)
							{

								ani = PANTHER_ANI_FREEZE_RIGHT;
								animations[ani]->Render(x, y);
							}
							else
								if (this->nx == -1)
								{
									ani = PANTHER_ANI_FREEZE_LEFT;
									animations[ani]->Render(x, y);
								}
						}
		}
		else
			if (this->GetState() == PANTHER_STATE_ACTIVE_RIGHT)
			{
				ani = PANTHER_ANI_RIGHT;
				animations[ani]->Render(x, y);
				//	RenderBoundingBox(100);
			}
			else
				if (this->GetState() == PANTHER_STATE_ACTIVE_LEFT)
				{

					ani = PANTHER_ANI_LEFT;
					animations[ani]->Render(x, y);
					//RenderBoundingBox(100);
				}
				else
					if (this->GetState() == PANTHER_STATE_JUMPING_RIGHT)
					{
						ani = PANTHER_ANI_JUMP_RIGHT;
						animations[ani]->Render(x, y);
						//	RenderBoundingBox(100);
					}
					else
						if (this->GetState() == PANTHER_STATE_JUMPING_LEFT)
						{

							ani = PANTHER_ANI_JUMP_LEFT;
							animations[ani]->Render(x, y);
							//RenderBoundingBox(100);
						}


	}
	else
	{


		if (this->GetState() == PANTHER_STATE_SIT_RIGHT)
		{

			ani = PANTHER_ANI_SIT_RIGHT;
			animations[ani]->Render(x, y);
		}
		else
			if (this->GetState() == PANTHER_STATE_SIT_LEFT)
			{

				ani = PANTHER_ANI_SIT_LEFT;
				animations[ani]->Render(x, y);
			}
	}
	//RenderBoundingBox(100);

}

void Panther::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case PANTHER_STATE_ACTIVE_RIGHT:
		vx = 1.5*GHOU_WALKING_SPEED*2;
		nx = 1;
		break;
	case PANTHER_STATE_ACTIVE_LEFT:
		vx = -1.5*GHOU_WALKING_SPEED*2;
		nx = -1;
		break;
	case PANTHER_STATE_JUMPING_LEFT:
		vx = -PANTHER_WALKING_SPEED;
		vy = -SIMON_JUMP_SPEED_Y ;
		nx = -1;
		break;
	case PANTHER_STATE_JUMPING_RIGHT:
		vx = PANTHER_WALKING_SPEED;
		vy = -SIMON_JUMP_SPEED_Y ;
		nx = 1;
		break;
	case PANTHER_STATE_SIT_LEFT:
		nx = -1;
		vx = 0;
		break;
	case PANTHER_STATE_SIT_RIGHT:
		nx = 1; vx = 0;
		break;
	case GHOU_STATE_INACTIVE:
		vx = 0;
		break;
	}
}

void Panther::SetPosition(float x, float y)
{
	this->x = x;
	X = x;
	this->y = y;
}

Panther::Panther(float xdistance)
{
	distanceToJump = xdistance;
	changeDirection = false;
	jumped = false;
	offCollision = false;
	tag = eTag::PANT;
}


Panther::~Panther()
{
}
