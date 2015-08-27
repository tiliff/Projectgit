#pragma once
#include "Vector2d.h"
#include "GameObject.h"

class Lerper : GameObject 
{
	float alpha;
	Vector2d position;
	int currentpath;
public:
	Lerper(int numLines,Vector2d* outline): GameObject(numLines,outline)
	{
		alpha=0.0f;
		position=Vector2d(955,520);
		currentpath=0;
		
	}
	void Update(float dt);
	void Draw(Core::Graphics& g)
	{
		shape.Draw(g,Lerper::position);
		
	}
};