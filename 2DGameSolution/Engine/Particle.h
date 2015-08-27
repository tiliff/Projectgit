#pragma once
#include "Vector2d.h"
#include "Core.h"
using Core::RGB;
class Particle
{
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d newVelocity;
	float lifetime;
	RGB color;
	int type;
	int size;
};