#include "KeyForce.h"


KeyForce::KeyForce()
{

}

KeyForce::KeyForce(const glm::vec3 &force)
{
	iWasForced=force;
}

glm::vec3 KeyForce::getUserDirection()
{
	glm::vec3 ret;
	if(GetAsyncKeyState('W'))
	{
		ret=glm::vec3(0.0f,1.0f,0.0f);
	}
	if(GetAsyncKeyState('A'))
	{
		ret=glm::vec3(-1.0f,0.0f,0.0f);
	}
	if(GetAsyncKeyState('S'))
	{
		ret=glm::vec3(0.0f,-1.0f,0.0f);
	}
	if(GetAsyncKeyState('D'))
	{
		ret=glm::vec3(1.0f,0.0f,0.0f);
	}
	return ret;
}

void KeyForce::updateForce(Particle* particle,float duration)
{
	particle->addForce(iWasForced * KeyForce::getUserDirection());
}