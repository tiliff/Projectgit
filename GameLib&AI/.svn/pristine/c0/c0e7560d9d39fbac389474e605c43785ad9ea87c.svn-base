#include "RestingContact.h"
#include <sstream>
QLabel* IBV;
QLabel* OutBV;
DebugSlider* restit;
QPushButton* resetToFall;
QPushButton* resettorest;
bool isatrest=false;
std::string Convertin(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
RestingContactLab::RestingContactLab(void)
{
}
RestingContactLab::RestingContactLab(QLabel& INBV, QLabel& OBV,DebugSlider& restitution,QPushButton& resetTF,QPushButton& resetTR)
{
	IBV=&INBV;
	OutBV=&OBV;
	restit=&restitution;
	resetToFall=&resetTF;
	resettorest=&resetTR;
}
void RestingContactLab::initialize()
{
	GuiBase::initialize(false,true);
	Grav=glm::vec3(0.0f,-5.0f,0.0f);
	restitution=restit->value();
	pg=addVectorGraphic();
	pg->r=190;
	pg->b=190;
	pg->g=100;
	p.Position=glm::vec3(-5.0f,3.0f,0.0f);
	p.Velocity=glm::vec3(2.0f,0.0f,0.0f);
	p.mass=1.0f;
	p.Damper=0.997f;
	
	outgoingbounce=0.0f;
	pfr.add(&p,&Grav);
}
void RestingContactLab::newFrame()
{
	pfr.updateForces(dt());
	restitution=restit->value();
	if(resetToFall->isDown())
	{
		ResetToFall();
	}
	if(resettorest->isDown())
	{
		ResetToRest();
	}
	p.Acceleration=p.SumofForces/p.mass;
	p.Velocity=(p.Velocity*p.Damper) + p.Acceleration *dt();
	p.Position+=p.Velocity*dt();
	p.clearForces();
	incomingbounce=glm::length(p.Velocity);
	IBV->setText(Convertin(incomingbounce).c_str());

	float radius=p.mass * 0.5f;
	glm::vec3 distance=p.Position-glm::vec3(p.Position.x,0.0f,0.0f);
	glm::vec3 Cnormal=glm::normalize(distance);
	float distanceLength=glm::dot(p.Position,Cnormal);
	if(distanceLength <= radius)
	{
		Pc.setParticles(glm::vec3(0.0f,1.0f,0.0f),restitution,&p);
		Pc.penetration=radius - glm::dot(p.Position,Cnormal);
		Pc.resolve(dt());
		if(isatrest)
		{
		p.Velocity=glm::vec3(0.0f,0.0f,0.0f);
		}
		outgoingbounce=glm::length(p.Velocity);
		OutBV->setText(Convertin(outgoingbounce).c_str());
	}
	sync(pg,p.Position);
}
void RestingContactLab::ResetToFall()
{
	p.Position=glm::vec3(-5.0f,3.0f,0.0f);
	p.Velocity=glm::vec3(2.0f,0.0f,0.0f);
	isatrest=false;
}
void RestingContactLab::ResetToRest()
{
	p.Position=glm::vec3(0.0f,p.mass*0.5f,0.0f);
	p.Velocity=glm::vec3(0.0f,0.0f,0.0f);
	isatrest=true;
}