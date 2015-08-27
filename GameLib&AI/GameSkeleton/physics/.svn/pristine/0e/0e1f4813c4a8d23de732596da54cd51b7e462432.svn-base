#include "AngularVelocityLab.h"

DebugSlider* rad;
DebugSlider* angvel;
QPushButton* toss;
QPushButton* resets;

AngularVelocityLab::AngularVelocityLab(void)
{
}

void AngularVelocityLab::throwBall()
{
	if(rotating)
	{
		rotating = false;
	}
}

void AngularVelocityLab::retrieveBall()
{
	rotating = true;
	particle.Position = glm::vec3(0.0f, 3.0f, 0.0f);
}
AngularVelocityLab::AngularVelocityLab(QPushButton& Throw,QPushButton& Reset,DebugSlider& Radius,DebugSlider& AngularVelocity)
{
	rad = &Radius;
	resets = &Reset;
	toss = &Throw;
	angvel = &AngularVelocity;
}
void AngularVelocityLab::initialize()
{
	GuiBase::initialize(false, true);
	rotating = true;


	//Particle
	partGraph = addVectorGraphic();
	partGraph->r =255;
	partGraph->b=255;
	particle.Position = glm::vec3(0.0f, 3.0f, 0.0f);
	particle.mass = 0.5f;
	partGraph->pointSize = particle.mass;

	//Vector
	velocityGraph = addVectorGraphic();
	velocityGraph->r =255;
	velocityGraph->b=255;
	velocityGraph->displayStyle = DS_ARROW;

}

void AngularVelocityLab::newFrame()
{
	if(toss->isDown()){
		throwBall();
	}
	if(resets->isDown()){
		retrieveBall();
	}
	if(rotating)
	{
		particle.Position = glm::normalize(particle.Position) * rad->value();
		glm::vec3 Rperp = glm::vec3(-particle.Position.y, particle.Position.x, particle.Position.z);
		glm::vec3 newAngularVelocity = angvel->value() * Rperp;
		particle.Velocity = newAngularVelocity;
		particle.Position += particle.Velocity * dt();
	}
	else
	{
		particle.Position += particle.Velocity * dt();
	}

	sync(partGraph, particle.Position);
	sync(velocityGraph, particle.Velocity, particle.Position);
}