#pragma once

#include <Engine\BasicGui.h>
#include <ShapeGenerator.h>
#include <Engine\WidgetRenderer.h>
#include <Engine\Tools\NUShapeEditor.h> // VERY handy tools for editing NU shapes
#include <Engine\Tools\Random\Glm.h> // includes all random from myRandom + glm randomness

#include <glm\gtx\transform.hpp>

class Testing : public WidgetRenderer {
public:
	glm::vec3 rotation;
	glm::vec3 rotation2;
	glm::vec3 rotation3;
	bool binaryAlphaVis;
	bool blendtab;
	bool PlaneNormalTab;
	bool isblending;
	float alpha;
	float alpha2;
	glm::vec4 finalcolor;
	glm::vec4 finalcolor2;
	glm::vec4 finalcolor3;
	glm::vec4 finalcolor4;
	glm::vec4 finalcolor5;
	bool showFlatMap;
	glm::vec3 diffuseCol;
	glm::vec3 specCol;
	float specIntensity;
	glm::mat4 myRotationMat;
	bool showTangantCube;
	float octaves;
	GLuint texID;
	bool showNoisePlane;
	bool showHeightMap;
	float discardValue;
	bool showDyingTeapot;
	bool ShowSphere;
	bool ShowCubeMap;
	bool DisplayTexture;


	glm::vec3 rotationSpeed;
	glm::vec3 rotationSpeed2;

	glm::vec3 blendColor;
	int myTexture;
	int myTexture2;
	int myTexture3;
	int myTexture4;
	int myTexture5;
	int myTexture6;
	int myTexture7;
	int myTexture8;
	int myTexture9;





	Renderable * meRenderable;
	Renderable * meRenderable2;
	Renderable * meRenderable3;
	Renderable * meRenderable4;
	Renderable * meRenderable5;
	Renderable * meRenderable6;
	Renderable * Cubetang;
	Renderable * Cubetanglight;
	Renderable * noisePlane;
	Renderable * heightPlane;
	Renderable * dyingTeapot;
	Renderable * RefShere;
	Renderable * Cubemap;




    


	void init();
	void nextFrame(float dt);
	void getPerlinNoiseForMap();
};