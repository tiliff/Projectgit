#include "ParticleDrag.h"


ParticleDrag::ParticleDrag(void)
{
}


ParticleDrag::ParticleDrag(float k1,float k2)
{
 this->k1=k1;
 this->k2=k2;
}
void ParticleDrag::updateForce(Particle *particle,float duration)
{
	glm::vec3 force;
	force=particle->Velocity;
	float dragCoef= glm::length(force);
	dragCoef= k1 * dragCoef + k2 * dragCoef * dragCoef;
	if(glm::normalize(force)==glm::vec3())
	{
	particle->addForce(force);
	}
	else
	{
	force=glm::normalize(force);
	force *= -dragCoef;
	particle->addForce(force);
	}
}