#version 400

in vec2 outUv;
in vec4 outCol;

uniform float discardValue;
uniform sampler2D myTexture;

out vec4 finalCol;

void main()
{	
	finalCol = outCol * texture(myTexture, outUv).rgba;
	
	if(finalCol.a < discardValue)
	{
		discard;
	}
	
	if((finalCol.a - discardValue) < 0.05)
	{
		finalCol = mix(vec4(0.5f, 0.0f, 0.0f, 0.5f), vec4(0.0f, 0.0f, 0.5f, 1.0f), 0.1f);
	}
	
	finalCol.a = 1;
}
