#pragma once
#include "..\PhysicsStuff\ParticleContact.h"

class ParticleContactResolver
{

protected:
	unsigned int iterations;
	unsigned int iterationsUsed;

public:
	ParticleContactResolver();
	ParticleContactResolver(unsigned int iterations);
	void setIterations(unsigned int iterations);
	void resolveContacts(ParticleContact *, unsigned int numContacts, float duration);

};

