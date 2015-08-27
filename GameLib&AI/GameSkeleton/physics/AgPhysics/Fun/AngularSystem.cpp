#include "AngularSystem.h"

DebugSlider* SunMass;
DebugSlider* P1Mass;
DebugSlider* MoonMass;
DebugSlider* P2Mass;
DebugSlider* AngularVel;
QPushButton* ThrowIt;
QPushButton* Resetit;

AngularSystem::AngularSystem(void)
{
}

void AngularSystem::ThrowSystem()
{
	if(rotating)
	{
		rotating = false;
	}
}

void AngularSystem::ResetSystem()
{
	rotating = true;
	Sun.Position = glm::vec3(0.0f, 0.0f, 0.0f);

	//Planet1
	Planet1.Position = glm::vec3(0.0f, 1.0f, 0.0f);

	//Planet2
	Planet2.Position = glm::vec3(0.0f, 1.0f, 0.0f);

	//Moon
	Moon.Position = (Planet1.Position - Sun.Position)*(MoonMass->value()+P1Mass->value());
}
AngularSystem::AngularSystem(DebugSlider& Sunmass,DebugSlider& p1mass,DebugSlider& mmass,DebugSlider& p2mass,DebugSlider& AngularVelocity,QPushButton& throws,QPushButton& resets)
{
	SunMass = &Sunmass;
	P1Mass = &p1mass;
	MoonMass= &mmass;
	P2Mass = &p2mass;
	AngularVel = &AngularVelocity;
	ThrowIt =  &throws;
	Resetit = &resets;
}
void AngularSystem::initialize()
{
	GuiBase::initialize(false, true);
	rotating = true;


	//Sun
	partGraph = addVectorGraphic();
	partGraph->r =255;
	partGraph->b=255;
	Sun.Position = glm::vec3(0.0f, 0.0f, 0.0f);
	Sun.mass = 1.0f;
	partGraph->pointSize = Sun.mass;
	system[0]= Sun;

	//Planet1
	p1graph = addVectorGraphic();
	p1graph->g =255;
	p1graph->b=255;
	Planet1.Position = glm::vec3(0.0f, 1.0f, 0.0f);
	Planet1.mass = P1Mass->value();
	p1graph->pointSize = Planet1.mass;
	system[1]= Planet1;


	//Planet2
	p2graph = addVectorGraphic();
	p2graph->b=255;
	Planet2.Position = glm::vec3(0.0f, 1.0f, 0.0f);
	Planet2.mass = P2Mass->value();
	p2graph->pointSize = Planet2.mass;
	system[2]= Planet2;


	//Moon
	moon = addVectorGraphic();
	moon->r =155;
	Moon.Position = (Planet1.Position - Sun.Position)*(MoonMass->value()+P1Mass->value());
	Moon.mass = MoonMass->value();
	moon->pointSize = Moon.mass;
	system[3]= Moon;


	ThingsContact.restitution = 0.9f;

}

void AngularSystem::newFrame()
{

	partGraph->pointSize = SunMass->value();
	p1graph->pointSize = P1Mass->value();
	p2graph->pointSize = P2Mass->value();
	moon->pointSize = MoonMass->value();
	if(ThrowIt->isDown())
	{
		ThrowSystem();
	}
	if(Resetit->isDown())
	{
		ResetSystem();
	}
	if(rotating)
	{
		Planet1.Position = glm::normalize(Planet1.Position) * ((P1Mass->value()) + (SunMass->value()));
		glm::vec3 Rperp = glm::vec3(-Planet1.Position.y, Planet1.Position.x, Planet1.Position.z);
		glm::vec3 newAngularVelocity = AngularVel->value() * Rperp;
		Planet1.Velocity = newAngularVelocity;
		Planet1.Position += (Planet1.Velocity * P1Mass->value()) * dt();

		Moon.Position = glm::normalize(Moon.Position) * ((P1Mass->value()) + (MoonMass->value()*.75f));
		Rperp = glm::vec3(-Moon.Position.y, Moon.Position.x, Moon.Position.z);
		newAngularVelocity = AngularVel->value() * Rperp;
		Moon.Velocity = newAngularVelocity;
		Moon.Position += (Moon.Velocity / MoonMass->value()) * dt();


		Planet2.Position = glm::normalize(Planet2.Position) * (P2Mass->value()+(MoonMass->value() + (P1Mass->value() + SunMass->value()*1.5f)));
		Rperp = glm::vec3(-Planet2.Position.y, Planet2.Position.x, Planet2.Position.z);
		newAngularVelocity = AngularVel->value() * Rperp + Planet1.Position;
		Planet2.Velocity = newAngularVelocity;
		Planet2.Position += (Planet2.Velocity * P2Mass->value()) * dt();
	}
	else
	{
		Sun.Position += (Planet1.Velocity / SunMass->value()) * dt();
		Planet1.Position += (Planet1.Velocity * P1Mass->value()) * dt();
		Planet2.Position += (Planet2.Velocity * P2Mass->value()) * dt();
		Moon.Position += (Moon.Velocity / MoonMass->value()) * dt();
	}
	
	sync(partGraph, Sun.Position);
	sync(p1graph, Planet1.Position);
	sync(moon, Moon.Position,Planet1.Position);
	sync(p2graph, Planet2.Position);

	//sync(velocityGraph, Planet1.Velocity, Planet1.Position);
}