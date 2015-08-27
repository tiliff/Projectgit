#pragma once
#include "glm\glm.hpp"
class Particle
{
public:
	glm::vec3 Position;
	glm::vec3 Velocity;
	glm::vec3 Momentum;
	glm::vec3 Acceleration;
	float Damper;
	float mass;
	glm::vec3 SumofForces;

	void clearForces();
	void addForce(const glm::vec3 &v);
	void calculateMoment();
	void calculateVelocity();
	void integrate(float dt);
};

