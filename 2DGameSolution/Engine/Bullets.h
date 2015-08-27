#pragma once
#include "GameObject.h"
#include "Matrix3.h"




const float bulletspeed=5;
class Bullet : GameObject
{
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d* outlinep;
	int lines;
	bool fired;
	Bullet(int numLines,Vector2d* outline):GameObject(numLines , outline)
	{
		velocity= Vector2d(0.0f,0.0f);
		position=Vector2d(2000.0f,0.0f);
		outlinep=outline;
		lines=numLines;
		fired=false;
		
	}
	void draw(Core::Graphics& g);
	void Update(float dt);
	void resetBullet(Vector2d pos,Vector2d vel);
};
