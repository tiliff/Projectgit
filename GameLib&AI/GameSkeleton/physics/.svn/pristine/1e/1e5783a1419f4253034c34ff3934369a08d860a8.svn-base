#pragma once
#include "Particle.h"
class ParticleContact 
{
public:
	ParticleContact();
	Particle* particle[2];
	float restitution;
	float penetration;
	glm::vec3 contactNormal;
	glm::vec3 particleMovement[2];
	void resolve(float duration);
	float calculateSeperatingVelocity() const;
	void setParticles(glm::vec3 contact,float restit,Particle* P1,Particle* P2=NULL);

private:
	void resolveVelocity(float duration);
	void resolveInterpenetration(float duration);
};

