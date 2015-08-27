#pragma once
#include "GameObject.h"
#include "Matrix3.h"
#include "Bullets.h"



class Turret : GameObject
{
	public:
	Vector2d* outlinep;
	Vector2d position;
	int NUM_TURRETPOINTS;
	Vector2d mouse;
	Vector2d turretface;
	Turret(int numLines,Vector2d* outline,Vector2d shippos): GameObject(numLines,outline)
	{
		mouse=Vector2d(0.0f+Core::Input::GetMouseX(), 0.0f+Core::Input::GetMouseY());
		NUM_TURRETPOINTS=numLines;
		outlinep=outline;
		position=shippos;
		
	}
	~Turret()
	{
		delete this;
	}
	void Draw(Core::Graphics& g);
	Matrix3 rotateTurret(Vector2d mouse);
	void updatepos(float dt,Vector2d shippos);
	Vector2d GetBulPos(int i);
};
