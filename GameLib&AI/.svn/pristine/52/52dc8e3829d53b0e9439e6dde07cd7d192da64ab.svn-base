#include "DebugMenu.h"


MyDebugMenu MyDebugMenu::theInstance;


void MyDebugMenu::initialize(QVBoxLayout* layout)
{
		theInstance.meLayout=layout;
		FloatLayout=new QVBoxLayout();
		SliderLayout=new QVBoxLayout();
		BoolLayout=new QVBoxLayout();

		layout->addLayout(FloatLayout);
		layout->addLayout(SliderLayout);
		layout->addLayout(BoolLayout);

		
}

void MyDebugMenu::watch(const char* label,float& theFloat)
{
	FloatWatcher temp;
	temp.initialize(label,theFloat);
	watching.push_back(temp);
	numWatches++;

	QHBoxLayout* lay=new QHBoxLayout();
	lay->addWidget(temp.theLabel);
	lay->addWidget(temp.floatText);
	FloatLayout->addLayout(lay);
}

void MyDebugMenu::watchSlider(float& theFloat,float min,float max,const char* name)
{
	SliderWatcher temp;
	temp.initialize(theFloat,min,max,name);
	watchedSl.push_back(temp);
	numWatchedSliders++;

	QHBoxLayout* lay=new QHBoxLayout();
	lay->addWidget(temp.theLabel);
	lay->addWidget(temp.theSlider);
	FloatLayout->addLayout(lay);
}

void MyDebugMenu::watchCheckBox(const bool* thebool,QString Name)
{
	BoolWatcher temp;
	temp.initialize(thebool, Name);
	watchedBool.push_back(temp);
	numWatchedCheck++;

	QHBoxLayout* lay=new QHBoxLayout();
	lay->addWidget(temp.name);
	lay->addWidget(temp.theCheckBox);
	FloatLayout->addLayout(lay);
}

void MyDebugMenu::Update()
{
	for(int i =0;i<numWatches;i++)
	{
		watching[i].update();
	}
	for(int j =0;j<numWatchedSliders;j++)
	{
		watchedSl[j].update();
	}
	for(int k =0;k<numWatchedCheck;k++)
	{
		watchedBool[k].update();
	}
}