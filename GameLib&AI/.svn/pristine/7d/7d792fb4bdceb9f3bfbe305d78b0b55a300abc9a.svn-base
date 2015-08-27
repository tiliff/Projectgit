#include <MyGLWindow.h>
#include <Qt\qdebug.h>
#include <glm\glm.hpp>
#include <gtx\transform.hpp>
#include <gtc\matrix_transform.hpp>
#include <fstream>
#include <Qt\qimage.h>
#include <ShapeGenerator.h>
#include <Camera.h>
#include <Renderer.h>

static Renderer::GeometryInfo* geometries[10];
static Renderer::ShaderInfo* shaders[10];
static Renderer::RenderableInfo* renderables[20];
static Renderer::TextureInfo* textures[10];
Renderer shapes;






Neumont::ShapeData torus;
Neumont::ShapeData cube;
Neumont::ShapeData plane;
QCheckBox * lighting;
Camera cam;
float lit=0.0f;
glm::vec3 ShapeColor;
glm::vec3 ambientlight;
glm::vec3 difuseLight;
glm::vec3 lightPosition(0.0f,1.0f,-8.0f);
glm::mat3 Normal;
glm::vec3 specColor;
glm::mat4 transformCube1;
glm::mat4 transformTorus1;
glm::mat4 transformTorus2;
glm::mat4 transformShpere1;
glm::mat4 transformShpere2;
glm::mat4 transformArrow;
glm::mat4 transformPlane;
glm::mat4 transformPlane2;
glm::mat4 transformBinary;
glm::mat4 tangcubeTransform;
float Powerofspectralness;

Neumont::ShapeData makeCube()
{
	using glm::vec2;
	using glm::vec3;
	using glm::vec4;
	Neumont::Vertex stackVerts[] = 
	{
		// Top
		vec3(-1.0f, +1.0f, +1.0f), // 0
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV

		vec3(+1.0f, +1.0f, +1.0f), // 1
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		vec3(+1.0f, +1.0f, -1.0f), // 2		
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+1.0f, +0.0f), // UV

		vec3(-1.0f, +1.0f, -1.0f), // 3
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +1.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		// Front
		vec3(-1.0f, +1.0f, -1.0f), // 4
		vec4(+1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+0.0f, +1.0f), // UV

		vec3(+1.0f, +1.0f, -1.0f), // 5
		vec4(+1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		vec3(+1.0f, -1.0f, -1.0f), // 6
		vec4(+1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+1.0f, +0.0f), // UV

		vec3(-1.0f, -1.0f, -1.0f), // 7
		vec4(+1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, -1.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		// Right
		vec3(+1.0f, +1.0f, -1.0f), // 8
		vec4(0,0,-1,0), //Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+1.0f, +0.0f), // UV

		vec3(+1.0f, +1.0f, +1.0f), // 9
		vec4(0,0,-1,0), //Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		vec3(+1.0f, -1.0f, +1.0f), // 10
		vec4(0,0,-1,0), //Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV

		vec3(+1.0f, -1.0f, -1.0f), // 11
		vec4(0,0,-1,0), //Tangent
		vec3(+1.0f, +0.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		// Left
		vec3(-1.0f, +1.0f, +1.0f), // 12
		vec4(0,0,1,0), //Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+1.0f, +0.0f), // UV

		vec3(-1.0f, +1.0f, -1.0f), // 13
		vec4(0,0,1,0), //Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		vec3(-1.0f, -1.0f, -1.0f), // 14
		vec4(0,0,1,0), //Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV

		vec3(-1.0f, -1.0f, +1.0f), // 15
		vec4(0,0,1,0), //Tangent
		vec3(-1.0f, +0.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		// Back
		vec3(+1.0f, +1.0f, +1.0f), // 16
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+1.0f, +0.0f), // UV

		vec3(-1.0f, +1.0f, +1.0f), // 17
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		vec3(-1.0f, -1.0f, +1.0f), // 18
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+0.0f, +1.0f), // UV

		vec3(+1.0f, -1.0f, +1.0f), // 19
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, +0.0f, +1.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		// Bottom
		vec3(+1.0f, -1.0f, -1.0f), // 20
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+1.0f, +1.0f), // UV

		vec3(-1.0f, -1.0f, -1.0f), // 21
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+0.0f, +1.0f), // UV

		vec3(-1.0f, -1.0f, +1.0f), // 22
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+0.0f, +0.0f), // UV

		vec3(+1.0f, -1.0f, +1.0f), // 23
		vec4(1,0,0,0), //Tangent
		vec3(+0.0f, -1.0f, +0.0f), // Normal
		vec2(+1.0f, +0.0f), // UV
	};
	unsigned short stackIndices[] = {
		0, 1, 2, 0, 2, 3, // Top
		4, 5, 6, 4, 6, 7, // Front
		8, 9, 10, 8, 10, 11, // Right 
		12, 13, 14, 12, 14, 15, // Left
		16, 17, 18, 16, 18, 19, // Back
		20, 22, 21, 20, 23, 22, // Bottom
	};

	Neumont::ShapeData temp;

	temp.numVerts = sizeof(stackVerts) / sizeof(*stackVerts);
	temp.numIndices = sizeof(stackIndices) / sizeof(*stackIndices); // see above

	temp.indices = new unsigned short[temp.numIndices];
	memcpy(temp.indices, stackIndices, sizeof(stackIndices));

	temp.verts = new Neumont::Vertex[temp.numVerts];
	memcpy(temp.verts, stackVerts, sizeof(stackVerts));

	return temp;//copyToShapeData(stackVerts, ARRAY_SIZE(stackVerts), stackIndices, ARRAY_SIZE(stackIndices));
}

