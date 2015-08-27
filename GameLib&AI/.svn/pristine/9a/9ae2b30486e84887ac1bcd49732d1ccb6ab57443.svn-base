#version 400

in vec2 outUv;

uniform float octaveValues;
uniform sampler2D myTexture;

out vec4 outCol;

void main()
{
	int octaveCast = int(octaveValues);
	vec4 myNoise = texture(myTexture, outUv);
	
	outCol = vec4(myNoise[octaveCast], myNoise[octaveCast], myNoise[octaveCast], 1.0f);

	//outCol = vec4(1.0f, 0.0f, 0.0f, 1.0f);
}
