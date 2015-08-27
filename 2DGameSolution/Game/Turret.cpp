#include "Turret.h"
#include "Matrix2.h"
Vector2d bulletpoints[]=
{
	Vector2d(0,2),
	Vector2d(2,0),
	Vector2d(0,-2),
	Vector2d(-2,0)
};
int numline=sizeof(bulletpoints)/sizeof(*bulletpoints);
Vector2d* v = bulletpoints;
Bullet bullets[15]=
{
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v),
	Bullet(numline,v)

};
float time=0.0f;
Matrix3 Turret::rotateTurret(Vector2d mouse)
{
	Matrix3 rtTemp;
	Vector2d temp=mouse-position;
	Vector2d temp2=normalize(temp);
	Vector2d temp3=perpcw(normalize(temp));
	rtTemp.basis1 = Vector3d(temp2.x,temp2.y,0);
	rtTemp.basis2 = Vector3d(temp3.x,temp3.y,0);
	return rtTemp;
}
void Turret::Draw(Core::Graphics& g)
{
	g.SetColor(RGB(100,100,255));
	Vector2d mouse(0.0f+Core::Input::GetMouseX(), 0.0f+Core::Input::GetMouseY());
	Matrix3 rottur=rotateTurret(mouse);
	Matrix3 fin=multiplym(rottur,Matrix3::Scale(4,4));
	turretface=Vector2d(normalize( mouse-position));
	for(int i=0;i<NUM_TURRETPOINTS;i++)
	{
		const Vector2d& v1=(fin*outlinep[i]+position);
		const Vector2d& v2=(fin*outlinep[(i+1)%NUM_TURRETPOINTS]+position);
		g.DrawLine(v1.x,v1.y,v2.x,v2.y);
		
	}
	for(int i =0;i<15;i++)
		{
			g.SetColor(RGB(100,255,255));
			bullets[i].draw(g);
	}
	g.SetColor(RGB(255,255,255));
}
Vector2d Turret::GetBulPos(int i)
{
  return bullets[i].position;
}
void Turret::updatepos(float dt,Vector2d shippos)
{
	time+=dt;
	position=shippos;
	if(Core::Input::IsPressed(Core::Input::BUTTON_LEFT))
	{
		for(int i =0;i<20;i++)
		{
		if(time>0.2f && !bullets[i].fired)
		{
			time=0.0f;
			bullets[i].resetBullet(shippos,Vector2d((500*turretface.x),(500* turretface.y)));
		}
		}
	}
	for(int i =0;i<20;i++)
		{
			bullets[i].Update(dt);
	}
}