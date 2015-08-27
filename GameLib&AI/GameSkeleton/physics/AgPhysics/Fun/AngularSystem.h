#ifndef ANGULAR_VELOCITY_H
#define ANGULAR_VELOCITY_H
#include <PhysicsGui\GuiBase.h>
#include <PhysicsGui\VectorGraphic.h>
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "..\PhysicsStuff\PfGen.h"
#include "Qt\qpushbutton.h"
#include "..\PhysicsStuff\DebugSlider.h";
#include "..\PhysicsStuff\ParticleContacts.h"
using std::vector;


class AngularSystem : public GuiBase
{

	Particle Sun;
	Particle Planet1;
	Particle Planet2;
	Particle Moon;
	VectorGraphic* partGraph;
	VectorGraphic* p1graph;
	VectorGraphic* p2graph;
	VectorGraphic* moon;
	VectorGraphic* velocityGraph;
	ParticleContact ThingsContact;
	ParticleContactResolver resolver;
	vector<ParticleContact> contactVec;
	Particle system[4];


public:
	AngularSystem(void);
	AngularSystem(DebugSlider& Sunmass,DebugSlider& p1mass,DebugSlider& mmass,DebugSlider& p2mass,DebugSlider& AngularVelocity,QPushButton& throws,QPushButton& resets);
	void ThrowSystem();
	void ResetSystem();
	void initialize();
	void newFrame();
	float radius;
	float angularVel;
	bool rotating;

};

#endif	
