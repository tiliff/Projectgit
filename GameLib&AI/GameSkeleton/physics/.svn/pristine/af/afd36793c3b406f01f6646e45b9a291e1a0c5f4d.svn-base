#include "restingContactWidg.h"

std::string Convert(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
restingContact::restingContact()
{
	QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	float* INCBV=new float;
	*INCBV=0.0f;
	QLabel* IBVlab = new QLabel("Incoming Bounce Velocity");
	row1->addWidget(IBVlab);
	QLabel* IBV = new QLabel(Convert(*INCBV).c_str());
	row1->addWidget(IBV);
	mainLa->addLayout(row1);

	QHBoxLayout* row2= new QHBoxLayout();
	float* OutBV=new float;
	*OutBV=0.0f;
	QLabel* OBVLAB = new QLabel("Outgoing Bounce Velocity");
	row2->addWidget(OBVLAB);
	QLabel* OBV = new QLabel(Convert(*INCBV).c_str());
	row2->addWidget(OBV);
	mainLa->addLayout(row2);

	QHBoxLayout* row3= new QHBoxLayout();
	DebugSlider* Restitutions= new DebugSlider(0.0f,1.0f,100.0f);
	row3->addWidget(Restitutions);
	mainLa->addLayout(row3);
	Restitutions->setValue(0.9f);
	QLabel* ScLabel = new QLabel("Restitution");
	row3->addWidget(ScLabel);

	QHBoxLayout* row4= new QHBoxLayout();
	QPushButton* resetTF= new QPushButton("Reset to Fall");
	row4->addWidget(resetTF);
	mainLa->addLayout(row4);

	QHBoxLayout* row5= new QHBoxLayout();
	QPushButton* resetTR= new QPushButton("Reset to Rest");
	row5->addWidget(resetTR);
	mainLa->addLayout(row5);

	RestingContactLab* Contactlab=new RestingContactLab(*IBV,*OBV,*Restitutions,*resetTF,*resetTR);
	Contactlab->initialize();
	mainLa->addWidget(Contactlab);
}

