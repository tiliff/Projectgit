#include "..\Lab6\MultiSpringWidg.h"


MultiSpringWidg::MultiSpringWidg(void)
{

    QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	DebugSlider* Springconstm= new DebugSlider(0.0f,100.0f);
	row1->addWidget(Springconstm);
	mainLa->addLayout(row1);
	Springconstm->setValue(50.0f);
	QLabel* ScLabel = new QLabel("Spring Constant");
	row1->addWidget(ScLabel);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* RestLengthm= new DebugSlider(0.0f,5.0f);
	row2->addWidget(RestLengthm);
	mainLa->addLayout(row2);
	RestLengthm->setValue(1.0f);
	QLabel* RLabel = new QLabel("Rest Length");
	row2->addWidget(RLabel);

	QHBoxLayout* row3= new QHBoxLayout();
	DebugSlider* Dragslide= new DebugSlider(0.9f,1.0f);
	row2->addWidget(Dragslide);
	mainLa->addLayout(row3);
	Dragslide->setValue(0.98f);
	QLabel* draglab = new QLabel("Drag");
	row2->addWidget(draglab);

	QHBoxLayout* row4= new QHBoxLayout();
	QCheckBox* gravity= new QCheckBox("Gravity");
	row4->addWidget(gravity);
	mainLa->addLayout(row4);

	MultiSpringForces *springlab=new MultiSpringForces(*Springconstm,*RestLengthm,*Dragslide,*gravity);
	springlab->initialize();
	mainLa->addWidget(springlab);

}


