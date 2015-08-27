#include "ChaslesTheoremWidge.h"
#include <sstream>

std::string ConvertSs(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
ChaslesWidge::ChaslesWidge()
{
	QVBoxLayout* mainLayy2=new QVBoxLayout();
	setLayout(mainLayy2);
	QHBoxLayout* row1= new QHBoxLayout();

	QPushButton* Throws= new QPushButton("Throw");
	row1->addWidget(Throws);

	QPushButton* Resets= new QPushButton("Reset");
	row1->addWidget(Resets);
	mainLayy2->addLayout(row1);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* radius= new DebugSlider(0.1f,6.0f);
	row2->addWidget(radius);
	mainLayy2->addLayout(row2);
	radius->setValue(4.0f);
	QLabel* radiusLabel = new QLabel("Radius");
	row2->addWidget(radiusLabel);

	QHBoxLayout* row3= new QHBoxLayout();
	DebugSlider* ThrowSpeed= new DebugSlider(0.1f,10.0f);
	row3->addWidget(ThrowSpeed);
	mainLayy2->addLayout(row3);
	ThrowSpeed->setValue(5.0f);
	QLabel* TSLabel = new QLabel("Throw Speed");
	row3->addWidget(TSLabel);

	QHBoxLayout* row4= new QHBoxLayout();
	DebugSlider* AngularVelocity= new DebugSlider(0.1f,10.0f);
	row4->addWidget(ThrowSpeed);
	mainLayy2->addLayout(row4);
	ThrowSpeed->setValue(1.5f);
	QLabel* TSLabel2 = new QLabel("Angular Velocity");
	row4->addWidget(TSLabel2);

	mainLayy2->addLayout(row4);

	QHBoxLayout* row5= new QHBoxLayout();
	QCheckBox* radi2= new QCheckBox("Particles radius are the the same.");
	row5->addWidget(radi2);
	mainLayy2->addLayout(row5);


	ChaslesTheorem *CTlab= new ChaslesTheorem(*Throws,*Resets,*radius,*ThrowSpeed,*AngularVelocity,*rad);
	CTlab->initialize();
	mainLayy2->addWidget(CTlab);
}



