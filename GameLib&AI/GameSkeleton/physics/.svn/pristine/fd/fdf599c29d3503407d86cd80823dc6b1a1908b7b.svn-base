#include "MyWidge.h"
#include <sstream>

std::string ConvertStrings(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
MyWidge::MyWidge()
{
	QVBoxLayout* mainLay=new QVBoxLayout();
	setLayout(mainLay);
	QHBoxLayout* row1= new QHBoxLayout();

	DebugSlider* mass= new DebugSlider(0.5,5.0f);
	row1->addWidget(mass);
	mainLay->addLayout(row1);
	mass->setValue(0.5f);
	QLabel* massLabel = new QLabel("Mass");
	row1->addWidget(massLabel);

	float* values=new float;
	*values=0.0f;
	QLabel* momentum = new QLabel(ConvertStrings(*values).c_str());
	QHBoxLayout* row2= new QHBoxLayout();
	mainLay->addLayout(row2);
	row2->addWidget(momentum);

	QHBoxLayout* row3= new QHBoxLayout();
	QCheckBox* cons= new QCheckBox("Conserve Momentum");
	mainLay->addLayout(row3);
	row3->addWidget(cons);

	Momentum *moment= new Momentum(*mass,*cons,*values,*momentum);
	moment->initialize();
	mainLay->addWidget(moment);
}



