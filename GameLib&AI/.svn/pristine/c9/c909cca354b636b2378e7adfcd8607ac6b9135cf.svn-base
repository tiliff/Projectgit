#include "ParticleSpring.h"


ParticleSpring::ParticleSpring(void)
{
}

ParticleSpring::ParticleSpring(Particle *other,float SpringConstant,float restLength)
{
	this->other=other;
	this->SpringConstant=SpringConstant;
	this->restLength=restLength;
}
void ParticleSpring::updateForce(Particle* particle,float duration)
{
	glm::vec3 force;
	force=particle->Position-other->Position;

	float magnitude=glm::length(force);
	magnitude=magnitude-restLength;
	magnitude *= SpringConstant;

	force=glm::normalize(force);
	force *= -magnitude;
	particle->addForce(force);
}
