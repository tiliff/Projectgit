#include "Bullets.h"
#include "Turret.h"


void Bullet::draw(Core::Graphics& g)
	{
		if(fired)
		{

		Matrix3 trans=trans.translate(position.x,position.y);
		for(int j=0;j<lines;j++)
		{
			Vector2d p1=trans * outlinep[j]+position;
			Vector2d p2=trans * outlinep[(j+1)%lines]+position;
			g.DrawLine(p1.x,p1.y,p2.x,p2.y);
		}
		}
		else
		{
			position=Vector2d(2000.0f,0.0f);
			velocity=Vector2d(0.0f,0.0f);
		}
	}
void Bullet::resetBullet(Vector2d pos,Vector2d vel)
{
	fired=true;
	position=pos;
	velocity=vel;
}
void Bullet::Update(float dt)
{
	position=position+(dt*velocity);
	if(position.x < 0 ||position.x>1920||position.y<0||position.y>1080)
	{
		fired=false;
	}
}

