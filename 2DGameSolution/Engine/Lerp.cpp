#include "Lerp.h"

Vector2d lerpPoints[]=
{
	Vector2d(955,520),
	Vector2d(955,820),
	Vector2d(1255,520),
	Vector2d(955,220),
	Vector2d(655,520),
	Vector2d(955,720),
	Vector2d(1155,520),
	Vector2d(955,320),
	Vector2d(755,520),
	Vector2d(955,520)
	
};
int NumLerp=sizeof(lerpPoints)/sizeof(*lerpPoints)-1;
void Lerper::Update(float dt)
{
	
	   
		if(alpha>=1)
		{
			alpha=0;
			currentpath++;
		}
		
			dt;
			Vector2d a =lerpPoints[currentpath];
			Vector2d b =lerpPoints[currentpath+1%NumLerp];
			alpha +=dt*length(lerpPoints[0]-lerpPoints[1])/length(a-b);
			position = lerpvector(alpha,a,b);
			if(currentpath >= NumLerp)
		{
			currentpath=0;
		}
}
