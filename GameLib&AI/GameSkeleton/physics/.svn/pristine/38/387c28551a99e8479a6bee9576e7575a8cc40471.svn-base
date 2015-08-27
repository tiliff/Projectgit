#pragma once
#include "..\PhysicsStuff\DebugSlider.h"
#include "Qt\qpushbutton.h"
#include "..\PhysicsGui\include\PhysicsGui\GuiBase.h"
#include "..\PhysicsStuff\Particle.h"
#include "QtGui\qlabel.h"
#include "QtGui\qcheckbox.h"
#include "..\PhysicsStuff\ParticleContact.h"
class CollisionSolo : public GuiBase
{
	
public:	
	Particle p1;
	Particle P2;
	ParticleContact pc;
	VectorGraphic* P1g;
	VectorGraphic* P2g;
	VectorGraphic* vg1;
	VectorGraphic* vg2;
	CollisionSolo(DebugSlider &mass1,DebugSlider &mass2,DebugSlider &restitution,DebugSlider &velocity1,DebugSlider &velocity2,QPushButton &reset,QLabel &xVel1,QLabel &xVel2,QLabel &TMoment,QLabel &TKinEn);
	void initialize();
protected:
	void newFrame();
};

