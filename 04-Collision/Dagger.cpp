#include "Dagger.h"
#include "Camera.h"


void Dagger::turnOnDagger()
{
	isOn = true;
}

void Dagger::turnOffDagger()
{
	isOn = false;
}

void Dagger::GetBoundingBox(float & l, float & t, float & r, float & b)
{
//	float x, y;
//	this->GetPosition(x, y);

	//if (this->nx > 0)
	{
		l = x ;
		t = y;
		r = l + DAGGER_BBOX_WIDTH;
		b = t + DAGGER_BBOX_HEIGHT;
	}
	/*else
	{
		l = x-32;
		t = y;
		r = x - 5;
		b = t + 18;
	}*/
		
}

void Dagger::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects)
{
		CGameObject::Update(dt, coObjects);

		x += dx;
		float x1, y1;
		x1= Camera::GetInstance()->GetPosition().x;
		y1 = Camera::GetInstance()->GetPosition().y;
		if (x<x1 || x>(x1 + SCREEN_WIDTH))
		{

			this->SetState(DAGGER_STATE_INACTIVE);
			
		}

}

void Dagger::Render()
{
	int ani;
	if (this->GetState() == DAGGER_STATE_ACTIVE_LEFT)
	{
		ani = DAGGER_ANI_LEFT;
		animations[ani]->Render(x, y);
		//RenderBoundingBox(50);
	}
	else if( this->GetState() == DAGGER_STATE_ACTIVE_RIGHT)
		{
			ani = DAGGER_ANI_RIGHT;
			animations[ani]->Render(x, y);
		//	RenderBoundingBox(50);
		}
	
	//else this->GetState() == DAGGER_STATE_INACTIVE;

	
}

void Dagger::SetState(int state)
{
	CGameObject::SetState(state);

	switch (state)
	{
	case DAGGER_STATE_ACTIVE_RIGHT:
		vx = 2*DAGGER_FLYING_SPEED;
		nx = 1;
		break;
	case DAGGER_STATE_ACTIVE_LEFT:
		vx = -2*DAGGER_FLYING_SPEED;
		nx = -1;
		break;
	case DAGGER_STATE_INACTIVE:
		vx = 0;
		break;
	}
}

void Dagger::CreateWeapon(float x, float y, float nx)
{
	this->SetPosition(x, y);
	this->nx = nx;
	isFinished = false;
	vx = nx * DAGGER_FLYING_SPEED;
	//if (nx == -1)
	//{
	//	this->SetState(DAGGER_STATE_ACTIVE_LEFT);
	//}
	//else 
	//	if (nx == 1)
	//	{
	//		this->SetState(DAGGER_STATE_ACTIVE_LEFT);
	//	}
}

Dagger::Dagger()
{
	isOn = false;
	vx = 0;
	isFinished = true;
	this->SetState(DAGGER_STATE_INACTIVE);
}



Dagger::~Dagger()
{
}







