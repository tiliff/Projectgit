#version 400

in layout(location=0) vec3 pos;
in layout(location=1) vec3 col;
in layout(location=3) vec2 uv;

out vec4 outCol;
out vec2 outUv;

//mats
uniform mat4 viewTransform;
uniform mat4 model2WorldTransform;
uniform vec4 pureColor;


void main() 
{
	vec4 transformedPos =  model2WorldTransform * vec4(pos.x,pos.y,pos.z,1.0f);
	gl_Position =  viewTransform * transformedPos;
	
	
	outCol = vec4(pureColor);
	outUv = uv;
}