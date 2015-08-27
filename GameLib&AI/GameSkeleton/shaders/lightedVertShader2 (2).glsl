#version 400

in layout(location=0) vec3 pos;
in layout(location=1) vec3 col;
in layout(location=3) vec2 uv;

out vec2 outUv;
out vec4 outPos;

//mats
uniform mat4 viewTransform;
uniform mat4 model2WorldTransform;



void main() {
	vec4 transformedPos =  model2WorldTransform * vec4(pos.x,pos.y,pos.z,1.0f);
	gl_Position =  viewTransform * transformedPos;
	
	
	outUv = uv;
	outPos = transformedPos;
}