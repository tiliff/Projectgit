#include "DragWidg.h"


DragWidg::DragWidg(void)
{
	QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	DebugSlider* k1= new DebugSlider(0.0f,5.0f);
	row1->addWidget(k1);
	mainLa->addLayout(row1);
	k1->setValue(0.5f);
	QLabel* k1Label = new QLabel("Low Speed");
	row1->addWidget(k1Label);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* k2= new DebugSlider(0.0f,5.0f);
	row2->addWidget(k2);
	mainLa->addLayout(row2);
	k2->setValue(0.5f);
	QLabel* k2Label = new QLabel("High Speed");
	row2->addWidget(k2Label);

	DragForces *forcelab=new DragForces(*k1,*k2);
	forcelab->initialize();
	mainLa->addWidget(forcelab);
}



