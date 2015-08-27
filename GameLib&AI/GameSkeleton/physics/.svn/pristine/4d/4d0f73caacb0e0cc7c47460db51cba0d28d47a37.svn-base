#pragma once
#include "..\PhysicsStuff\DebugSlider.h"
#include "Qt\qpushbutton.h"
#include <..\..\MiddleWare\PhysicsGui\include\PhysicsGui\GuiBase.h>
#include "..\PhysicsStuff\Particle.h"
#include <QtGui\qlabel.h>
#include <QtGui\qcheckbox.h>
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "..\PhysicsStuff\ParticleGravity.h"
#include "..\PhysicsStuff\ParticleContacts.h"
using std::vector;
class RestingContactsLab : public GuiBase
{
	Particle towerDestroyer;
	//Particle tower1;
	//Particle tower2;
	//Particle tower3;
	//Particle tower4;
	Particle tower[4];

	VectorGraphic* destroyerGraphic;
	//VectorGraphic* tower1Graph;
	//VectorGraphic* tower2Graph;
	//VectorGraphic* tower3Graph;
	//VectorGraphic* tower4Graph;
	VectorGraphic* towerGraphs[4];

	ParticleForceRegistry registry;
	ParticleGravity gravity;
	ParticleGravity grav;
	ParticleContact contact;
	ParticleContact floorContact;
	ParticleContactResolver resolver;
	vector<ParticleContact> contactVec;

public:
	RestingContactsLab(QPushButton& reset);
	void initialize();
	void newFrame();
	void reset();
	float restitution;

};

