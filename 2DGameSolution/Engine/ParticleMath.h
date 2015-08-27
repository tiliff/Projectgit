#pragma once
#include <stdlib.h>
#include "Vector2d.h"

const float TWO_PI = 2*3.1415926f;
class randomness
{
public:
float RandomFloat()
{
	return (float) rand() / RAND_MAX;
}


Vector2d RandomUnitVector()
{
	float angle = TWO_PI * RandomFloat();
	return Vector2d( cos(angle), sin(angle) );
}
float randomInRange(float min,float max)
{
	return RandomFloat()*(max-min+1)+min;
}
};