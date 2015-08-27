#include "Enemycruizer.h"
#include "Matrix3.h"
randomness ran;

float timetoSpawn=100.0f;
Vector2d cruize[]=
{
	1.5*Vector2d(25,0),
	1.5*Vector2d(-25,25),
	1.5*Vector2d(-20,15),
	1.5*Vector2d(-25,0),
	1.5*Vector2d(-20,-15),
	1.5*Vector2d(-25,-25)
};


enemyCruizer::enemyCruizer()
{
	dead=false;
	hit=false;
	position=Vector2d(ran.randomInRange(-1000,1800),ran.randomInRange(-1000,1800));
	numhitstotake=(int)ran.randomInRange(6,10);
	numTimesHit=0;
	gameOver=false;
	if(position.x<=1920&&position.x>=0&&position.y<=1040&&position.y>=0)
	{
		position=Vector2d(ran.randomInRange(-1000,2500),ran.randomInRange(-1000,2500));
	}
	velocity=Vector2d(ran.randomInRange(1.0f,2.0f),0);
	
}

void enemyCruizer::draw(Core::Graphics& g)
{
	const int numShippoints= sizeof(cruize)/sizeof(*cruize);
	Matrix3 rotato=rotato.rotate(angle);
	g.SetColor(RGB(200,100,100));
	if(!dead)
	{
		for(int i=0;i<numShippoints;i++)
		{

			const Vector2d& s1=rotato*cruize[i]+position;
			const Vector2d& s2=rotato*cruize[(i+1)%numShippoints]+position;
			g.DrawLine(s1.x,s1.y,s2.x,s2.y);
		}
	}
}

void enemyCruizer::update(float dt,Vector2d shippos,Vector2d bulletpos)
{
	timetoSpawn-=dt;
	newposition=(shippos-position);
	newvelocity=(velocity.x*normalize(newposition));
	angle=(shippos.y>= position.y) ? acos(newvelocity.x/velocity.x) : -acos(newvelocity.x/velocity.x);
	float hitvec=length(bulletpos-position);
	if(!dead)
	{
		position = position + dt*newvelocity;
	}
	if(!dead && hitvec <= 20.0f)
	{
		hit=true;
	}
	if(length(newposition) <= 20)
	{
		dead=true;
		gameOver=true;
	}
	if(dead)
	{
		if(timetoSpawn<=0 && !shipSpawn)
		{
			shipSpawn=true;
			dead=false;
			position=Vector2d(ran.randomInRange(-1000,2000),ran.randomInRange(-1000,1800));
		if(position.x<=1920&&position.x>=0&&position.y<=1080&&position.y>=0)
		{
			position=Vector2d(ran.randomInRange(-1000,2000),ran.randomInRange(-1000,1800));
		}
			dead=false;
			timetoSpawn=100.0f;
		}
	}
	if(hit)
	{
		numTimesHit++;
		hit=false;
	}
	if(timetoSpawn<=0)
	{
		shipSpawn=false;
	}
	if(numTimesHit==numhitstotake)
	{
		dead=true;
	}
	if(timetoSpawn<=0)
	{
		shipSpawn=false;
	}
	
}
bool enemyCruizer::CheckGame()
{
	return gameOver;
}