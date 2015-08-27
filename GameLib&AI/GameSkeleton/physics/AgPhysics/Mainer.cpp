#include "PhysicsGui\GuiBase.h"
#include "QtGui\qapplication.h"
#include "Lab1\MeParticleDemo.h"
#include "Lab2\MyWidge.h"
#include "Lab3\FaccumWidge.h"
#include "Lab4\DragWidg.h"
#include "Lab5\SpringWidg.h"
#include "Lab6\MultiSpringWidg.h"
#include "Lab7\soloCollisionWidg.h"
#include "Lab9\restingContactWidg.h"
#include "Lab10\restingContactsWidg.h"
#include "Lab12\AngularVelocityWidge.h"
#include "Fun\AngularSystemWidge.h"

int main(int argc, char * argv[])
{
	QApplication app(argc,argv);
	//MeParticleDemo demo;
	//demo.show();
	//MyWidge Lab2;
	//Lab2.show();
	/*FaccumWidge Lab3;
	Lab3.show();*/
	/*DragWidg lab4;
	lab4.show();*/
	//SpringWidg Lab5;
	//Lab5.show();
	//MultiSpringWidg Lab6;
	//Lab6.show();
	//soloCollisionWidg lab7;
	//lab7.show();
	restingContact lab9;
	lab9.show();
	//restingContacts Lab10;
	//Lab10.show();
	/*AngularWidge Lab12;
	Lab12.show();*/
	//AngularSystemWidge Funness;
	//Funness.showMaximized();
	return app.exec();
}