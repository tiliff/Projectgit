#pragma once
#include "GameObject.h"
#include "Matrix3.h"
#include "ParticleSystem.h"





class Spaceship : public GameObject
{
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d* outlinep;
	float size;
	int numline;
	float dragCoeff;
	float angle;
	bool gameOver;


	Spaceship(int numLines,Vector2d* outline,Vector2d Shippos):GameObject(numLines , outline)
	{
		velocity= Vector2d(0.0f,0.0f);
		dragCoeff=0.99f;
		size=0.45f;
		position=Shippos;
		outlinep=outline;
		numline=numLines;
		angle=0;
		gameOver=false;
		
	}
	void Draw(Core::Graphics& g);
	void Wrapship(Vector2d position);
	void Update(float dt);
	void WallBounce(Vector2d position);
	void artWallBounce();
	void wallResponse(Vector2d perp);
};