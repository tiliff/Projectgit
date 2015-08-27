#include "FaccumWidge.h"


FaccumWidge::FaccumWidge(void)
{
	QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	QPushButton* reset= new QPushButton("Reset");
	row1->addWidget(reset);
	mainLa->addLayout(row1);

	Forces* Forcelab=new Forces(*reset);
	Forcelab->initialize();
	mainLa->addWidget(Forcelab);
}

