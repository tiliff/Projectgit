#version 400

//PassThrough FragShader

in vec4 outCol;
in vec2 outUv;

uniform sampler2D myTexture;

void main() {
	if(texture(myTexture, outUv).g < 0.1f && texture(myTexture, outUv).r > 0.1f && texture(myTexture, outUv).b < 0.1f)
	{
		discard;
	}
	gl_FragColor = texture(myTexture, outUv);

}