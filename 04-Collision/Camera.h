#pragma once

#include <d3dx9.h>
#include <d3d9.h>


class Camera
{
public:
	Camera(int, int);

	//center of camera
	void SetPosition(float x, float y);
	void SetPosition(D3DXVECTOR2 pos);
	D3DXVECTOR2 Transform(float zx, float zy);
	//int GetWidth();
	//int GetHeight();


	void Update();
	D3DXVECTOR3 GetPosition();
	RECT GetBound();

	~Camera();

	static Camera * GetInstance();

private:
	static Camera*  __instance;
	D3DXVECTOR2     mPositionOfCamera;
};

