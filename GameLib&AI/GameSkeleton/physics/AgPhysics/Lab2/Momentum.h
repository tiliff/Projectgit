#pragma once
#include <..\..\MiddleWare\PhysicsGui\include\PhysicsGui\GuiBase.h>
#include "..\PhysicsStuff\Particle.h"
#include "..\PhysicsStuff\DebugSlider.h"
#include <QtGui\qlabel.h>
#include <QtGui\qcheckbox.h>
class Momentum : public GuiBase
{
    VectorGraphic* graphic;
	VectorGraphic* velocityGraphic;
	VectorGraphic* momentumGraphic;
	glm::vec3 momentum;
	Particle p;
public:
	Momentum(DebugSlider &mass,QCheckBox &cons,float &value,QLabel &massLabel);
	void initialize();
	void newFrame();
	void vectorGraphicMouseDrag(glm::uint vectorGraphicIndex,const glm::vec3& dragDelta);
	glm::vec3 getUserDirection();
};
