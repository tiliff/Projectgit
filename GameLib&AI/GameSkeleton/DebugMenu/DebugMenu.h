#pragma once
#include <QtGui\QVBoxLayout>
#include <QtGui\qlabel.h>
#include <..\..\NeumontTools\include\Slider.h>
#include <QtGui\qcheckbox.h>
#include <sstream>
#include "DebugSlider.h"

class MyDebugMenu
{
	QVBoxLayout* meLayout;
	QVBoxLayout* FloatLayout;
	QVBoxLayout* SliderLayout;
	QVBoxLayout* BoolLayout;
	static MyDebugMenu theInstance;
	MyDebugMenu(){}
	MyDebugMenu(const MyDebugMenu&);
	MyDebugMenu& operator=(MyDebugMenu&);
	int numWatches;
	int numWatchedSliders;
	int numWatchedCheck;

	struct FloatWatcher
	{
	QLabel* theLabel;
	QLabel* floatText;
	float* datFloat;
	public :
		void initialize(const char* label,float& theFloat)
		{
			std::stringstream s;
			this->theLabel->setText(label);
			s << theFloat;
			const char* str=s.str().c_str();
			this->floatText->setText(str);
			datFloat=&theFloat;
		}
		void update()
		{
			std::stringstream s;
			s<<datFloat;
			const char* str=s.str().c_str();
			this->floatText->setText(str);
		}
		
	};
	QList<FloatWatcher> watching;

	struct SliderWatcher
	{
	QLabel* theLabel;
    float* Float;
	DebugSlider* theSlider;

	void initialize(float& theFloat,float min,float max,const char* Name)
		{
			theLabel=new QLabel();
			*Float = theFloat;
			theLabel->setText(Name);
			theSlider=new DebugSlider(min,max,true,20.0f);
			theSlider->setValue(*Float);
		}
		void update()
		{
			*Float = theSlider->value();
		}
	};
	QList<SliderWatcher> watchedSl;

	struct BoolWatcher
	{
    bool* theBool;
	QCheckBox* theCheckBox;
	QLabel* name;
	void initialize(const bool* thebool,QString Name)
		{
			name=new QLabel(Name);
			*theBool=thebool;
			theCheckBox=new QCheckBox();
			theCheckBox->setChecked(*thebool);
		}
	void update()
	{
		*theBool = theCheckBox->isChecked();
	}
	};
	QList<BoolWatcher> watchedBool;

public:
	static MyDebugMenu& getInstance(){return theInstance;}
	void initialize(QVBoxLayout* layout);
	void watch(const char* label,float& theFloat);
	void watchSlider(float& theFloat,float min,float max,const char* name);
	void watchCheckBox(const bool* thebool,QString Name);
	void Update();
};
#define debugMenu MyDebugMenu::getInstance();
