#version 400


in vec2 outUv;
in vec4 outPos;
in mat3 myNormTrans;
//in mat4 outM2Wmat;
in vec3 MyDebug;

uniform sampler2D myTexture;
uniform mat4 normalRotationMat;
uniform vec3 lightPos;
uniform vec3 diffuseCol;
uniform vec3 cameraPos;
uniform float specIntensity;

out vec4 finalCol;

void main() 
{

//LAB 4 (LIGHT ON MAP)
vec3 newNorm = vec3((texture(myTexture, outUv).rgb - 0.5f)* 2);
newNorm = vec3(newNorm.x,-newNorm.y,newNorm.z);

vec3 TanNorm =  normalize(vec3(normalRotationMat * vec4(myNormTrans * newNorm, 1.0f)));

vec3 lightVec = normalize(lightPos - vec3(outPos));
float lightDotNorm = clamp(dot(lightVec, TanNorm), 0.0f, 1.0f);
vec3 spec = vec3(1.0f, 1.0f, 1.0f);
vec3 reflectVec = -reflect(lightVec, TanNorm);
vec3 viewerVec = normalize(cameraPos - TanNorm);
vec3 diffuse = diffuseCol * lightDotNorm;
float specIntensity = 50.0f;

spec *= diffuseCol * pow(clamp(dot(reflectVec, viewerVec), 0.0f, 1.0f), specIntensity);
finalCol = vec4(diffuse + spec, 1.0f);


//finalCol = vec4(myNormTrans * vec3(0,0,1),  1.0f);
//finalCol = vec4(MyDebug,  1.0f);
//finalCol = vec4(normalRotationMat * vec4(1,0,0,1));
//finalCol = vec4(newNorm, 1.0f);
}

