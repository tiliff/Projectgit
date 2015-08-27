#include "soloCollisionWidg.h"

std::string ConvertStringss(float f)
{
	std::stringstream s;
	s<<f;
	return s.str();
}
soloCollisionWidg::soloCollisionWidg()
{
	QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	DebugSlider* Mass1= new DebugSlider(0.0f,5.0f,false,100.0f);
	row1->addWidget(Mass1);
	mainLa->addLayout(row1);
	Mass1->setValue(0.5f);
	QLabel* ScLabel = new QLabel("Green's Mass");
	row1->addWidget(ScLabel);

	QHBoxLayout* row2= new QHBoxLayout();
	DebugSlider* Mass2= new DebugSlider(0.0f,5.0f,false,100.0f);
	row2->addWidget(Mass2);
	mainLa->addLayout(row2);
	Mass2->setValue(0.3f);
	QLabel* RLabel = new QLabel("Purple's Mass");
	row2->addWidget(RLabel);

	QHBoxLayout* row3= new QHBoxLayout();
	DebugSlider* Restitution= new DebugSlider(0.0f,1.0f,false,100.0f);
	row3->addWidget(Restitution);
	mainLa->addLayout(row3);
	Restitution->setValue(1.0f);
	QLabel* draglab = new QLabel("Restitution");
	row3->addWidget(draglab);

	QHBoxLayout* row4= new QHBoxLayout();
	DebugSlider* particle1Velocity= new DebugSlider(0.0f,10.0f);
	row4->addWidget(particle1Velocity);
	mainLa->addLayout(row4);
	particle1Velocity->setValue(2.0f);
	QLabel* vellab = new QLabel("Green's Velocity");
	row4->addWidget(vellab);

	QHBoxLayout* row5= new QHBoxLayout();
	DebugSlider* particle1Velocity2= new DebugSlider(-10.0f,0.0f);
	row5->addWidget(particle1Velocity2);
	mainLa->addLayout(row5);
	particle1Velocity2->setValue(-3.0f);
	QLabel* vellab2 = new QLabel("Purple's velocity");
	row5->addWidget(vellab2);

	QHBoxLayout* row6= new QHBoxLayout();
	QPushButton* reset= new QPushButton("Reset");
	row6->addWidget(reset);
	mainLa->addLayout(row6);

	float* GreensxVel=new float;
	*GreensxVel=0.0f;
	QLabel* Green = new QLabel("Green X Velocity");
	row6->addWidget(Green);
	QLabel* Gvel = new QLabel(ConvertStringss(*GreensxVel).c_str());
	row6->addWidget(Gvel);
	



	float* purplesxvel=new float;
	*purplesxvel=0.0f;
	QLabel* Purp = new QLabel("Purple X Velocity");
	row6->addWidget(Purp);
	QLabel* pvel = new QLabel(ConvertStringss(*purplesxvel).c_str());
	row6->addWidget(pvel);
	



	float* TotalMomentum=new float;
	*TotalMomentum=0.0f;
	QLabel* TOT = new QLabel("Total Momentum");
	row6->addWidget(TOT);
	QLabel* totalmomentum = new QLabel(ConvertStringss(*TotalMomentum).c_str());
	row6->addWidget(totalmomentum);
	


	float* totalKineticEnergy=new float;
	*totalKineticEnergy=0.0f;
	QLabel* Totk = new QLabel("Total Kinetic Energy");
	row6->addWidget(Totk);
	QLabel* TKE = new QLabel(ConvertStringss(*totalKineticEnergy).c_str());
	row6->addWidget(TKE);
	

	

	CollisionSolo* collisionlab=new CollisionSolo(*Mass1,*Mass2,*Restitution,*particle1Velocity,*particle1Velocity2,*reset,*Gvel,*pvel,*totalmomentum,*TKE);
	collisionlab->initialize();
	mainLa->addWidget(collisionlab);
}


