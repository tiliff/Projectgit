#include "Planets.h"

float rotationangle=0.0f;
Vector2d planetPoints[]=
{
	Vector2d(  0,0),
	Vector2d( 60,60),
	Vector2d( 30,0),
	Vector2d(-60,-60)

};
const unsigned int NUM_Points = sizeof(planetPoints) / sizeof(*planetPoints);
void Planets::drawplanets(int numrecurse,Matrix3 temp,Core::Graphics& g)
{
	if(numrecurse>0)
	{

		for(unsigned int i=0; i<NUM_Points; i++)
		{
			const Vector2d& p1=((temp * planetPoints[i])+Vector2d(temp.basis1.z,temp.basis2.z));
			const Vector2d& p2=((temp * planetPoints[(i+1)%NUM_Points])+Vector2d(temp.basis1.z,temp.basis2.z));
			g.SetColor(RGB(255,50,255));
			g.DrawLine(p1.x,p1.y,p2.x,p2.y);
		}
		drawplanets(numrecurse-1,multiplym(temp,multiplym(multiplym(Matrix3::Scale(0.9f,0.9f),Matrix3::rotate(rotationangle)),Matrix3::translate(120,180))),g);
	}
}
void Planets::updateplanets(float dt)
{
	rotationangle+=1*dt/3;
}