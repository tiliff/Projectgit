#ifndef ANGULAR_VELOCITY_H
#define ANGULAR_VELOCITY_H
#include <PhysicsGui\GuiBase.h>
#include <PhysicsGui\VectorGraphic.h>
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "..\PhysicsStuff\PfGen.h"
#include "Qt\qpushbutton.h"
#include "..\PhysicsStuff\DebugSlider.h";

class AngularVelocityLab : public GuiBase
{

	Particle particle;
	VectorGraphic* partGraph;
	VectorGraphic* velocityGraph;


public:
	AngularVelocityLab(void);
	AngularVelocityLab(QPushButton& Throw,QPushButton& Reset,DebugSlider& Radius,DebugSlider& AngularVelocity);
	void initialize();
	void newFrame();
	void throwBall();
	void retrieveBall();
	float radius;
	float angularVel;
	bool rotating;

};

#endif	
