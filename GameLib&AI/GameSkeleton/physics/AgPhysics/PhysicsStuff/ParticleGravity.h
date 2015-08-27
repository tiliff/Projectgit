#pragma once
#include "PfGen.h"
class ParticleGravity : public PfGen
{
	glm::vec3 gravity;
public:
	ParticleGravity();
	ParticleGravity(const glm::vec3 &gravity);
	virtual void updateForce(Particle *Particle, float duration);
};

