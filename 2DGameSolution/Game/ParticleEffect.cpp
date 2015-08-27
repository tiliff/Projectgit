#include "ParticleEffect.h"
#include "Matrix3.h"


bool particleEffect::update(float dt)
{
	
	bool increment=false;
	bool dead=true;
	for(int i=0;i<numberParticles;i++)
	{
		if(particles[i].type==1)
		{
         particles[i].lifetime-=dt;
		}
		if(particles[i].type==2 &&increment)
		{
			particles[i].lifetime+=dt;
			if(particles[i].lifetime>=1)
			{
				increment=false;
			}
         
		}
		if(particles[i].type==2 && !increment)
		{
			particles[i].lifetime-=dt;
			if(particles[i].lifetime<=.1)
			{
				increment=true;
			}
         
		}
		if(particles[i].lifetime<1.0f && particles[i].type==1)
		{
			particles[i].color=color.brightness(particles[i].color,particles[i].lifetime);
			particles[i].position=particles[i].position+dt*particles[i].velocity;
		}
		if(particles[i].lifetime<=.00001f)
		{
			dead=false;
		}
		if(particles[i].type==2)
		{
				particles[i].color=RGB(ryan.randomInRange(0,255),ryan.randomInRange(0,255),ryan.randomInRange(0,255));
				particles[i].color=color.brightness(particles[i].color,particles[i].lifetime);
		}
		if(particles[i].lifetime<=.1f)
		{
			dead=false;
			particles[i].color=(RGB(ryan.randomInRange(1,255),ryan.randomInRange(1,255),ryan.randomInRange(1,255)));
			particles[i].color=color.brightness(particles[i].color,ryan.randomInRange(0,1));
			particles[i].position=Vector2d(ryan.randomInRange(0,1920),ryan.randomInRange(0,1040));
			particles[i].lifetime=ryan.randomInRange(1,3);
		}
	}

	return dead;
}

void particleEffect::draw(Core::Graphics& g)
{
	Vector2d pointA,pointB;

	for(int i=0;i<numberParticles;i++)
	{
		if(particles[i].lifetime>0)
		{
			if(particles[i].type==1)
			{
				g.SetColor(particles[i].color);
				pointA=particles[i].position;
				pointB=particles[i].position+Vector2d(1,0);
				g.DrawLine(pointA.x,pointA.y,pointB.x,pointB.y);
			}
			if(particles[i].type==2)
			{
				
				for(int j=0;j<particles[i].size;j++)
				{
					g.SetColor(particles[i].color);
					pointA=particles[i].position+Vector2d((float)-j,0.0f);
					pointB=particles[i].position+Vector2d(0,(float)j);
					g.DrawLine(pointA.x,pointA.y,pointB.x,pointB.y);
					pointA=particles[i].position+Vector2d(0,(float)j);
					pointB=particles[i].position+Vector2d((float)j,0);
					g.DrawLine(pointA.x,pointA.y,pointB.x,pointB.y);
					pointA=particles[i].position+Vector2d((float)j,(float)0);
					pointB=particles[i].position+Vector2d(0,(float)-j);
					g.DrawLine(pointA.x,pointA.y,pointB.x,pointB.y);
					pointA=particles[i].position+Vector2d(0,(float)-j);
					pointB=particles[i].position+Vector2d((float)-j,0.0f);
					g.DrawLine(pointA.x,pointA.y,pointB.x,pointB.y);
				}
			}
		}
	}

}