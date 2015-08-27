#include "DragForces.h"
#include "..\Lab1\MeParticleDemo.h"
#include <Qt\qdebug.h>
#include "Windows.h"
DebugSlider* k1;
DebugSlider* k2;
void DragForces::initialize()
{
	GuiBase::initialize(false, true);

	dragForce = ParticleDrag(k1->value(),k2->value());

	p.mass=0.5f;
	graphic = addVectorGraphic();
	graphic->r=200;
	graphic->b=200;
	p.Position=glm::vec3(-3.0f,0.0f,0.0f);
	p.Velocity=glm::vec3(10.0f,0.0f,0.0f);
	pf.add(&p,&dragForce);
}
DragForces::DragForces(DebugSlider &Low,DebugSlider &High)
{
	k1=&Low;
	k2=&High;
}
void DragForces::newFrame()
{
	if(p.Velocity.x<=0.5f || p.Position.x >= 5.0f)
	{
		p.Position=glm::vec3(-3.0f,0.0f,0.0f);
		p.Velocity=glm::vec3(10.0f,0.0f,0.0f);
		p.clearForces();
	}
	pf.updateForces(dt());
	dragForce = ParticleDrag(k1->value(),k2->value());
	p.Velocity+=p.SumofForces* dt();
	p.Position+=p.Velocity * dt();
	p.clearForces();
	sync(graphic,p.Position);
}