MyGLWindow::MyGLWindow(DebugSlider &sARed,DebugSlider &sAGreen,DebugSlider &sABlue,
			DebugSlider &sDRed,DebugSlider &sDGreen,DebugSlider &sDBlue,
			DebugSlider &sSRed,DebugSlider &sSGreen,DebugSlider &sSBlue,
			DebugSlider &Sx,DebugSlider &Sy,DebugSlider &Sz,DebugSlider &SP,QCheckBox &Lit,
			DebugSlider &rX,DebugSlider &rY,DebugSlider &rZ,DebugSlider &lX,DebugSlider &lY,DebugSlider &lZ)
{
	ARed=&sARed;
	AGreen=&sAGreen;
	ABlue=&sABlue;
	DRed=&sDRed;
	DGreen=&sDGreen;
	DBlue=&sDBlue;
	SRed=&sSRed;
	SGreen=&sSGreen;
	SBlue=&sSBlue;
	SLx=&Sx;
	SLy=&Sy;
	SLz=&Sz;
	SLpow=&SP;
	lighting=&Lit;
	SLRx=&rX;
	SLRy=&rY;
	SLRz=&rZ;
	SLLx=&lX;
	SLLy=&lY;
	SLLz=&lZ;
}
MyGLWindow::MyGLWindow()
{

}
void MyGLWindow::initializeGL()
{
	glewInit();
	glEnable(GL_DEPTH_TEST);
	shapes.initializeRenderer();
	sendDataToHardware();
	//CompileShaders();
	connect(&mytimer,SIGNAL(timeout()),this,SLOT(myUpdate()));
	cam.position=glm::vec3(0.0f,5.0f,0.0f);
	mytimer.start(0);
}
void MyGLWindow::paintGL()
{
	glViewport(0,0,width(),height());
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	glm::mat4 world=cam.getWorldToViewMatrix();
	glm::mat4 myRotationMat=glm::rotate(0.0f,glm::vec3(1,0,0));
	myRotationMat= glm::rotate(glm::mat4(1),SLRx->value(),1.0f,0.0f,0.0f)*glm::rotate(glm::mat4(1),SLRy->value(),0.0f,1.0f,0.0f)*glm::rotate(glm::mat4(1),SLRz->value(),0.0f,0.0f,1.0f);
	transformCube1=world*glm::scale(glm::translate(glm::mat4(),lightPosition),glm::vec3(0.1f,0.1f,0.1f));
	transformTorus1=glm::translate(glm::mat4(),glm::vec3(2.0f,2.0f,0.0f));
    transformTorus2=glm::translate(glm::mat4(),glm::vec3(-2.0f,2.0f,0.0f));
	transformShpere1=glm::translate(glm::mat4(),glm::vec3(2.0f,0.0f,0.0f));
	transformShpere2=glm::translate(glm::mat4(),glm::vec3(-2.0f,0.0f,0.0f));
	transformArrow=glm::translate(glm::mat4(),glm::vec3(0.0f,-2.0f,0.0f));
	transformPlane=glm::translate(glm::mat4(),glm::vec3(0.0f,-3.0f,0.0f));
	transformBinary=glm::translate(glm::mat4(),glm::vec3(0.0f,1.0f,0.0f));
	transformPlane2=glm::rotate(90.0f,glm::vec3(1,0,0))*glm::mat4(1)*glm::translate(glm::mat4(),glm::vec3(0.0f,-5.0f,0.0f));
	tangcubeTransform=world*glm::rotate(myRotationMat,1.0f,glm::vec3(1.0f,1.0f,1.0f))*glm::translate(glm::mat4(),glm::vec3(0.0f,0.0f,0.0f));
	//transformPlane2=world* transformPlane2;
	glm::mat4 projectionmatrix = glm::perspective(90.0f,((float)width()) / height(),0.1f,100.0f);
	glm::vec3 dominatingColor=glm::vec3(SRed->value(),SGreen->value(),SBlue->value());
	ambientlight=glm::vec3(ARed->value(),AGreen->value(),ABlue->value());
	difuseLight=glm::vec3(DRed->value(),DGreen->value(),DBlue->value());
	specColor=glm::vec3(SLx->value(),SLy->value(),SLz->value());
	Powerofspectralness=(SLpow->value());
	glm::vec3 camPos= cam.position;


	shapes.addRenderableUniformParameter(renderables[0],"model2WorldTransform",Renderer::PT_MAT4,&transformCube1[0][0]);
	shapes.addRenderableUniformParameter(renderables[0],"viewTransform",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	glBindVertexArray(geometries[0]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[0]->texture->TextureID);
	glDrawElements(geometries[0]->indexingMode,geometries[0]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[0]->geometryoffset);
	
	shapes.addRenderableUniformParameter(renderables[1],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[1],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[1],"transform",Renderer::PT_MAT4,&transformTorus1[0][0]);
	shapes.addRenderableUniformParameter(renderables[1],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[1],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[1],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[1],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[1],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[1],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[1],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[1],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[1],"lighting",Renderer::PT_FLOAT,&lit);
    glBindVertexArray(geometries[1]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[1]->texture->TextureID);
	//glDrawElements(geometries[1]->indexingMode,geometries[1]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[1]->geometryoffset);

	shapes.addRenderableUniformParameter(renderables[2],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[2],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[2],"transform",Renderer::PT_MAT4,&transformTorus2[0][0]);
	shapes.addRenderableUniformParameter(renderables[2],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[2],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[2],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[2],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[2],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[2],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[2],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[2],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[2],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[1]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[2]->texture->TextureID);
	//glDrawElements(geometries[1]->indexingMode,geometries[1]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[1]->geometryoffset);

	shapes.addRenderableUniformParameter(renderables[3],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[3],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[3],"transform",Renderer::PT_MAT4,&transformShpere1[0][0]);
	shapes.addRenderableUniformParameter(renderables[3],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[3],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[3],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[3],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[3],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[3],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[3],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[3],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[3],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[2]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[3]->texture->TextureID);
	//glDrawElements(geometries[2]->indexingMode,geometries[2]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[2]->geometryoffset);

	shapes.addRenderableUniformParameter(renderables[4],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[4],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[4],"transform",Renderer::PT_MAT4,&transformShpere2[0][0]);
	shapes.addRenderableUniformParameter(renderables[4],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[4],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[4],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[4],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[4],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[4],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[4],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[4],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[4],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[2]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[4]->texture->TextureID);
	//glDrawElements(geometries[2]->indexingMode,geometries[2]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[2]->geometryoffset);

	shapes.addRenderableUniformParameter(renderables[5],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[5],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[5],"transform",Renderer::PT_MAT4,&transformArrow[0][0]);
	shapes.addRenderableUniformParameter(renderables[5],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[5],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[5],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[5],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[5],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[5],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[5],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[5],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[5],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[3]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[5]->texture->TextureID);
	//glDrawElements(geometries[3]->indexingMode,geometries[3]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[3]->geometryoffset);

	shapes.addRenderableUniformParameter(renderables[6],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[6],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[6],"transform",Renderer::PT_MAT4,&transformPlane[0][0]);
	shapes.addRenderableUniformParameter(renderables[6],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[6],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[6],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[6],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[6],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[6],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[6],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[6],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[6],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[4]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[6]->texture->TextureID);
	glDrawElements(geometries[4]->indexingMode,geometries[4]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[4]->geometryoffset);


	shapes.addRenderableUniformParameter(renderables[7],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[7],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[7],"transform",Renderer::PT_MAT4,&transformBinary[0][0]);
	shapes.addRenderableUniformParameter(renderables[7],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[7],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[7],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[7],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[7],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[7],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[7],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[7],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[7],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[5]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[7]->texture->TextureID);
	//glDrawElements(geometries[5]->indexingMode,geometries[5]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[5]->geometryoffset);

	/*shapes.addRenderableUniformParameter(renderables[8],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[8],"model2WorldTransform",Renderer::PT_MAT4,&transformPlane2[0][0]);
	shapes.addRenderableUniformParameter(renderables[8],"viewTransform",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[8],"cameraPos;",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[8],"specIntensity;",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[8],"diffuseCol;",Renderer::PT_VEC3,&difuseLight[0]);*/
	shapes.addRenderableUniformParameter(renderables[8],"dominatingColor",Renderer::PT_VEC3,&dominatingColor[0]);
	shapes.addRenderableUniformParameter(renderables[8],"lightPos",Renderer::PT_VEC3,&lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[8],"transform",Renderer::PT_MAT4,&transformPlane2[0][0]);
	shapes.addRenderableUniformParameter(renderables[8],"world",Renderer::PT_MAT4,&world[0][0]);
	shapes.addRenderableUniformParameter(renderables[8],"projectionMat",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[8],"ambientLight",Renderer::PT_VEC3,&ambientlight[0]);
	shapes.addRenderableUniformParameter(renderables[8],"Speclight",Renderer::PT_VEC3,&specColor[0]);
	shapes.addRenderableUniformParameter(renderables[8],"camPos",Renderer::PT_VEC3,&camPos[0]);
	shapes.addRenderableUniformParameter(renderables[8],"Power",Renderer::PT_FLOAT,&Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[8],"diffuseColor",Renderer::PT_VEC3,&difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[8],"normalMat",Renderer::PT_MAT3,&Normal[0][0]);
	shapes.addRenderableUniformParameter(renderables[8],"lighting",Renderer::PT_FLOAT,&lit);
	glBindVertexArray(geometries[4]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[8]->texture->TextureID);
	glDrawElements(geometries[4]->indexingMode,geometries[4]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[4]->geometryoffset);

	shapes.addRenderableUniformParameter(renderables[9],"model2WorldTransform",Renderer::PT_MAT4,&tangcubeTransform[0][0]);
	shapes.addRenderableUniformParameter(renderables[9],"viewTransform",Renderer::PT_MAT4,&projectionmatrix[0][0]);
	shapes.addRenderableUniformParameter(renderables[9],"diffuseCol", Renderer::PT_VEC3, &difuseLight[0]);
	shapes.addRenderableUniformParameter(renderables[9],"specIntensity", Renderer::PT_FLOAT, &Powerofspectralness);
	shapes.addRenderableUniformParameter(renderables[9],"cameraPos", Renderer::PT_VEC3, &camPos[0]);
	shapes.addRenderableUniformParameter(renderables[9],"lightPos", Renderer::PT_VEC3, &lightPosition[0]);
	shapes.addRenderableUniformParameter(renderables[9],"normalRotationMat", Renderer::PT_MAT4, &myRotationMat[0][0]);
	glBindVertexArray(geometries[6]->vertexArrayID);
	glBindTexture(GL_TEXTURE_2D,renderables[9]->texture->TextureID);
	glDrawElements(geometries[6]->indexingMode,geometries[6]->numIndices,GL_UNSIGNED_SHORT,(void*)geometries[6]->geometryoffset);
}	
void MyGLWindow::sendDataToHardware()
{

	Neumont::ShapeData cube= Neumont::ShapeGenerator::makeCube();
	Neumont::ShapeData Torus= Neumont::ShapeGenerator::makeTorus(120);
	Neumont::ShapeData Sphere= Neumont::ShapeGenerator::makeSphere(10);
	Neumont::ShapeData Arrow= Neumont::ShapeGenerator::makeArrow();
	Neumont::ShapeData plane= Neumont::ShapeGenerator::makePlane(2);
	Neumont::ShapeData TangCube = makeCube();


	
	shaders[1]=shapes.createShaderInfo("../shaders/lightVertShader.glsl","../shaders/lightFragShader.glsl");
	shaders[2]=shapes.createShaderInfo("../shaders/LightingVertexShaderCode.glsl", "../shaders/LightingFragmentShaderCode.glsl");
	shaders[3]=shapes.createShaderInfo("../shaders/LightedBinaryVertexShaderCode.glsl", "../shaders/LightedBinaryFragmentShaderCode.glsl");
	shaders[4]=shapes.createShaderInfo("../shaders/lightedVertShader2 (2).glsl", "../shaders/lightedFragShader2 (3).glsl");
	shaders[5]=shapes.createShaderInfo("../shaders/NormalVertexShaderCode.glsl", "../shaders/NormalFragmentShaderCode.glsl");
	shaders[6]=shapes.createShaderInfo("../shaders/LightingVertexShaderCode2.glsl", "../shaders/LightingFragmentShaderCode2.glsl");
	shaders[7]=shapes.createShaderInfo("../shaders/TanVert.glsl", "../shaders/TanFrag.glsl");


	
	textures[0]=shapes.addTexture("umbreon.png");
	textures[1]=shapes.addTexture("patter2.png");
	textures[2]=shapes.addTexture("pikachu.png");
	textures[3]=shapes.addTexture("Shapes.png");


	
	geometries[0]=shapes.addGeometry(cube.verts,cube.vertexBufferSize(),cube.indices,cube.numIndices,GL_TRIANGLES);
	shapes.addShaderStreamedParameter(geometries[0],0,Renderer::PT_VEC3,0,12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[0],1,Renderer::PT_VEC4,geometries[0]->BufferOffset+3*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[0],2,Renderer::PT_VEC3,geometries[0]->BufferOffset+7*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[0],3,Renderer::PT_VEC2,geometries[0]->BufferOffset+10*sizeof(float),12*sizeof(float));
	renderables[0]=shapes.addRenderable(geometries[0],transformCube1,shaders[1],textures[0]);
	
	geometries[1]=shapes.addGeometry(Torus.verts,Torus.vertexBufferSize(),Torus.indices,Torus.numIndices,GL_TRIANGLES);
	shapes.addShaderStreamedParameter(geometries[1],0,Renderer::PT_VEC3,geometries[1]->BufferOffset,12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[1],1,Renderer::PT_VEC4,geometries[1]->BufferOffset+3*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[1],2,Renderer::PT_VEC3,geometries[1]->BufferOffset+7*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[1],3,Renderer::PT_VEC2,geometries[1]->BufferOffset+10*sizeof(float),12*sizeof(float));

	renderables[1]=shapes.addRenderable(geometries[1],transformTorus1,shaders[2],textures[2]);
	renderables[2]=shapes.addRenderable(geometries[1],transformTorus2,shaders[2],textures[2]);

	geometries[2]=shapes.addGeometry(Sphere.verts,Sphere.vertexBufferSize(),Sphere.indices,Sphere.numIndices,GL_TRIANGLES);
	shapes.addShaderStreamedParameter(geometries[2],0,Renderer::PT_VEC3,geometries[2]->BufferOffset,12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[2],1,Renderer::PT_VEC4,geometries[2]->BufferOffset+3*sizeof(float),12*sizeof(float));
 	shapes.addShaderStreamedParameter(geometries[2],2,Renderer::PT_VEC3,geometries[2]->BufferOffset+7*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[2],3,Renderer::PT_VEC2,geometries[2]->BufferOffset+10*sizeof(float),12*sizeof(float));

	renderables[3]=shapes.addRenderable(geometries[2],transformShpere1,shaders[2],textures[1]);
	renderables[4]=shapes.addRenderable(geometries[2],transformShpere2,shaders[2],textures[1]);

	geometries[3]=shapes.addGeometry(Arrow.verts,Arrow.vertexBufferSize(),Arrow.indices,Arrow.numIndices,GL_TRIANGLES);
	shapes.addShaderStreamedParameter(geometries[3],0,Renderer::PT_VEC3,geometries[3]->BufferOffset,12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[3],1,Renderer::PT_VEC4,geometries[3]->BufferOffset+3*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[3],2,Renderer::PT_VEC3,geometries[3]->BufferOffset+7*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[3],3,Renderer::PT_VEC2,geometries[3]->BufferOffset+10*sizeof(float),12*sizeof(float));

	renderables[5]=shapes.addRenderable(geometries[3],transformArrow,shaders[2],textures[2]);

	geometries[4]=shapes.addGeometry(plane.verts,plane.vertexBufferSize(),plane.indices,plane.numIndices,GL_TRIANGLES);
	shapes.addShaderStreamedParameter(geometries[4],0,Renderer::PT_VEC3,geometries[4]->BufferOffset,12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[4],1,Renderer::PT_VEC4,geometries[4]->BufferOffset+3*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[4],2,Renderer::PT_VEC3,geometries[4]->BufferOffset+7*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[4],3,Renderer::PT_VEC2,geometries[4]->BufferOffset+10*sizeof(float),12*sizeof(float));

	renderables[6]=shapes.addRenderable(geometries[4],transformPlane,shaders[2],textures[0]);
	renderables[8]=shapes.addRenderable(geometries[4],transformPlane2,shaders[6],textures[3]);
	


	geometries[5]=shapes.readBinary("Cube.bin");
	shapes.addShaderStreamedParameter(geometries[5],0,Renderer::PT_VEC3,geometries[5]->BufferOffset,8*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[5],2,Renderer::PT_VEC3,geometries[5]->BufferOffset+3*sizeof(float),8*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[5],3,Renderer::PT_VEC2,geometries[5]->BufferOffset+6*sizeof(float),8*sizeof(float));
	renderables[7]=shapes.addRenderable(geometries[5],transformBinary,shaders[3],textures[2]);

	geometries[6]=shapes.addGeometry(TangCube.verts,TangCube.vertexBufferSize(),TangCube.indices,TangCube.numIndices,GL_TRIANGLES);
	shapes.addShaderStreamedParameter(geometries[6],0,Renderer::PT_VEC3,geometries[6]->BufferOffset,12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[6],1,Renderer::PT_VEC4,geometries[6]->BufferOffset+3*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[6],2,Renderer::PT_VEC3,geometries[6]->BufferOffset+7*sizeof(float),12*sizeof(float));
	shapes.addShaderStreamedParameter(geometries[6],3,Renderer::PT_VEC2,geometries[6]->BufferOffset+10*sizeof(float),12*sizeof(float));

	renderables[9] =shapes.addRenderable(geometries[6],tangcubeTransform,shaders[7],textures[3]);
}
//std::string readShaderCode(const char *fileName)
//{
//	std::ifstream input(fileName);
//
//	if(!input.good())
//	{
//		qDebug() << "File not found" << fileName;
//		exit(1);
//	}
//	return std::string(std::istreambuf_iterator<char>(input),
//		std::istreambuf_iterator<char>());
//}
//void MyGLWindow::CompileShaders()
//{
//	GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
//	GLuint fragShaderID=glCreateShader(GL_FRAGMENT_SHADER);
//	const char* adapter[1];
//	
//	std::string shaderCode= readShaderCode("../shaders/LightingVertexShaderCode.glsl");
//	adapter[0] = shaderCode.c_str();
//	glShaderSource(vertexShaderID,1,adapter,0);
//
//	shaderCode= readShaderCode("../shaders/LightingFragmentShaderCode.glsl");
//	adapter[0] = shaderCode.c_str();
//	glShaderSource(fragShaderID,1,adapter,0);
//
//	glCompileShader(vertexShaderID);
//	glCompileShader(fragShaderID);
//
//	GLint compileStatus;
//	glGetShaderiv(vertexShaderID,GL_COMPILE_STATUS,&compileStatus);
//	if(compileStatus != GL_TRUE)
//	{
//		GLint logLength;
//		glGetShaderiv(vertexShaderID,GL_INFO_LOG_LENGTH, &logLength);
//		char* buffer = new char [logLength];
//		GLsizei bitBucket;
//		glGetShaderInfoLog(vertexShaderID,logLength,&bitBucket,buffer);
//		qDebug() <<buffer;
//		delete [] buffer;
//	}
//	glGetShaderiv(fragShaderID,GL_COMPILE_STATUS,&compileStatus);
//	if(compileStatus != GL_TRUE)
//	{
//		GLint logLength;
//		glGetShaderiv(fragShaderID,GL_INFO_LOG_LENGTH, &logLength);
//		char* buffer = new char [logLength];
//		GLsizei bitBucket;
//		glGetShaderInfoLog(fragShaderID,logLength,&bitBucket,buffer);
//		qDebug() <<buffer;
//		delete [] buffer;
//	}
//
//	programID = glCreateProgram();
//	glAttachShader(programID,vertexShaderID);
//	glAttachShader(programID,fragShaderID);
//
//	glLinkProgram(programID);
//
//	glUseProgram(programID);
//
//	glDeleteShader(vertexShaderID);
//	glDeleteShader(fragShaderID);
//}
void MyGLWindow::myUpdate()
{
	if(GetAsyncKeyState('E'))
	{
	QCursor mouse = cursor();
	QPoint mousePosition = mouse.pos();
	cam.mouseUpdate(glm::vec2(mousePosition.x(),mousePosition.y()));
	}

	if(GetAsyncKeyState('W'))
	{
		cam.moveForward();
	}
	if(GetAsyncKeyState('S'))
	{
		cam.moveBackward();
	}
	if(GetAsyncKeyState('A'))
	{
		cam.strafeLeft();
	}
	if(GetAsyncKeyState('D'))
	{
		cam.strafeRight();
	}
	if(GetAsyncKeyState('R'))
	{
		cam.moveUp();
	}
	if(GetAsyncKeyState('F'))
	{
		cam.moveDown();
	}
	if(GetAsyncKeyState('Y'))
	{
		lightPosition[1]+=0.1f;
	}
	if(GetAsyncKeyState('H'))
	{
		lightPosition[1]-=0.1f;
	}
	if(GetAsyncKeyState('L'))
	{
		lightPosition[0]+=0.1f;
	}
	if(GetAsyncKeyState('J'))
	{
		lightPosition[0]-=0.1f;
	}
	if(GetAsyncKeyState('K'))
	{
		lightPosition[2]+=0.1f;
	}
	if(GetAsyncKeyState('I'))
	{
		lightPosition[2]-=0.1f;
	}
	if(lighting->isChecked())
	{
		lit=1.0f;
	}
	if(!lighting->isChecked())
	{
		lit=0.0f;
	}
	
	paintGL();
	swapBuffers();
}
void MyGLWindow::CreateTexture(const char* name,int textureID,int ProgramId,GLuint* data,char* parameterName)
{
	QImage texture;
	if(!texture.load(name))
	{
		qDebug()<<"Texture Load Failure.";
		return;
	}
	texture = convertToGLFormat(texture);
	GLint location= glGetUniformLocation(ProgramId,name);
	glUniform1i(location,textureID);
	glActiveTexture(textureID);
	glGenTextures(1,data);
	glBindTexture(GL_TEXTURE_2D,*data);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,texture.width(),texture.height(),0,GL_RGBA,GL_UNSIGNED_BYTE,(GLvoid*)texture.bits());
}

