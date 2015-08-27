#version 400
	
	//in vec4 decolor;
	in vec3 thePosition;
	in vec3 theNormal;
	in vec2 outUv;
	out vec4 finalColor;

	uniform vec3 dominatingColor;
	uniform vec3 ambientLight;
	uniform vec3 Speclight;
	uniform vec3 camPos;
	uniform float Power;
	uniform vec3 lightPos;
	uniform mat3 normalMat;
	uniform vec3 diffuseColor;
	uniform sampler2D myTexture;
	uniform float lighting;

	void main()
	{
	if(lighting==1)
	{
	vec3 finalNormal= normalize(theNormal);
	vec3 view=normalize(camPos-thePosition);
	vec3 lightvec = normalize(lightPos-thePosition);
	vec3 reflectionVec= -reflect(lightvec,finalNormal);
	float specBright=clamp(dot(reflectionVec,view),0.0f,1.0f);
	specBright=pow(specBright,Power);
	vec3 normalVector= normalize(normalMat * theNormal);
	float lightdot= clamp( max(dot(lightvec,normalVector),0.0),0,1);
	vec3 difColor=diffuseColor*lightdot;
	vec3 spec=Speclight*specBright;
        vec3 light=ambientLight + difColor + spec;
	finalColor=vec4(clamp(light,0,1),1.0f) * vec4(dominatingColor,1.0f) * texture(myTexture,outUv).rgba;
        //finalColor=vec4((ambientLight + difColor)*vec4(dominatingColor,1.0f) + spec,1)*texture(myTexture,outUv).rgba;
	}
	else
	{
	finalColor=vec4(dominatingColor,1.0f) * texture(myTexture,outUv);
	}
	}