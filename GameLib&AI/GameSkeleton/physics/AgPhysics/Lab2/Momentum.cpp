#include <sstream>
#include "Momentum.h"
#ifndef DebugSlider_h
#define DebugSlider_h
#include <Qt\qdebug.h>
#include "Windows.h"
#endif

DebugSlider* slider;
QCheckBox* theBox;
QLabel* theLabel;
float* MomentVal;

std::string ConvertString(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}

Momentum::Momentum(DebugSlider &mass,QCheckBox &cons,float &value,QLabel &massLabel)
{
	slider=&mass;
	theBox=&cons;
	theLabel=&massLabel;
	MomentVal=&value;
}
void Momentum::initialize()
{
	GuiBase::initialize(false, true);
	graphic = addVectorGraphic();
	velocityGraphic = addVectorGraphic();
	momentumGraphic=addVectorGraphic();
	velocityGraphic->displayStyle =DS_ARROW;
	momentumGraphic->displayStyle =DS_ARROW;
	velocityGraphic->b=255;
	momentumGraphic->r=255;
	graphic->position=p.Position;
	graphic->g=255;
	graphic->b=255;
	//p.Damper=0.99f;

}

void Momentum::newFrame()
{
	p.calculateMoment();
	*MomentVal=glm::length(p.Momentum);
	theLabel->setText(ConvertString(*MomentVal).c_str());
	p.mass= slider->value();
	graphic->pointSize=p.mass;

	if(theBox->isChecked())
	{
		p.Velocity=p.Momentum/p.mass;
	}

	float accelerationScaler = 1.00f;
	p.Acceleration=(accelerationScaler * getUserDirection());
	p.Velocity += p.Acceleration *dt();
	/*p.Velocity=p.Velocity*p.Damper;*/
	p.Position+=p.Velocity *dt();
	sync(graphic,p.Position);
	sync(velocityGraphic,p.Velocity,p.Position);
	sync(momentumGraphic,p.Momentum,p.Position);
}
void Momentum::vectorGraphicMouseDrag(uint vectorGraphicIndex,const glm::vec3& dragDelta)
{
	p.Position+= dragDelta;
}
glm::vec3 Momentum::getUserDirection()
{
	glm::vec3 ret;
	if(GetAsyncKeyState('W'))
	{
		ret=glm::vec3(0.0f,1.0f,0.0f);
	}
	if(GetAsyncKeyState('A'))
	{
		ret=glm::vec3(-1.0f,0.0f,0.0f);
	}
	if(GetAsyncKeyState('S'))
	{
		ret=glm::vec3(0.0f,-1.0f,0.0f);
	}
	if(GetAsyncKeyState('D'))
	{
		ret=glm::vec3(1.0f,0.0f,0.0f);
	}
	return ret;
}
