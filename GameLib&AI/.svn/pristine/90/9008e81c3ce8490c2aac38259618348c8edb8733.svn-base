#include "ParticleForceRegistry.h"


	void ParticleForceRegistry::add(Particle* particle, PfGen* fg)
	{
		ParticleForceRegistration temp;
		temp.particle=particle;
		temp.fg=fg;
		registrations.push_back(temp);
	}
	void ParticleForceRegistry::remove(Particle* particle, PfGen* fg)
	{
		for(int i=0; i < registrations.size();i++)
		{
			if(registrations[i].particle==particle&&registrations[i].fg==fg)
			{
             registrations.erase(registrations.begin()+i);
			}
		}
	}
	void ParticleForceRegistry::clear()
	{
		registrations.clear();
	}

void ParticleForceRegistry::updateForces(float duration)
{
	Registry::iterator i =registrations.begin();
	for(;i!= registrations.end();i++)
	{
		i->fg->updateForce(i->particle,duration);
	}
}
