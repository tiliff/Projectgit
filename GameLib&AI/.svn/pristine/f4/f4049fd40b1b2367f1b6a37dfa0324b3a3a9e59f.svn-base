#version 400

in layout(location=0) vec4 pos;
in layout(location=3) vec2 uv;
in layout(location=2) vec3 norm;

out vec3 reflectionDir;

uniform mat4 viewTransform;
uniform mat4 model2WorldTransform;


void main() {
	reflectionDir = vec3(pos);
	
	gl_Position = viewTransform * model2WorldTransform * pos;
    
}