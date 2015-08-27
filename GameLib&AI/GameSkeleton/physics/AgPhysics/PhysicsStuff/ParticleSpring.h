#pragma once
#include "PfGen.h"
class ParticleSpring : public PfGen
{
	
public:
	Particle* other;
	float SpringConstant;
	float restLength;
	ParticleSpring();
	ParticleSpring(Particle *other,float SpringConstant,float restLength);
	virtual void updateForce(Particle* particle,float duration);
	
};

