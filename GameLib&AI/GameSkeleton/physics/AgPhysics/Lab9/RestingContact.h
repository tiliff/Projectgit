#pragma once
#include "..\PhysicsStuff\DebugSlider.h"
#include "Qt\qpushbutton.h"
#include <..\..\MiddleWare\PhysicsGui\include\PhysicsGui\GuiBase.h>
#include "..\PhysicsStuff\Particle.h"
#include <QtGui\qlabel.h>
#include <QtGui\qcheckbox.h>
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "..\PhysicsStuff\ParticleGravity.h"
#include "..\PhysicsStuff\ParticleContact.h"
class RestingContactLab : public GuiBase
{
	Particle p;
	VectorGraphic* pg;
	ParticleForceRegistry pfr;
	ParticleGravity Grav;
	
public:
	ParticleContact Pc;
	RestingContactLab();
	RestingContactLab(QLabel& INBV, QLabel& OBV,DebugSlider& restitution,QPushButton& resetTF,QPushButton& resetTR);
	void ResetToFall();
	void ResetToRest();
	void initialize();
	void newFrame();
	float incomingbounce;
	float outgoingbounce;
	float restitution;
};

