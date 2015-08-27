#version 430

	in layout(location=0) vec3 position;
	in layout(location=1) vec3 color;
	in layout(location=2) vec3 normal;

	out vec4 decolor;
	uniform mat4 transform;
	uniform mat4 projectionMat;
	uniform vec3 dominatingColor;
	uniform vec3 ambientLight;
	uniform vec3 lightPos;
	uniform vec3 diffuseColor;
	uniform mat3 normalMat;
	
	void main()
	{
	 gl_Position= projectionMat * transform * vec4(position,1);
	 vec3 lightvec = normalize(lightPos-vec3(transform * vec4(position,1)));
	 vec3 normalVector= normalize(normalMat * normal);
	 float lightdot= max(dot(lightvec,normalVector),0.0);
	 vec3 difColor=diffuseColor*lightdot;
	 decolor= vec4((ambientLight + difColor) * dominatingColor,1);
	 //decolor=color * ambientLight;
	}