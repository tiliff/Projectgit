#version 400
	
	in layout(location=0) vec3 position;
	in layout(location=1) vec3 color;
	
	out vec3 decolor;
	uniform mat4 transform;
	uniform mat4 projectionMat;
	uniform vec3 dominatingColor;
	
	void main()
	{
	 gl_Position= projectionMat * transform * vec4(position,1);
	 decolor=color;
	}
	