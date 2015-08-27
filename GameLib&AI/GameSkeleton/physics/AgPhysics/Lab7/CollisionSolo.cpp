#include "CollisionSolo.h"
#include <sstream>
DebugSlider* massP1;
DebugSlider* massP2;
DebugSlider* rest;
DebugSlider* VelP1;
DebugSlider* VelP2;
QPushButton* rese;
QLabel* velx1;
QLabel* velx2;
QLabel* TM;
QLabel* TK;
std::string cConvertString(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
CollisionSolo::CollisionSolo(DebugSlider &mass1,DebugSlider &mass2,DebugSlider &restitution,DebugSlider &velocity1,DebugSlider &velocity2,QPushButton &reset,QLabel &xVel1,QLabel &xVel2,QLabel &TMoment,QLabel &TKinEn)
{
	massP1=&mass1;
	massP2=&mass2;
	rest=&restitution;
	VelP1=&velocity1;
	VelP2=&velocity2;
	rese=&reset;
	velx1=&xVel1;
	velx2=&xVel2;
	TM=&TMoment;
	TK=&TKinEn;
}
void CollisionSolo::initialize()
{
	GuiBase::initialize(false, true);
	P1g = addVectorGraphic();
	P2g = addVectorGraphic();
	vg1 = addVectorGraphic();
	vg2 = addVectorGraphic();
	vg1->displayStyle=DS_ARROW;
	vg2->displayStyle=DS_ARROW;
    P1g->g=255;
	P2g->r=255;
	P2g->b=255;
	vg1->r=255;
	vg1->b=255;
	vg2->g=255;
	p1.Position=glm::vec3(-4.0f,0.0f,0.0f);
	P2.Position=glm::vec3(4.0f,0.0f,0.0f);
	p1.Velocity.x=2.0f;
	P2.Velocity.x=-3.0f;
	p1.mass=massP1->value();
	P2.mass=massP2->value();
}
void CollisionSolo::newFrame()
{
	p1.mass=massP1->value();
	P2.mass=massP2->value();
	float Tm=(p1.mass * p1.Velocity.x)+(P2.mass * P2.Velocity.x);
	TM->setText(cConvertString(Tm).c_str());
	velx1->setText(cConvertString(p1.Velocity.x).c_str());
	velx2->setText(cConvertString(P2.Velocity.x).c_str());
	float TotalKinetic=(p1.mass * 0.5f) * pow(p1.Velocity.x,2.0f) + (P2.mass * 0.5f) * pow(P2.Velocity.x,2.0f);
	TK->setText(cConvertString(TotalKinetic).c_str());
	float radius= (p1.mass*0.5f) + (P2.mass*0.5f);
	glm::vec3 distance = p1.Position - P2.Position;
	float distanceLength= glm::length(distance);
	float restittution=rest->value();
	
	if(distanceLength <= radius)
	{
		glm::vec3 contactNormal = glm::normalize(distance);
		pc.setParticles(contactNormal,restittution,&p1,&P2);
		pc.resolve(dt());
	}
	p1.Position += p1.Velocity*dt();
    P1g->pointSize=massP1->value();
	P2.Position += P2.Velocity*dt();
    P2g->pointSize=massP2->value();
	if(rese->isDown())
	{
		p1.Position=glm::vec3(-4.0f,0.0f,0.0f);
	    P2.Position=glm::vec3(4.0f,0.0f,0.0f);
		p1.Velocity.x=VelP1->value();
	    P2.Velocity.x=VelP2->value();
	}
	sync(P1g,p1.Position);
	sync(P2g,P2.Position);
	sync(vg1,p1.Velocity,p1.Position);
	sync(vg2,P2.Velocity,P2.Position);
}

