#pragma once
#include "..\PhysicsGui\include\PhysicsGui\GuiBase.h"
#include "..\PhysicsGui\include\PhysicsGui\VectorGraphic.h"
#include "..\PhysicsStuff\Particle.h"
#include "..\PhysicsStuff\ParticleGravity.h"
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "Qt\qpushbutton.h"
#include "KeyForce.h"

class Forces : public GuiBase
{
	VectorGraphic* keygraphic;
	VectorGraphic* multiple;
	VectorGraphic* grav;
	Particle multip;
	Particle keyp;
	Particle gravp;
	ParticleGravity pg;
	ParticleForceRegistry pfr;
	KeyForce kweef;
protected:
	void newFrame();
public:
	Forces(QPushButton &reset);
	void initialize();
	glm::vec3 getUserDirection();

};

