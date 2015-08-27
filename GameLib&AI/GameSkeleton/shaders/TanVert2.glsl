#version 400

	in layout(location=0) vec3 pos;
	in layout(location=1) vec3 tan;
	in layout(location=3) vec2 uv;
	in layout(location=2) vec3 norm;

	out vec2 outUv;
	out vec4 outPos;
	out mat3 myNormTrans;
	//out mat4 outM2Wmat;

	out vec3 MyDebug;

	//mats
	uniform mat4 viewTransform;
	uniform mat4 model2WorldTransform;
	uniform mat4 world;


void main() {
	vec4 v= vec4(pos,1);
	vec4 newPosition = world* model2WorldTransform * v;
	vec4 projectedPosition= viewTransform * newPosition;
	gl_Position = projectedPosition;
	vec3 biTan = cross(norm, vec3(tan));
	myNormTrans = mat3(tan, biTan, norm);
	
	outUv = uv;
	outPos = v;
	//outM2Wmat = model2WorldTransform;
	
	MyDebug = vec3(tan);
	//MyDebug = vec3(biTan);
	//MyDebug = vec3(norm);
	//MyDebug = vec3(uv,0);
}