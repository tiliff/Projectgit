#include "MeParticleDemo.h"
#include <Qt\qdebug.h>
#include "Windows.h"

void MeParticleDemo::initialize()
{
	GuiBase::initialize(false, true);
	p.mass=1;
	graphic = addVectorGraphic();
	velocityGraphic = GuiBase::addVectorGraphic();
	velocityGraphic->displayStyle =DS_ARROW;
	velocityGraphic->r=255;
	graphic->position=p.Position;
}
void MeParticleDemo::newFrame()
{
	p.SumofForces += getUserDirection();
	p.integrate(dt());
	sync(graphic,p.Position);
	sync(velocityGraphic,p.Velocity,p.Position);
}
void MeParticleDemo::vectorGraphicMouseDrag(uint vectorGraphicIndex,const glm::vec3& dragDelta)
{
	p.Position += dragDelta;
}
glm::vec3 MeParticleDemo::getUserDirection()
{
	glm::vec3 ret;
	if(GetAsyncKeyState(VK_UP))
	{
		ret=glm::vec3(0.0f,1.0f,0.0f);
	}
	if(GetAsyncKeyState(VK_LEFT))
	{
		ret=glm::vec3(-1.0f,0.0f,0.0f);
	}
	if(GetAsyncKeyState(VK_DOWN))
	{
		ret=glm::vec3(0.0f,-1.0f,0.0f);
	}
	if(GetAsyncKeyState(VK_RIGHT))
	{
		ret=glm::vec3(1.0f,0.0f,0.0f);
	}
	return ret;
}



