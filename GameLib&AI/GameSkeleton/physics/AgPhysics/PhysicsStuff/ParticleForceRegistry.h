#pragma once
#include "Particle.h"
#include "..\PhysicsStuff\PfGen.h"
#include <vector>
class ParticleForceRegistry
{
protected:
	struct ParticleForceRegistration
	{
		Particle * particle;
		PfGen *fg;
	};
	typedef std::vector<ParticleForceRegistration> Registry;
	Registry registrations;
public:

	void add(Particle* particle, PfGen* fg);
	void remove(Particle* particle, PfGen* fg);
	void clear();
	void updateForces(float duration);
};

