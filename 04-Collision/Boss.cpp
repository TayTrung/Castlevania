#include "Boss.h"



void Boss::Update(DWORD dt, Simon *simon1)
{
	if (hp == 0)
	{
		this->SetState(BOSS_STATE_INACTIVE);
	}
	else
	{

		CGameObject::Update(dt);
		x += dx;
		y += dy;

		if (GetTickCount() - untouchable_start > SIMON_UNTOUCHABLE_TIME)
		{
			untouchable_start = 0;
			untouchable = false;
		}

		if (this->GetState() == BOSS_STATE_SLEEP)
		{
			if (simon1->x > this->x + 20)
			{
				this->SetState(BOSS_STATE_MOVE_DOWN);
			}
		}

		if (this->GetState() == BOSS_STATE_MOVE_DOWN)
		{
			if ((simon1->y) < (150 - SIMON_BIG_BBOX_HEIGHT))
			{
				if (this->y > offsetMap + 60)
				{

					if (simon1->x > this->x)
					{
						this->SetState(BOSS_STATE_ATTACK_RIGHT);
					}
					else
						this->SetState(BOSS_STATE_ATTACK_LEFT);
				}
			}
			else
				if ((simon1->y) > (150 - SIMON_BIG_BBOX_HEIGHT))
				{
					if (this->y > offsetMap + 100)
					{
						if (simon1->x > this->x)
						{
							this->SetState(BOSS_STATE_ATTACK_RIGHT);
						}
						else
							this->SetState(BOSS_STATE_ATTACK_LEFT);
					}
				}

		}
		float z,a;
		z = Camera::GetInstance()->GetPosition().x;
		a = Camera::GetInstance()->GetPosition().y;

		if (tick == 2)
		{
			if (waitTime == 0)
			{

				xz = this->GetState();
			}	
			this->SetState(BOSS_STATE_AFK);
			waitTime += dt;
			if (waitTime > 3000)
			{
				this->SetState(xz);
				fired = false;
				waitTime = 0;
				tick = 0;
			}
		}
		else
		{
			if (this->GetState() == BOSS_STATE_ATTACK_LEFT || this->GetState() == BOSS_STATE_ATTACK_RIGHT)
			{
				if (this->x < z || this->y>a+SCREEN_HEIGHT)
				{
					if (this->y > 80 + offsetMap)
					{
						vx = -vx;
						vy = -2 * vy;
					}
					else
					{
						vx = 0;
						vy = 0;
						waitTime += dt;
						if (waitTime > 1000)
						{
							this->SetState(BOSS_STATE_ATTACK_RIGHT);
							waitTime = 0;
							tick += 1;
						}
					}
				}
				else
					if (this->x > z + SCREEN_WIDTH - BOSS_BBOX_WIDTH || this->x < z || this->y>a + SCREEN_HEIGHT)
					{
						if (this->y > 80 + offsetMap)
						{
							vx = -vx;
							vy = -2 * vy;
						}
						else
						{
							vx = 0;
							vy = 0;
							waitTime += dt;
							if (waitTime > 1000)
							{
								this->SetState(BOSS_STATE_ATTACK_LEFT);
								waitTime = 0;
								tick += 1;
							}
						}
					}
					else
					{

						{
							if (this->y < offsetMap + 20)
							{

								if (simon1->x > this->x)
								{
									if (simon1->x - this->x > 130)
									{
										vx = 0;
										vy = 0;
										waitTime += dt;
										if (waitTime > 1000)
										{
											this->SetState(BOSS_STATE_ATTACK_RIGHT);
											waitTime = 0;
											tick += 1;
										}

									}
									else
									{
										this->vy = 0;
										this->vx = -GHOU_WALKING_SPEED;
									}
								}
								else
								{
									if (this->x - simon1->x > 130)
									{
										vx = 0;
										vy = 0;
										waitTime += dt;
										if (waitTime > 1000)
										{
											this->SetState(BOSS_STATE_ATTACK_LEFT);
											waitTime = 0;
											tick += 1;
										}
									}
									else
									{
										this->vy = 0;
										this->vx = GHOU_WALKING_SPEED;
									}
								}
							}
						}
					}
			}
		}
	}

}
	
	


void Boss::Render()
{
	int ani;
	if(this->GetState()!=BOSS_STATE_INACTIVE)
	{
		
			if (this->GetState() != BOSS_STATE_SLEEP)
			{
				ani = BOSS_ANI_ATTACK;
			}
			else

				ani = BOSS_ANI_SLEEP;
			int alpha=255;
			if (untouchable == true)
			 alpha = 110;
			animations[ani]->Render(x, y,alpha);
			//RenderBoundingBox(100);
	}

}

void Boss::SetState(int state)
{
	CGameObject::SetState(state);
	switch (state)
	{
	case BOSS_STATE_MOVE_RIGHT:
		vx = GHOU_WALKING_SPEED/2;
		vy = 0;
		nx = 1;
		break;
	case BOSS_STATE_MOVE_LEFT:
		vx = -GHOU_WALKING_SPEED/2;
		vy = 0;
		nx = -1;
		break;
	case BOSS_STATE_MOVE_DOWN:
		vx = 0;
		vy = GHOU_WALKING_SPEED/2;
		break;
	case BOSS_STATE_AFK:
		vx = 0;
		vy = 0;
		break;
	case BOSS_STATE_MOVE_UP:
		vx = 0;
		vy = -GHOU_WALKING_SPEED/2;
	
		break;
	case BOSS_STATE_ATTACK_RIGHT:
		vx = 3*GHOU_WALKING_SPEED/2;
		vy = 2*GHOU_WALKING_SPEED/2;
		break;

	case BOSS_STATE_ATTACK_LEFT:
		vx = -3*GHOU_WALKING_SPEED/2;
		vy = 2*GHOU_WALKING_SPEED/2;
		break;

	}
}

void Boss::GetBoundingBox(float & left, float & top, float & right, float & bottom)
{
	left = x;
	top = y;
	right = x + BOSS_BBOX_WIDTH;
	bottom = y + BOSS_BBOX_HEIGHT;
}

Boss::Boss()
{
	tick = 0;

	hp = 2;
}


Boss::~Boss()
{
}
