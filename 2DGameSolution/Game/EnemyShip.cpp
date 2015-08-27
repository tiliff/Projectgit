#include "EnemyShip.h"
#include "Matrix3.h"
#include "Score.h"
randomness randy;
ParticleSystem part;
int shipscore=0;
static float timespawn=50.0f;
int spawn=3;
bool shipnotspawn=false;
Vector2d lerper[]=
{
	Vector2d(25,0),
	Vector2d(-25,25),
	Vector2d(-20,15),
	Vector2d(-25,0),
	Vector2d(-20,-15),
	Vector2d(-25,-25)
};


EnemyShip::EnemyShip()
{
	dead=true;
	hit=false;
	gameOver=false;
	position=Vector2d(randy.randomInRange(-1000,1800),randy.randomInRange(-1000,1800));
	while(position.x<=1950&&position.x>=0&&position.y<=1080&&position.y>=0)
	{
		position=Vector2d(randy.randomInRange(-1000,2000),randy.randomInRange(-1000,2000));
	}
	velocity=Vector2d(randy.randomInRange(5.0f,10.0f),0);
	
}
void EnemyShip::draw(Core::Graphics& g)
{
	const int numShippoints= sizeof(lerper)/sizeof(*lerper);
	Matrix3 rotato=rotato.rotate(angle);
	g.SetColor(RGB(200,100,100));
	if(!dead)
	{
		for(int i=0;i<numShippoints;i++)
		{

			const Vector2d& s1=rotato*lerper[i]+position;
			const Vector2d& s2=rotato*lerper[(i+1)%numShippoints]+position;
			g.DrawLine(s1.x,s1.y,s2.x,s2.y);
		}
	}
}

void EnemyShip::update(float dt,Vector2d shippos,Vector2d bulletpos)
{
	timespawn-=dt;
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
		dead=true;
		hit=true;
	}
	if(length(newposition) <= 10)
	{
		dead=true;
		gameOver=true;
	}
	if(dead)
	{
		position=Vector2d(randy.randomInRange(-1000,2000),randy.randomInRange(-1000,2000));
		while(position.x<=1920&&position.x>=0&&position.y<=1080&&position.y>=0)
		{
			position=Vector2d(randy.randomInRange(-1000,2000),randy.randomInRange(-1000,1800));
		}
		if(timespawn<=0 && !shipnotspawn)
		{
			shipnotspawn=true;
			dead=false;
			timespawn=50.0f;
		}
	}
	if(hit)
	{
		part.createEffect(1,1,position,100);
		part.update(dt);
		part.deleteparts(dt);
		dead=true;
		hit=false;
		position=Vector2d(randy.randomInRange(-1000,2000),randy.randomInRange(-1000,1800));
	}
	if(timespawn<=0)
	{
		shipnotspawn=false;
	}
	
}
bool EnemyShip::CheckGame()
	{
		return gameOver;
	}