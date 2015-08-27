#include "EnemyShipController.h"

Shipcontroller::Shipcontroller()
{
	ships=new EnemyShip[10];
	ship=new enemyCruizer[3];
}
void Shipcontroller::draw(Core::Graphics& g)
{
	
	for(int i=0;i<10;i++)
	{
      ships[i].draw(g);
	}
	for (int j = 0; j < 3; j++)
	{
		ship[j].draw(g);
	}
}
Shipcontroller::~Shipcontroller()
{
	delete ships;
	delete ship;
}
void Shipcontroller::update(float dt,Vector2d shippos,Vector2d bulletpos)
{
	for(int i=0;i<10;i++)
	{
      ships[i].update(dt,shippos,bulletpos);
	}
	for (int j = 0; j < 3; j++)
	{
		ship[j].update(dt,shippos,bulletpos);
	}
}
bool Shipcontroller::checkGame()
{
	bool ret=false;
	for(int i=0;i<10;i++)
	{
      if(ships[i].CheckGame())
	  {
       return true;
	  }
	}
	for (int j = 0; j < 3; j++)
	{
		if(ship[j].CheckGame())
		{
			return true;
		}
	}
	return ret;
}