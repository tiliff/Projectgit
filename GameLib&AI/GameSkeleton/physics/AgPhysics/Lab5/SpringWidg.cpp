#include "..\Lab5\SpringWidg.h"


SpringWidg::SpringWidg()
{
    QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	DebugSlider* Springconst= new DebugSlider(0.0f,100.0f);
	row1->addWidget(Springconst);
	mainLa->addLayout(row1);
	Springconst->setValue(0.5f);
	QLabel* ScLabel = new QLabel("Spring Constant");
	row1->addWidget(ScLabel);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* RestLength= new DebugSlider(0.0f,5.0f);
	row2->addWidget(RestLength);
	mainLa->addLayout(row2);
	RestLength->setValue(4.0f);
	QLabel* RLabel = new QLabel("Rest Length");
	row2->addWidget(RLabel);

	SpringForces *springlab=new SpringForces(*Springconst,*RestLength);
	springlab->initialize();
	mainLa->addWidget(springlab);
}



