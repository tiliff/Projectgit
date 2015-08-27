#pragma once
#include "PhysicsGui\GuiBase.h"
#include "..\PhysicsStuff\Particle.h"

class MeParticleDemo : public GuiBase
{
	VectorGraphic* graphic;
	VectorGraphic* velocityGraphic;
	Particle p;
public:
	MeParticleDemo()
	{
		initialize();
	}
	void initialize();
	void newFrame();
	void vectorGraphicMouseDrag(glm::uint vectorGraphicIndex,const glm::vec3& dragDelta);
	glm::vec3 getUserDirection();
};
