#include "ParticleGravity.h"


ParticleGravity::ParticleGravity()
{
}

ParticleGravity::ParticleGravity(const glm::vec3 &gravity)
{
	this->gravity = gravity;
}

void ParticleGravity::updateForce(Particle* particle,float duration)
{
	particle->addForce(gravity * particle->mass);
}



