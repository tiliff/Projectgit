#include "ParticleContact.h"


ParticleContact::ParticleContact()
{

}

void ParticleContact::setParticles(glm::vec3 contact,float restit,Particle* P1,Particle* P2)
{
	this->particle[0]=P1;
	this->particle[1]=P2;
	this->contactNormal=contact;
	this->restitution=restit;
}
void ParticleContact::resolve(float duration)
{
	resolveVelocity(duration);
	resolveInterpenetration(duration);
}
float ParticleContact::calculateSeperatingVelocity() const
{
	glm::vec3 relativeVelocity = particle[0]->Velocity;
	if(particle[1]) relativeVelocity -=particle[1]->Velocity;
	return glm::dot(relativeVelocity,contactNormal);
}

void ParticleContact::resolveVelocity(float duration)
{
	float seperatingVelocity=calculateSeperatingVelocity();

	if(seperatingVelocity > 0)
	{
		return;
	}
	float newSeperatingVelocity= -seperatingVelocity*restitution;
	float deltaVelocity = newSeperatingVelocity - seperatingVelocity;
	float totalInverseMass= 1/particle[0]->mass;
	if(particle[1])
	{
		totalInverseMass+=1/particle[1]->mass;
	}
	if(totalInverseMass<=0)
	{
		return;
	}
	float impulse=deltaVelocity / totalInverseMass;
	glm::vec3 impulsePerIMass =contactNormal * impulse;

	particle[0]->Velocity=particle[0]->Velocity + impulsePerIMass * (1/particle[0]->mass);

	if(particle[1])
	{
	particle[1]->Velocity=particle[1]->Velocity + impulsePerIMass * -(1/particle[1]->mass);
	}
}
void ParticleContact::resolveInterpenetration(float duration)
{
	if(penetration <= 0)
	{
		return;
	}

	float totalInverse= 1/particle[0]->mass;
	if(particle[1])
	{
		totalInverse+= 1/particle[1]->mass;
	}

	if(totalInverse <= 0)
	{
		return;
	}

	glm::vec3 movepermass = contactNormal * (penetration / totalInverse);

	particleMovement[0] = movepermass * (1/ particle[0]->mass);
	if(particle[1])
	{
	particleMovement[1] = movepermass * (1/ particle[1]->mass);
	}
	else
	{
		particleMovement[1].null;
	}

	particle[0]->Position = particle[0]->Position + particleMovement[0];
	if(particle[1])
	{
	particle[1]->Position = particle[1]->Position + particleMovement[1];
	}
}