#include <algorithm>
#include "debug.h"
#include "Sprites.h"
#include "Simon.h"
#include "Game.h"
#include "SceneManager.h"
//#include "Scene.h"
#include "Scene1.h"
#include "Scene2.h"

void Simon::useDagger()
{
	isUsingDagger = true;
}

void Simon::notUseDagger()
{
	isUsingDagger = false;
}

void Simon::Update(DWORD dt, vector<LPGAMEOBJECT> *coObjects)
{
	
	if ((this->GetState()==SIMON_STATE_ATTACK && this->whip->isFinished == true) || (this->GetState() == SIMON_STATE_ATTACK_SITTING && this->whip->isFinished == true))
	{
		//this->SetState(SIMON_STATE_IDLE);
		CGameObject::SetState(SIMON_STATE_IDLE);
	}

	if ((this->GetState() == SIMON_STATE_THROW && this->dagger->isFinished == true) || (this->GetState() == SIMON_STATE_THROW_SITTING && this->dagger->isFinished == true))
	{
	CGameObject::SetState(SIMON_STATE_IDLE);
	}
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	vy += SIMON_GRAVITY*dt;

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();

	CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	/*if ( GetTickCount() - untouchable_start > MARIO_UNTOUCHABLE_TIME) 
	{
		untouchable_start = 0;
		untouchable = 0;
	}*/

	// No collision occured, proceed normally
	if (coEvents.size()==0)
	{
		x += dx; 
		y += dy;
	}
	else
	{
		float min_tx, min_ty, nx = 0, ny;

		FilterCollision(coEvents, coEventsResult, min_tx, min_ty, nx, ny);

		// block 
		x += min_tx*dx + nx*0.4f;		// nx*0.4f : need to push out a bit to avoid overlapping next frame
		y += min_ty*dy + ny*0.4f;
		
		if (nx!=0) vx = 0;
		if (ny != 0)
		{
			vy = 0;
			

			if (this->isJumping == true)
			{
				this->isJumping = false;
				
				this->SetState(SIMON_STATE_IDLE);

			}
				
		}
	
	}
	if (this->GetState() == SIMON_STATE_THROW || this->GetState() == SIMON_STATE_THROW_SITTING)
	{
		if (animations[ani]->GetCurrentFrame() == 3)
		{
			this->dagger->isFinished = true;
		}
	}

	Scene *a = SceneManager::GetInstance()->getCurrentScene();

	if (dynamic_cast<Scene1 *>(a))
	{
			if (vx > 0 && x > MAP1_WIDTH-32) x = MAP1_WIDTH-32;
	}
	else
	{
		if (dynamic_cast<Scene2 *>(a))
		{
			if (vx > 0 && x > MAP2_WIDTH- 22) x = MAP2_WIDTH- 22;
		}
	}
	if (vx < 0 && x < 1) x = 1;
	//if (this->GetState() != SIMON_STATE_ATTACK_SITTING)
	//	this->whip->SetPosition(x, y);
	// clean up collision events
	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

void Simon::Render()
{
	/*float x, y;

	this->GetPosition(x, y);*/
	if (vx == 0)
	{
		if (this->GetState() == (SIMON_STATE_SIT))
		{
			if (nx == 1)
				ani = SIMON_ANI_SITTING_RIGHT;
			else
				if (nx == -1)
					ani = SIMON_ANI_SITTING_LEFT;
		}
		else
			if (this->GetState() == (SIMON_STATE_ATTACK_SITTING))
			{
				if (nx == 1)
				{
					ani = SIMON_ANI_ATTACKING_RIGHT_SITTING;
					//this->whip->SetState(WHIP_STATE_ACTIVE_RIGHT);
				}
				else if (nx == -1)
				{
					ani = SIMON_ANI_ATTACKING_LEFT_SITTING;
					//this->whip->SetState(WHIP_STATE_ACTIVE_LEFT);
				}
				//	this->whip->SetPosition(x, y);
				//	this->whip->Render();
			}
			else
				if (this->GetState() == SIMON_STATE_THROW_SITTING)
				{
					if (nx == 1)
					{
						ani = SIMON_ANI_THROW_LEFT_SITTING;
					}
					else 
						if (nx == -1)
						{
							ani = SIMON_ANI_THROW_RIGHT_SITTING;
						}
				}
				else
					if (this->GetState() == (SIMON_STATE_JUMP))
					{
						if (nx == 1)
							ani = SIMON_ANI_JUMPING_RIGHT;
						else
							if (nx == -1)
								ani = SIMON_ANI_JUMPING_LEFT;

					}
					else
						if (this->GetState() == (SIMON_STATE_ATTACK))
						{
							if (nx == -1)
							{
								ani = SIMON_ANI_ATTACKING_LEFT;
								//this->whip->SetState(WHIP_STATE_ACTIVE_LEFT);
							}
							else
								if (nx == 1)
								{
									ani = SIMON_ANI_ATTACKING_RIGHT;
									//this->whip->SetState(WHIP_STATE_ACTIVE_RIGHT);
								}

							//	this->whip->SetPosition(x, y);
							//	this->whip->Render();

						}
						else
							if (this->GetState() == (SIMON_STATE_THROW))
							{
								if (nx == -1)
								{
									ani = SIMON_ANI_THROW_LEFT;
									//this->dagger->SetState(DAGGER_STATE_ACTIVE_LEFT);
								}
								else
									if (nx == 1)
									{
										ani = SIMON_ANI_THROW_RIGHT;
										//this->dagger->SetState(DAGGER_STATE_ACTIVE_RIGHT);
									}
							}
							else
								if (this->isJumping == false)
								{
									if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
									else
										if (nx < 0) ani = SIMON_ANI_IDLE_LEFT;
								}
	}
	else
		if (vx > 0)
			ani = SIMON_ANI_WALKING_RIGHT;
		else
			ani = SIMON_ANI_WALKING_LEFT;

	int alpha = 255;
	if (untouchable) alpha = 128;
	animations[ani]->Render(x, y, alpha);
    RenderBoundingBox(100);
}

void Simon::SetState(int state)
{
	
	
	if (this->GetState() == SIMON_STATE_ATTACK)
		return;

	if (this->GetState() == SIMON_STATE_ATTACK_SITTING)
		return;
	if (this->GetState() == SIMON_STATE_THROW)
		return;

	if (this->GetState() == SIMON_STATE_THROW_SITTING)
		return;
	CGameObject::SetState(state);
	switch (state)
	{
	case SIMON_STATE_WALKING_RIGHT:
		vx = SIMON_WALKING_SPEED;
		nx = 1;
		break;
	case SIMON_STATE_WALKING_LEFT:
		vx = -SIMON_WALKING_SPEED;
		nx = -1;
		break;
	case SIMON_STATE_JUMP:
		vy = -SIMON_JUMP_SPEED_Y;
	case SIMON_STATE_IDLE:
		vx = 0;
		break;
	//case	SIMON_STATE_HURT_RIGHT:
	//	vy = -SIMON_HURT;
	//	vx=-
	//case	SIMON_STATE_HURT_LEFT:
	/*case SIMON_STATE_DIE:
		vy = -SIMON_DIE_DEFLECT_SPEED;
		break;*/
	}
}


//void Simon::PickedSword()
//{
//	isHavingSword = true;
//}

void Simon::GetBoundingBox(float &left, float &top, float &right, float &bottom)
{
	if (this->GetState() != SIMON_STATE_SIT && this->GetState() != SIMON_STATE_ATTACK_SITTING && this->GetState() != SIMON_STATE_JUMP && this->GetState() != SIMON_STATE_THROW_SITTING)
	{
		left = x;
		top = y;
	}
	else
	{
		left = x;
		top = y + 8;
	}

	right = x + SIMON_BIG_BBOX_WIDTH;
	bottom = y + SIMON_BIG_BBOX_HEIGHT;
}