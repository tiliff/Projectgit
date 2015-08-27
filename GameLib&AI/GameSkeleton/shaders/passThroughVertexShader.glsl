#version 400

in layout(location=0) vec3 position;
in layout(location=1) vec4 color;
out vec4 decolor;

uniform mat4 transform;
uniform mat4 projectionMat;


main()
{
    	vec4 v= vec4(position,1);
	vec4 newPosition = transform * v;
	vec4 projectedPosition= projectionMat * newPosition;
	gl_Position = projectedPosition;
	decolor=color;
}