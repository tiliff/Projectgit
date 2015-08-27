
#version 400
	
	in layout(location=0) vec3 position;
	in layout(location=1) vec4 color;
	in layout(location=2) vec3 normal;
	in layout(location=3) vec2 Uv;

	
	uniform mat4 transform;
	uniform mat4 projectionMat;
	uniform mat4 world;
	//uniform vec3 dominatingColor;
	//uniform vec3 ambientLight;
	//uniform vec3 lightPos;
	//uniform vec3 diffuseColor;
	//uniform mat3 normalMat;
	//out vec4 decolor;
	out vec3 thePosition;
	out vec3 theNormal;
	out vec2 outUv;

	void main()
	{
	vec4 v= vec4(position,1);
	vec4 newPosition = world* transform * v;
	vec4 projectedPosition= projectionMat * newPosition;
	gl_Position = projectedPosition;
	theNormal=vec3(mat3(transform)*normal);
	thePosition=vec3(mat3(transform)*position);
	outUv=Uv;
	}