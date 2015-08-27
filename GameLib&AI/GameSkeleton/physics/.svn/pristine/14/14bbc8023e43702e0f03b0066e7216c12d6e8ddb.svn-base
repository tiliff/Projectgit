#include "AngularVelocityWidge.h"
#include <sstream>

std::string ConvertS(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
AngularWidge::AngularWidge()
{
	QVBoxLayout* mainLayy=new QVBoxLayout();
	setLayout(mainLayy);
	QHBoxLayout* row1= new QHBoxLayout();

	QPushButton* Throw= new QPushButton("Throw");
	row1->addWidget(Throw);

	QPushButton* Reset= new QPushButton("Reset");
	row1->addWidget(Reset);
	mainLayy->addLayout(row1);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* radius= new DebugSlider(0.1f,5.0f);
	row2->addWidget(radius);
	mainLayy->addLayout(row2);
	radius->setValue(4.0f);
	QLabel* radiusLabel = new QLabel("Radius");
	row2->addWidget(radiusLabel);

	QHBoxLayout* row3= new QHBoxLayout();
	DebugSlider* AngularVel= new DebugSlider(0.0f,10.0f);
	row3->addWidget(AngularVel);
	mainLayy->addLayout(row3);
	AngularVel->setValue(0.5f);
	QLabel* AvelLabel = new QLabel("AngularVelocity");
	row3->addWidget(AvelLabel);


	AngularVelocityLab *avellab= new AngularVelocityLab(*Throw,*Reset,*radius,*AngularVel);
	avellab->initialize();
	mainLayy->addWidget(avellab);
}



