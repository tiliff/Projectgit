#version 400

in vec3 reflectionDir;
out vec4 color;

uniform samplerCube myTexture;

void main() 
{
	color = texture(myTexture,reflectionDir);
	
}