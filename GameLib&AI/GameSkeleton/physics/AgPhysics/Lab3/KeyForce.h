#pragma once
#include "..\PhysicsStuff\PfGen.h"
#include <Windows.h>

class KeyForce :public PfGen
{
public:
	glm::vec3 iWasForced;
public:
	KeyForce();
	KeyForce(const glm::vec3 &force);
	virtual void updateForce(Particle *Particle, float duration);
	glm::vec3 getUserDirection();
};

