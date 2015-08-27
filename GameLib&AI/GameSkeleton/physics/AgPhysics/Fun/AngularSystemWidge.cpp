#include "AngularSystemWidge.h"
#include <sstream>

AngularSystemWidge::AngularSystemWidge()
{
	QVBoxLayout* mainLayy=new QVBoxLayout();
	setLayout(mainLayy);

	QHBoxLayout* row1= new QHBoxLayout();
	DebugSlider* CenterMass= new DebugSlider(0.1f,5.0f);
	row1->addWidget(CenterMass);
	mainLayy->addLayout(row1);
	CenterMass->setValue(2.0f);
	QLabel* CenterMassLabel = new QLabel("Center Mass");
	row1->addWidget(CenterMassLabel);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* p1Mass= new DebugSlider(0.1f,5.0f);
	row2->addWidget(p1Mass);
	mainLayy->addLayout(row2);
	p1Mass->setValue(1.0f);
	QLabel* P1Label = new QLabel("Planet 1 Mass");
	row2->addWidget(P1Label);

	QHBoxLayout* row3= new QHBoxLayout();
	DebugSlider* P2Mass= new DebugSlider(0.1f,5.0f);
	row3->addWidget(P2Mass);
	mainLayy->addLayout(row3);
	P2Mass->setValue(2.5f);
	QLabel* P2Label = new QLabel("Planet 2 Mass");
	row3->addWidget(P2Label);

	QHBoxLayout* row5= new QHBoxLayout();
	DebugSlider* MoonMass= new DebugSlider(0.1f,5.0f);
	row5->addWidget(MoonMass);
	mainLayy->addLayout(row5);
	MoonMass->setValue(0.1f);
	QLabel* MMLabel = new QLabel("Moon Mass");
	row5->addWidget(MMLabel);

	QHBoxLayout* row4= new QHBoxLayout();
	DebugSlider* AngularVel= new DebugSlider(0.0f,10.0f);
	row4->addWidget(AngularVel);
	mainLayy->addLayout(row4);
	AngularVel->setValue(0.5f);
	QLabel* AvelLabel = new QLabel("AngularVelocity");
	row4->addWidget(AvelLabel);

	QHBoxLayout* row7= new QHBoxLayout();
	QPushButton* Throw= new QPushButton("Throw");
	row7->addWidget(Throw);

	QPushButton* Reset= new QPushButton("Reset");
	row7->addWidget(Reset);
	mainLayy->addLayout(row7);


	AngularSystem *angsyst= new AngularSystem(*CenterMass,*p1Mass,*MoonMass,*P2Mass,*AngularVel,*Throw,*Reset);
	angsyst->initialize();
	mainLayy->addWidget(angsyst);
}



