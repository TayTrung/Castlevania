#include "Monster.h"



void Monster::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + MONSTER_BBOX_WIDTH;
	bottom = y + MONSTER_BBOX_HEIGHT;
}

void Monster::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{

	CGameObject::Update(dt);
	// Simple fall down

	if (freezed == false)
	vy += ITEM_GRAVITY * dt;
	
	if (this->y < offsetMap + 40 - MONSTER_BBOX_HEIGHT)
		offCollision = false;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	if (offCollision == false)
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
			if (this->GetState() == MONSTER_STATE_UNDERWATER)
			{
				if (this->nx == 1)
					this->SetState(MONSTER_STATE_ACTIVE_RIGHT);
				else
					if (this->nx == -1)
						this->SetState(MONSTER_STATE_ACTIVE_LEFT);
			}
		}

	}


	//clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];

	float xc, yc;
	xc = Camera::GetInstance()->GetPosition().x;

	//if (makeAFire == false)

		if (isWaitting == false)
		{
			if (((abs(x - this->x1)) <25) && ((abs(x - this->x1)) > 23))
			{
				if (nx == 1)
				{
					this->SetState(MONSTER_STATE_FIRE_RIGHT);
					isWaitting = true;
				}
				else
					if (nx == -1)
					{
						this->SetState(MONSTER_STATE_FIRE_LEFT);
						isWaitting = true;
					}


			}

		}
	
	
	if (isWaitting)
	{
		TimeWait += dt;
		if (TimeWait >= 1000)
		{
			if (nx == 1)
			{
				this->SetState(MONSTER_STATE_ACTIVE_LEFT);
				this->spawnFireBall = false;
			}
			else
				if (nx == -1)
				{
					 this->SetState(MONSTER_STATE_ACTIVE_RIGHT);
					 this->spawnFireBall = false;
				}
			isWaitting = false;
			TimeWait = 0;
		}
	}

	if (x<xc || x>xc + SCREEN_WIDTH)
		this->SetState(MONSTER_STATE_INACTIVE);
	if(y>offsetMap+150)

		this->SetState(MONSTER_STATE_INACTIVE);


}


void Monster::Render()
{
	if (vx != 0 || vy != 0)
	{
		if (freezed == true)
		{
			if (this->GetState() == MONSTER_STATE_ACTIVE_RIGHT)
			{

			}
			else
				if (this->GetState() == MONSTER_STATE_ACTIVE_LEFT)
				{

				}
				else
					if (this->GetState() == MONSTER_STATE_UNDERWATER)
					{
						ani = MONSTER_ANI_UNDERWATER;
						animations[ani]->Render(x, y);

					}
						
		}
		else

			if (this->GetState() == MONSTER_STATE_ACTIVE_LEFT)
			{
				ani = MONSTER_ANI_LEFT;
				animations[ani]->Render(x, y);
				//	RenderBoundingBox(100);
			}
			else
				if (this->GetState() == MONSTER_STATE_ACTIVE_RIGHT)
				{

					ani = MONSTER_ANI_RIGHT;
					animations[ani]->Render(x, y);
					//RenderBoundingBox(100);
				}
				else
					if (this->GetState() == MONSTER_STATE_UNDERWATER)
					{
						ani = MONSTER_ANI_UNDERWATER;
						animations[ani]->Render(x, y);
					}



	}
	else
	{
		if (freezed == true)
		{

			if (this->GetState() == MONSTER_STATE_FIRE_RIGHT)
			{
				ani = MONSTER_ANI_FIRE_RIGHT;
				animations[ani]->Render(x, y);

			}
			else
				if (this->GetState() == MONSTER_STATE_FIRE_LEFT)
				{
					ani = MONSTER_ANI_FIRE_LEFT;
					animations[ani]->Render(x, y);
				}
		}
		else

			if (this->GetState() == MONSTER_STATE_FIRE_RIGHT)
			{
				ani = MONSTER_ANI_FIRE_RIGHT;
				animations[ani]->Render(x, y);


			}
			else
				if (this->GetState() == MONSTER_STATE_FIRE_LEFT)
				{
					ani = MONSTER_ANI_FIRE_LEFT;
					animations[ani]->Render(x, y);


				}

	}

}

void Monster::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case MONSTER_STATE_ACTIVE_RIGHT:
		vx = MONSTER_WALKING_SPEED;
		nx = 1;
		break;
	case MONSTER_STATE_ACTIVE_LEFT:
		vx = -MONSTER_WALKING_SPEED;
		nx = -1;
		break;
	case MONSTER_STATE_FIRE_LEFT:
		vx = 0;
		vy = 0;
		nx = -1;
		break;
	case MONSTER_STATE_FIRE_RIGHT:
		vx = 0;
		vy = 0;
		nx = 1;
		break;
	case MONSTER_STATE_UNDERWATER:
		vx = 0;
		vy = -MONSTER_JUMP_SPEED;
	
		break;
	}
}

Monster::Monster(float x11)
{
	x1 = x11;
	offCollision = true;
	isWaitting = false;
	TimeWait = 0;
	spawnFireBall = false;
}


Monster::~Monster()
{
}
