#include "Camera.h"

#include "SceneManager.h"
//#include "Scene.h"
#include "Scene1.h"
#include "Scene2.h"
Camera * Camera::__instance = NULL;


Camera::Camera(int X, int Y)
{

	mPositionOfCamera = D3DXVECTOR2(X, Y);
}



Camera::~Camera()
{

}

Camera * Camera::GetInstance()
{
	if (__instance == NULL) __instance = new Camera(0, 0);
	return __instance;
}

void Camera::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR2((int)x, (int)y));
}

void Camera::SetPosition(D3DXVECTOR2 pos)
{
	mPositionOfCamera = pos;
}

D3DXVECTOR2 Camera::Transform(float zx, float zy)
{
	return D3DXVECTOR2(zx - mPositionOfCamera.x, zy - mPositionOfCamera.y);
}
void Camera::Update()
{
	Scene *a=SceneManager::GetInstance()->getCurrentScene();

	if (mPositionOfCamera.x < 0)
		mPositionOfCamera.x = 0;

	if (dynamic_cast<Scene1 *>(a))
	{
		if (mPositionOfCamera.x > MAP1_WIDTH - SCREEN_WIDTH+16)
			mPositionOfCamera.x = MAP1_WIDTH - SCREEN_WIDTH+16;
	}
	else
	{
		if (dynamic_cast<Scene2 *>(a))
		{
			if (mPositionOfCamera.x > MAP2_WIDTH- SCREEN_WIDTH+16)
				mPositionOfCamera.x = MAP2_WIDTH- SCREEN_WIDTH+16;
			
		}
	}
}

D3DXVECTOR3 Camera::GetPosition()
{
	return mPositionOfCamera;
}

//RECT Camera::GetBound()
//{
//    RECT bound; 
//
//    bound.left = mPosition.x - mWidth / 2;
//    bound.right = bound.left + mWidth;
//    bound.top = mPosition.y - mHeight / 2;
//    bound.bottom = bound.top + mHeight;
//
//    return bound;
//}

//int Camera::GetWidth()
//{
//    return mWidth;
//}

//int Camera::GetHeight()
//{
//    return mHeight;
//}