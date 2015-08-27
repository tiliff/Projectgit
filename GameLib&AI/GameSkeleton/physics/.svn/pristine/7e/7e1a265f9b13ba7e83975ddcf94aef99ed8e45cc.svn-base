#pragma once
#include "..\PhysicsGui\include\PhysicsGui\GuiBase.h"
#include "..\PhysicsGui\include\PhysicsGui\VectorGraphic.h"
#include "..\PhysicsStuff\Particle.h"
#include "..\PhysicsStuff\ParticleDrag.h"
#include "..\PhysicsStuff\ParticleForceRegistry.h"
#include "..\PhysicsStuff\DebugSlider.h"


class DragForces : public GuiBase
{
    VectorGraphic* graphic;
	ParticleForceRegistry pf;
	ParticleDrag dragForce;
	Particle p;
public:
	DragForces(DebugSlider &Low,DebugSlider &High);
	void initialize();
	void newFrame();
	
	
};

