#pragma once
#include <GL\glew.h>
#include <QtOpenGL\qglwidget>
#include <Qt\qtimer.h>
#include <DebugSlider.h>
#include <Qt\qcheckbox.h>

class MyGLWindow : public QGLWidget
{
	Q_OBJECT 
	QTimer mytimer;
	GLuint programID;
	GLuint bufferID;
	GLuint indexBufferID;
    uint torusOffset;
	uint cubeOffset;
	uint planeOffset;
public:
	MyGLWindow(DebugSlider &sARed,DebugSlider &sAGreen,DebugSlider &sABlue,
			DebugSlider &sDRed,DebugSlider &sDGreen,DebugSlider &sDBlue,
			DebugSlider &sSRed,DebugSlider &sSGreen,DebugSlider &sSBlue,
			DebugSlider &Sx,DebugSlider &Sy,DebugSlider &Sz,DebugSlider &SP,QCheckBox &Lit,
			DebugSlider &rX,DebugSlider &rY,DebugSlider &rZ,DebugSlider &lX,DebugSlider &lY,DebugSlider &lZ);
	MyGLWindow();

protected:
	void initializeGL();
	void paintGL();
	void sendDataToHardware();
	void CompileShaders();
	void CreateTexture(const char* name,int textureID,int ProgramId,GLuint* data,char* parameterName);
private slots:
	void myUpdate();
	DebugSlider*ARed;
	DebugSlider*AGreen;
	DebugSlider*ABlue;
	DebugSlider*DRed;
	DebugSlider*DGreen;
	DebugSlider*DBlue;
	DebugSlider*SRed;
	DebugSlider*SGreen;
	DebugSlider*SBlue;
	DebugSlider*SLx;
	DebugSlider*SLy;
	DebugSlider*SLz;
	DebugSlider*SLpow;
	DebugSlider*SLRx;
	DebugSlider*SLRy;
	DebugSlider*SLRz;
	DebugSlider*SLLx;
	DebugSlider*SLLy;
	DebugSlider*SLLz;
};

