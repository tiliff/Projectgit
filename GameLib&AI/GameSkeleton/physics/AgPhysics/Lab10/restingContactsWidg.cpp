#include "restingContactsWidg.h"

restingContacts::restingContacts()
{
	QVBoxLayout* mainLa=new QVBoxLayout();
	setLayout(mainLa);
	QHBoxLayout* row1= new QHBoxLayout();

	QHBoxLayout* row2= new QHBoxLayout();
	QPushButton* reset= new QPushButton("Reset");
	row2->addWidget(reset);
	mainLa->addLayout(row2);

	RestingContactsLab* Contactslab=new RestingContactsLab(*reset);
	Contactslab->initialize();
	mainLa->addWidget(Contactslab);
}

