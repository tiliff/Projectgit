#ifndef CHASLES_THEOREM_H
#define CHASLES_THEOREM_H

#include <PhysicsGui\GuiBase.h>
#include <PhysicsGui\VectorGraphic.h>
#include <glm\gtx\rotate_vector.hpp>
#include <Windows.h>
#include "..\PhysicsStuff\pfGen.h"
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "Qt\qpushbutton.h"
#include "..\PhysicsStuff\DebugSlider.h"

struct GraphicContainer
{
	Particle systemParticle;
	VectorGraphic* ParticleGraphic;
	VectorGraphic* redVector;
	//VectorGraphic* greenVector;
	VectorGraphic* blueVector;
	glm::vec3 initialParticlePosition;
	float radiusPercentage;
};

class ChaslesTheorem : public GuiBase
{
	VectorGraphic* blackVector;
	VectorGraphic* greenVector;
	VectorGraphic* forceVector;
	GraphicContainer container[15];
public:
	ChaslesTheorem(void);
	ChaslesTheorem(QPushButton& Throw,QPushButton& reset,DebugSlider& partsRadius,DebugSlider& ThrowSpeed,DebugSlider& angularvelocity,QCheckBox& sameParts);
	ChaslesTheorem();
	void initialize();
	void newFrame();
	void resetSystem();
	void throwSystem();
	void updateLever();
	float radius;
	float angularVel;
	float totalInertia;
	float torqueMag;
	float throwSpeed;
	bool sameRadius;
	bool isThrown;
	int throwDirection;
	glm::vec3 systemOrigin;
	glm::vec3 systemVelocity;
	glm::vec3 leverPos;
	glm::vec3 leverForce;
	glm::vec3 perpForce; 

};

#endif
