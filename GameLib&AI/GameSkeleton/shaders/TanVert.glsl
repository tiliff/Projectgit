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


void main() {
	vec4 transformedPos =  model2WorldTransform * vec4(pos.x,pos.y,pos.z,1.0f);
	gl_Position =  viewTransform * transformedPos;
	vec3 biTan = cross(norm, vec3(tan));
	myNormTrans = mat3(tan, biTan, norm);
	
	outUv = uv;
	outPos = vec4(pos,1.0f);
	//outPos = transformedPos;
	//outM2Wmat = model2WorldTransform;
	
	MyDebug = vec3(tan);
	//MyDebug = vec3(biTan);
	//MyDebug = vec3(norm);
	//MyDebug = vec3(uv,0);
}