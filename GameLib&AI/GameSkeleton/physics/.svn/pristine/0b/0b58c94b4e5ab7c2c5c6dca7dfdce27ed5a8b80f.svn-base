#pragma once
#include "..\PhysicsGui\include\PhysicsGui\GuiBase.h"
#include "..\PhysicsGui\include\PhysicsGui\VectorGraphic.h"
#include "..\PhysicsStuff\Particle.h"
#include "..\PhysicsStuff\ParticleSpring.h"
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "..\PhysicsStuff\DebugSlider.h"


class SpringForces : public GuiBase
{
    VectorGraphic* graphic;
	VectorGraphic* graphic2;
	ParticleForceRegistry pf;
	ParticleSpring ps;
	Particle p;
	Particle p2;
public:
	SpringForces(DebugSlider &SpringConst,DebugSlider &RestLength);
	void initialize();
	void newFrame();
	void vectorGraphicMouseDrag(uint vectorGraphicIndex,const glm::vec3& dragDelta);
	
};

