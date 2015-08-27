#include "Spaceship.h"

ParticleSystem party;
Vector2d wallpoints[]=
{
	Vector2d(1910/2,0),
	Vector2d(1910,520),
	Vector2d(1910/2,1040),
	Vector2d(0,520),
	Vector2d(1910/2,0)
};
Vector2d* w=wallpoints;
Shape wall(4,w);
Vector2d nextposition;
int numwalls=sizeof(wallpoints)/sizeof(*wallpoints);
bool wrap=true;
bool bounce=false;
bool wallbounce;
bool artbounce=false;

void Spaceship::Wrapship(Vector2d position)
{
	if(position.x >= 1935)
	{
		Spaceship::position.x=-35;
	}
	else if(position.x <= -35)
	{
		Spaceship::position.x=1935;
	}
	else if(position.y >= 1095)
	{
		Spaceship::position.y=-35;
	}
	else if(position.y <= -35)
	{
		Spaceship::position.y=1095;
	}
	
}
void Spaceship::Draw(Core::Graphics& g)
{
	if(!gameOver)
	{
	g.SetColor(RGB(50,255,50));
	    Matrix3 temp= temp.rotate(angle);
		Matrix3 temptrans=temptrans.translate(position.x,position.y);
		Matrix3 scaler= scaler.Scale(size,size);
		Matrix3 end=multiplym(multiplym(scaler,temp),temptrans);
	    for(int i=0; i<numline; i++)
		{
			Vector2d p1=((end * outlinep[i])+position);
			Vector2d p2=((end * outlinep[(i+1)%numline])+position);
			g.DrawLine(p1.x,p1.y,p2.x,p2.y);
		}
	g.DrawString(10,10,"Use W,S,A,D to move and 1,2,3 to change modes \n Hold the f key to leave an explosive pebble");
	if(wrap)
	{
		g.DrawString(20,20,"\n Screen mode: Wrap");
	}
	if(bounce)
	{
		g.DrawString(20,20,"\n Screen mode: Wall Bounce");
	}
	if(artbounce)
	{
	wall.Draw(g,Vector2d(0,0));
	g.DrawString(20,20,"\n Screen mode:Arbitrary Wall Bounce");
	}
	party.draw(g);
	}
	g.SetColor(RGB(255,255,255));
	
}

void Spaceship::artWallBounce()
{
	for(int i=0;i<4;i++)
	{
	Vector2d temp=position-wallpoints[i];
	Vector2d temp2= nextposition - wallpoints[i];
	Vector2d walls=wallpoints[i+1%numwalls]-wallpoints[i];
	Vector2d perp=perpccw(walls);
	float next=dotproduct(normalize(perp),temp);
	float current=dotproduct(normalize(perp),temp2);
	
	if(current < 0)
	{
		if(next>0)
		{
		wallResponse(normalize(perp));
		}
	}
	}
}
void Spaceship::wallResponse(Vector2d perp)
{
	Spaceship::velocity=velocity-(2 *dotproduct(velocity,perp)*perp);
}

void Spaceship::WallBounce(Vector2d position)
{
	if(position.x >= 1920)
	{
		Spaceship::velocity=Vector2d(-1*Spaceship::velocity.x,Spaceship::velocity.y);
	}
	if(position.x <= 0)
	{
		Spaceship::velocity=Vector2d(-1*Spaceship::velocity.x,Spaceship::velocity.y);
	}
	if(position.y >= 1040)
	{
		Spaceship::velocity=Vector2d(Spaceship::velocity.x,-1* Spaceship::velocity.y);
	}
	if(position.y <= 0)
	{
		Spaceship::velocity=Vector2d(Spaceship::velocity.x,-1* Spaceship::velocity.y);
	}
}
void Spaceship::Update(float dt)
{
	if(!gameOver)
	{
	if(Core::Input::IsPressed('1'))
		{
			wrap=true;
			bounce=false;
			artbounce=false;
			
		}
	if(Core::Input::IsPressed('2'))
		{
			bounce=true;
			wrap=false;
			artbounce=false;
			
		}
	if(Core::Input::IsPressed('3'))
		{
		    bounce=false;
			wrap=false;
			artbounce=true;	
		}
	if(wrap)
	{
	Wrapship(Spaceship::position);
	}
	if(bounce)
	{
	WallBounce(Spaceship::position);
	}
	if(artbounce)
	{
	artWallBounce();
	}
	   if(Core::Input::IsPressed('D'))
		{
			angle+=8.0f*dt;

		}
		if(Core::Input::IsPressed('A'))
		{
			angle-=8.0f*dt;
		}
		if(Core::Input::IsPressed('W'))
		{
			Matrix3 temp=temp.rotate(angle);
			Vector2d vel=(0,-4*dt);
			velocity=velocity+(temp*vel);
		}
		if(Core::Input::IsPressed('S'))
		{
			Matrix3 temp=temp.rotate(angle);
			Vector2d vel=(0,4*dt);
			velocity=velocity+(temp*vel);
		}
		else{
        velocity=dragCoeff*velocity;
		}
		party.createEffect(3,2,position,5);
		position=position+(velocity);
		nextposition=position+(velocity);
		party.update(dt);
		party.deleteparts(dt);
	}
		
}