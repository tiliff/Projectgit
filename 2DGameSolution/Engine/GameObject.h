#pragma once
#include "Vector2d.h"
#include "Shape.h"
class GameObject
{
	
	
public:
	Shape shape;
	Vector2d position;
	GameObject(int numLines,Vector2d* outline): shape(numLines,outline)
	{

	}
	void Draw(Core::Graphics& g)
	{
		shape.Draw(g,position);
	}
};