#include <SliderWidget.h>
#include <Qt\qcheckbox.h>

SliderWidget::SliderWidget()
	{
		DebugSlider *ared = new DebugSlider(0,1);
		DebugSlider *agreen = new DebugSlider(0,1);
		DebugSlider *ablue = new DebugSlider(0,1);

		DebugSlider *dred = new DebugSlider(0,1);
		DebugSlider *dgreen = new DebugSlider(0,1);
		DebugSlider *dblue = new DebugSlider(0,1);
		 
		DebugSlider *sred = new DebugSlider(0,1);
		DebugSlider *sgreen = new DebugSlider(0,1);
		DebugSlider *sblue = new DebugSlider(0,1);

		DebugSlider *sX = new DebugSlider(0,1);
		DebugSlider *sY = new DebugSlider(0,1);
		DebugSlider *sZ = new DebugSlider(0,1);

		DebugSlider *rX = new DebugSlider(-180,180);
		DebugSlider *rY = new DebugSlider(-180,180);
		DebugSlider *rZ = new DebugSlider(-180,180);

		DebugSlider *lX = new DebugSlider(-10,10);
		DebugSlider *lY = new DebugSlider(-10,10);
		DebugSlider *lZ = new DebugSlider(-10,10);

		DebugSlider *sPower = new DebugSlider(50.0f,200.0f);

		QCheckBox *isLit = new QCheckBox("Lighting On");
		
		ared->setFixedHeight(50);
		agreen->setFixedHeight(50);
		ablue->setFixedHeight(50);

		dred->setFixedHeight(50);
		dgreen->setFixedHeight(50);
		dblue->setFixedHeight(50);

		sred->setFixedHeight(50);
		sgreen->setFixedHeight(50);
		sblue->setFixedHeight(50);

		sX->setFixedHeight(50);
		sY->setFixedHeight(50);
		sZ->setFixedHeight(50);

		rX->setFixedHeight(50);
		rY->setFixedHeight(50);
		rZ->setFixedHeight(50);

		lX->setFixedHeight(50);
		lY->setFixedHeight(50);
		lZ->setFixedHeight(50);

		sPower->setFixedHeight(50);

		ared->setValue(0.2f);
		agreen->setValue(0.2f);
		ablue->setValue(0.2f);

		dred->setValue(1.0f);
		dgreen->setValue(1.0f);
		dblue->setValue(1.0f);

		sred->setValue(0.50f);
		sgreen->setValue(0.50f);
		sblue->setValue(0.50f);

	    sX->setValue(0.0f);
		sY->setValue(0.0f);
		sZ->setValue(0.0f);

		sPower->setValue(50.0f);

		rX->setValue(0.0f);
		rY->setValue(0.0f);
		rZ->setValue(0.0f);

		lX->setValue(0.0f);
		lY->setValue(0.0f);
		lZ->setValue(0.0f);


		QVBoxLayout *mainLayout = new QVBoxLayout();
		setLayout(mainLayout);
		QLabel* ambient = new QLabel("Ambient");
		QLabel* defuse = new QLabel("Diffuse Color");
		QLabel* shape = new QLabel("Shape Color");
		QLabel* specular = new QLabel("Specular Color");
		QLabel* specPow = new QLabel("Specular Power");
		QLabel* Rotation = new QLabel("Rotation");
		QLabel* LightPos = new QLabel("Light Position");
		const char* ShapeX =("Shape X");
		const char* ShapeY =("Shape Y");
		const char* ShapeZ =("Shape Z");
		float ShapeXF =0.0f;
		float ShapeYF =0.0f;
		float ShapeZF =0.0f;
		




		QHBoxLayout *row = new  QHBoxLayout();
		mainLayout -> addLayout(row);
		row -> addWidget(ambient);
		row -> addWidget(ared);
		row -> addWidget(agreen);
		row -> addWidget(ablue);

		QHBoxLayout *row2 = new QHBoxLayout();
		mainLayout -> addLayout(row2);
		row2 -> addWidget(defuse);
		row2 -> addWidget(dred);
		row2 -> addWidget(dgreen);
		row2 -> addWidget(dblue);

		QHBoxLayout *row3 = new QHBoxLayout();
		mainLayout -> addLayout(row3);
		row3 -> addWidget(shape);
		row3 -> addWidget(sred);
		row3 -> addWidget(sgreen);
		row3 -> addWidget(sblue);

		QHBoxLayout *row4 = new QHBoxLayout();
		mainLayout -> addLayout(row4);
		row4 -> addWidget(specular);
		row4 -> addWidget(sX);
		row4 -> addWidget(sY);
		row4 -> addWidget(sZ);

		QHBoxLayout *row7 = new  QHBoxLayout();
		mainLayout -> addLayout(row7);
		row7 -> addWidget(Rotation);
		row7 -> addWidget(rX);
		row7 -> addWidget(rY);
		row7 -> addWidget(rZ);

		/*QHBoxLayout *row8 = new  QHBoxLayout();
		mainLayout -> addLayout(row8);
		row8 -> addWidget(LightPos);
		row8 -> addWidget(lX);
		row8 -> addWidget(lY);
		row8 -> addWidget(lZ);*/

		QHBoxLayout *row5 = new QHBoxLayout();
		mainLayout -> addLayout(row5);
		row5 -> addWidget(specPow);
		row5 -> addWidget(sPower);

		QHBoxLayout *row6 = new QHBoxLayout();
		mainLayout -> addLayout(row6);
		row6 -> addWidget(isLit);

		

		

		mainLayout -> addWidget(new MyGLWindow(*ared, *agreen, *ablue,*dred, *dgreen, *dblue, *sred, *sgreen, *sblue,*sX,*sY,*sZ,*sPower,*isLit,*rX,*rY,*rZ,*lX,*lY,*lZ));
}