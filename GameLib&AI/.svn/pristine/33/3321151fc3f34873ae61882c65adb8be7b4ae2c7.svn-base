#version 400

in layout(location=0) vec4 pos;
in layout(location=2) vec3 normal;
in layout(location=3) vec2 uv;

out vec3 reflectionDir;

//mats
uniform mat4 viewTransform;
uniform mat4 model2WorldTransform;
uniform vec3 camPos;


void main() 
{
	vec4 worldposv4= model2WorldTransform * pos;
        vec3 worldposv3= vec3(worldposv4);
	vec3 Norm = vec3(normalize(vec4(normal,0.0f)));
	vec3 worldView = normalize(camPos-worldposv3);

	reflectionDir= reflect(-worldView, Norm);

	gl_Position =  viewTransform * worldposv4;
}