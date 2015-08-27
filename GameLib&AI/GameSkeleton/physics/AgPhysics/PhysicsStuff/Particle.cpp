#include "Particle.h"

void Particle::clearForces()
{
	SumofForces=glm::vec3();
}

void Particle::addForce(const glm::vec3 &v)
{
	this->SumofForces += v;
}

void Particle::calculateMoment()
{
	this->Momentum=this->Velocity*this->mass;
}

void Particle::calculateVelocity()
{
	this->Velocity=(this->Momentum/this->mass);
}

void Particle::integrate(float dt)
{
	glm::vec3 acceleration = SumofForces/mass;

	this->Velocity += acceleration * dt;
	this->Position += this->Velocity * dt;
	this->SumofForces = glm::vec3();
}