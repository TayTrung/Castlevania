#include <algorithm>
#include "debug.h"
#include "Sprites.h"
#include "Simon.h"
#include "Game.h"
#include "SceneManager.h"
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

	if ((this->GetState() == SIMON_STATE_ATTACK && this->whip->isFinished == true) ||//danh xong xet ve vi tri cu
		(this->GetState() == SIMON_STATE_THROW && this->dagger->isFinished == true) ||
		(this->GetState() == SIMON_STATE_ATTACK_ON_STAIRS && this->whip->isFinished == true) ||
		(this->GetState() == SIMON_STATE_THROW_ON_STAIRS && this->dagger->isFinished == true)
		)
	{
		//this->SetState(SIMON_STATE_IDLE);
		CGameObject::SetState(SIMON_STATE_IDLE);
	}

	if ((this->GetState() == SIMON_STATE_ATTACK_SITTING && this->whip->isFinished == true) ||////danh xong xet ve vi tri cu
		(this->GetState() == SIMON_STATE_THROW_SITTING && this->dagger->isFinished == true))
	{
		CGameObject::SetState(SIMON_STATE_SIT);
	}
	// Calculate dx, dy 
	CGameObject::Update(dt);

	// Simple fall down
	if (this->isOnStairs == false)
		vy += SIMON_GRAVITY * dt;

	

	vector<LPCOLLISIONEVENT> coEvents;
	vector<LPCOLLISIONEVENT> coEventsResult;

	coEvents.clear();
	if (this->isOnStairs == false)
		CalcPotentialCollisions(coObjects, coEvents);

	// reset untouchable timer if untouchable time has passed
	if ( GetTickCount() - untouchable_start >SIMON_UNTOUCHABLE_TIME)
	{
		untouchable_start = 0;
		untouchable = false;
	}

	// No collision occured, proceed normally
	if (coEvents.size() == 0)
	{
		x += dx;
		y += dy;
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

			

			if (this->isJumping == true)
			{
				this->isJumping = false;

				this->SetState(SIMON_STATE_IDLE);

			}
			if (this->GetState() == SIMON_STATE_HURT_RIGHT ||
				this->GetState() == SIMON_STATE_HURT_LEFT)
			{
				CGameObject::SetState(SIMON_STATE_IDLE);
				this->isJumping = false;
				StartUntouchable();
			}

			if (this->GetState() == SIMON_STATE_DOWN_LEFT || this->GetState() == SIMON_STATE_DOWN_RIGHT)
			{
				this->SetState(SIMON_STATE_IDLE);
			}
		}

	}
	if (this->GetState() == SIMON_STATE_THROW || this->GetState() == SIMON_STATE_THROW_SITTING || 
		this->GetState() == SIMON_STATE_THROW_ON_STAIRS)
	{
		if (animations[ani]->GetCurrentFrame() == 3)
		{
			this->dagger->isFinished = true;
		}
	}

	Scene *a = SceneManager::GetInstance()->getCurrentScene();

	if (dynamic_cast<Scene1 *>(a))
	{
		if (vx > 0 && x > MAP1_WIDTH - 32) x = MAP1_WIDTH - 32;
	}
	else
	{
		if (dynamic_cast<Scene2 *>(a))
		{
			if (vx > 0 && x > MAP2_WIDTH - 22) x = MAP2_WIDTH - 22;
			
		}
	}
	if (vx < 0 && x < 1) x = 1;
	if (this->GetState() != SIMON_STATE_ATTACK_SITTING)
		this->whip->SetPosition(x, y);
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
		{
			if (this->GetState() == SIMON_STATE_ATTACK_ON_STAIRS)
			{
				if(nx==1)
				{
					// true=going up, false=going down
					if (this->directionOnStairs == true)
					{
						ani = SIMON_ANI_ATTACK_OS_UP_RIGHT;
					}
					else
						if (this->directionOnStairs == false)
						{
							ani = SIMON_ANI_ATTACK_OS_DOWN_RIGHT;

						}
				}
				else
					if (nx==-1)
					{
						// true=going up, false=going down
						if (this->directionOnStairs == true)
						{
							ani = SIMON_ANI_ATTACK_OS_UP_LEFT;
						}
						else
							if (this->directionOnStairs == false)
							{

								ani = SIMON_ANI_ATTACK_OS_DOWN_LEFT;
							}
					}
			}
			else
			{
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
				{
					if (this->GetState() == (SIMON_STATE_THROW_ON_STAIRS))
					{
						if (nx == 1)
						{
							// true=going up, false=going down
							if (this->directionOnStairs == true)
							{
								ani = SIMON_ANI_ATTACK_OS_UP_RIGHT;
							}
							else
								if (this->directionOnStairs == false)
								{
									ani = SIMON_ANI_ATTACK_OS_DOWN_RIGHT;

								}
						}
						else
							if (nx == -1)
							{
								// true=going up, false=going down
								if (this->directionOnStairs == true)
								{
									ani = SIMON_ANI_ATTACK_OS_UP_LEFT;
								}
								else
									if (this->directionOnStairs == false)
									{

										ani = SIMON_ANI_ATTACK_OS_DOWN_LEFT;
									}
							}
					}
					else
					{
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
						{
							if (this->GetState() == (SIMON_STATE_JUMP))
							{
								if (nx == 1)
									ani = SIMON_ANI_JUMPING_RIGHT;
								else
									if (nx == -1)
										ani = SIMON_ANI_JUMPING_LEFT;

							}
							else
							{
								if (this->GetState() == (SIMON_STATE_ATTACK))
								{
									if (nx == -1)
									{
										ani = SIMON_ANI_ATTACKING_LEFT;
									}
									else
										if (nx == 1)
										{
											ani = SIMON_ANI_ATTACKING_RIGHT;
										}

								}
								else
								{
									if (this->GetState() == (SIMON_STATE_THROW))
									{
										if (nx == -1)
										{
											ani = SIMON_ANI_THROW_LEFT;
										}
										else
											if (nx == 1)
											{
												ani = SIMON_ANI_THROW_RIGHT;
											}
									}
									else
									{
										if (this->GetState() == SIMON_STATE_HURT_RIGHT)
										{
											ani = SIMON_ANI_HURT_RIGHT;


										}
										else
										{
											if (this->GetState() == SIMON_STATE_HURT_LEFT)
											{
												ani = SIMON_ANI_HURT_LEFT;


											}
											else
											{
												if (this->isJumping == false)
												{
													if (this->isOnStairs == true)
													{

														if (this->directionOnStairs == true)// true=going up, false=going down
														{
															if (nx > 0) ani = SIMON_ANI_AFK_UP_RIGHT;
															else
																if (nx < 0) ani = SIMON_ANI_AFK_UP_LEFT;
														}
														else
															if (this->directionOnStairs == false)
															{
																if (nx > 0) ani = SIMON_ANI_AFK_DOWN_RIGHT;
																else
																	if (nx < 0) ani = SIMON_ANI_AFK_DOWN_LEFT;
															}
													}
													else
													{
														if (nx > 0) ani = SIMON_ANI_IDLE_RIGHT;
														else
															if (nx < 0) ani = SIMON_ANI_IDLE_LEFT;
													}

												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			
		}
	}
	else
	{
		if (this->GetState() == SIMON_STATE_HURT_RIGHT)
		{
			ani = SIMON_ANI_HURT_RIGHT;


		}
		else
		{
			if (this->GetState() == SIMON_STATE_HURT_LEFT)
			{
				ani = SIMON_ANI_HURT_LEFT;


			}
			else
			{
				if (vx > 0)
				{
					if (this->GetState() == SIMON_STATE_DOWN_RIGHT)
						ani = SIMON_ANI_DOWN_RIGHT;
					else
						if (this->GetState() == SIMON_STATE_UP_RIGHT)
							ani = SIMON_ANI_UP_RIGHT;
						else
							ani = SIMON_ANI_WALKING_RIGHT;

				}
				else
				{
					if (vx < 0)
					{
						if (this->GetState() == SIMON_STATE_DOWN_LEFT)				
							ani = SIMON_ANI_DOWN_LEFT;
						else
							if (this->GetState() == SIMON_STATE_UP_LEFT)
								ani = SIMON_ANI_UP_LEFT;
							else
								ani = SIMON_ANI_WALKING_LEFT;
					}
				}
			}
		}
	}

	int alpha = 255;
	if (untouchable) alpha = 180;
	animations[ani]->Render(x, y, alpha);
	//RenderBoundingBox(100);
}

void Simon::SetState(int state)
{
	
	if (this->whip->isFinished == false||
		this->dagger->isFinished==false)
	{

		if (this->GetState() == SIMON_STATE_ATTACK)
			return;
		if (this->GetState() == SIMON_STATE_ATTACK_SITTING)
			return;
		if (this->GetState() == SIMON_STATE_ATTACK_ON_STAIRS)
			return;
		if (this->GetState() == SIMON_STATE_THROW_ON_STAIRS)
			return;
		if (this->GetState() == SIMON_STATE_THROW)
			return;
		if (this->GetState() == SIMON_STATE_THROW_SITTING)
			return;
		

	}else if (this->GetState()==SIMON_STATE_HURT_LEFT || this->GetState() == SIMON_STATE_HURT_RIGHT)
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
		case SIMON_STATE_HURT_RIGHT:
			vx = SIMON_JUMP_SPEED_Y / 6;
			vy = -SIMON_JUMP_SPEED_Y;
			break;
		case SIMON_STATE_HURT_LEFT:
			vx = -SIMON_JUMP_SPEED_Y / 6;
			vy = -SIMON_JUMP_SPEED_Y;
			break;
		case SIMON_STATE_DOWN_RIGHT:

			vx = SIMON_WALKING_SPEED / 2.5;
			vy = SIMON_WALKING_SPEED / 2.5;
			nx = 1;

			break;
		case SIMON_STATE_DOWN_LEFT:

			vx = -SIMON_WALKING_SPEED / 2.5;
			vy = SIMON_WALKING_SPEED / 2.5;
			nx = -1;

			break;
		case SIMON_STATE_UP_RIGHT:

			vx = SIMON_WALKING_SPEED / 2.5;
			vy = -SIMON_WALKING_SPEED / 2.5;
			nx = 1;

			break;
		case SIMON_STATE_UP_LEFT:

			vx = -SIMON_WALKING_SPEED / 2.5;
			vy = -SIMON_WALKING_SPEED / 2.5;
			nx = -1;
			break;
		case SIMON_STATE_JUMP:
			vy = -SIMON_JUMP_SPEED_Y;
			break;
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
