#version 400


in vec2 outUv;
in vec4 outPos;
in vec3 thenorm;

uniform sampler2D myTexture;
uniform vec3 lightPos;
uniform vec3 diffuseCol;
//uniform vec3 specCol;
uniform vec3 cameraPos;
uniform float specIntensity;

out vec4 finalCol;

void main() 
{

//LAB 3 (LIGHT ON MAP)
//vec3 newNorm = vec3((texture(myTexture, outUv).rgb - 0.5f)* 2);
Vec3 newNorm = normalize(texture2D(myTexture, UV ).rgb*2.0 - 0.5);
newNorm = vec3(newNorm.x,newNorm.y,newNorm.z);

vec3 lightVec = normalize(lightPos - vec3(outPos));
float lightDotNorm = clamp(dot(lightVec, newNorm), 0.0f, 1.0f);
vec3 spec = vec3(1.0f, 1.0f, 1.0f);
vec3 reflectVec = -reflect(lightVec, newNorm);
vec3 viewerVec = normalize(cameraPos - newNorm);
vec3 diffuse = diffuseCol * lightDotNorm;
float specIntensity = 50.0f;

spec *= diffuseCol * pow(clamp(dot(reflectVec, viewerVec), 0.0f, 1.0f), specIntensity);
finalCol = vec4(diffuse + spec, 1.0f);


//finalCol = vec4(spec, 1.0f);
}