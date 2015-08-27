#include "SpringForces.h"

DebugSlider* springconst;
DebugSlider* restlength;

SpringForces::SpringForces(DebugSlider &SpringConst,DebugSlider &RestLength)
{
	springconst=&SpringConst;
	restlength=&RestLength;
}
void SpringForces::initialize()
{
	GuiBase::initialize(false,true);
	ps.SpringConstant=4.0f;
	ps.restLength=4.0f;
	ps=ParticleSpring(&p2,springconst->value(),restlength->value());
	graphic = addVectorGraphic();
	graphic2 = addVectorGraphic();
	graphic->b=255;
	graphic2->g=255;
	p.Damper=0.99f;
	p2.Damper=0.99f;
	p.Position=glm::vec3(-2.0f,0.0f,0.0f);
	p2.Position=glm::vec3(2.0f,0.0f,0.0f);
	p.mass=1.0f;
	p2.mass=1.0f;
	pf.add(&p,&ps);

}
void SpringForces::vectorGraphicMouseDrag(uint vectorGraphicIndex,const glm::vec3& dragDelta)
{
	if(vectorGraphicIndex==0)
	{
	p.Position+= dragDelta;
	}
	else
	{
	p2.Position+= dragDelta;
	}
}
void SpringForces::newFrame()
{
	ps=ParticleSpring(&p2,springconst->value(),restlength->value());
	pf.updateForces(dt());
	p.Acceleration=p.SumofForces/p.mass;
	p.Velocity=(p.Velocity) + p.Acceleration * dt();
	p.Velocity=p.Velocity *p.Damper;
	p.Position+=p.Velocity*dt();
	p.clearForces();
    sync(graphic,p.Position);
	sync(graphic2,p2.Position);
}