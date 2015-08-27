#version 400

//PassThrough FragShader

in vec4 outCol;
in vec2 outUv;

uniform sampler2D myTexture;

void main() 
{
	
	gl_FragColor = outCol * texture(myTexture, outUv).rgba;
	if( gl_FragColor.g > 0.9f && gl_FragColor.r < 0.1f && gl_FragColor.b < 0.1f)
	{
		discard;
	}
	else if(gl_FragColor.g < 0.1f && gl_FragColor.r < 0.1f && gl_FragColor.b < 0.1f)
	{
		discard;
	}	
	
}

