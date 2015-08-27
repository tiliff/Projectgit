#ifndef FLAT_PLANE_MAP
#define FLAT_PLANE_MAP

#include <Engine\Scene.h>
#include <ShapeGenerator.h>
#include <Engine\Tools\NUShapeEditor.h>
#include <Engine\Tools\Random\Glm.h>

class FlatPlaneMap : public Scene
{
public:
	Renderable* mappingRen;
	Renderable* lightCube;
	glm::vec3 diffuseCol;
	glm::vec3 specCol;
	float specIntensity;
	int myTexture;
};
#endif 
