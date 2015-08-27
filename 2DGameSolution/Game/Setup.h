#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include "Engine.h"
#include"Spaceship.h"
#include "Lerp.h"
#include "Turret.h"
#include "Planets.h"
#include "time.h"
#include "Profile.h"
#include "Profiler.h"
#include "EnemyShipController.h"
#include "Logger.h"
bool setup=true;
int Score=0;
float times;
CStopWatch myTimer;
_CrtMemState state;
using Core::Input;
Shipcontroller enemies;
randomness rands;
Vector2d shipPoints[]=
{
	Vector2d(-103,-1),
	Vector2d(-103,15),
	Vector2d(-57,38),
	Vector2d(-26,42),
	Vector2d(-12,26),
	Vector2d(7,20),
	Vector2d(14,24),
	Vector2d(14,33),
	Vector2d(7,33),
	Vector2d(-2,40),
	Vector2d(-7,48),
	Vector2d(-9,55),
	Vector2d(0,71),
	Vector2d(8,78),
	Vector2d(14,77),
	Vector2d(105,76),
	Vector2d(105,80),
	Vector2d(122,72),
	Vector2d(121,39),
	Vector2d(107,32),
	Vector2d(107,34),
	Vector2d(41,34),
	Vector2d(41,18),
	Vector2d(53,17),
	Vector2d(52,1),
	Vector2d(53,-17),
	Vector2d(41,-18),
	Vector2d(41,-34),
	Vector2d(107,-34),
	Vector2d(107,-32),
	Vector2d(121,-39),
	Vector2d(122,-72),
	Vector2d(105,-80),
	Vector2d(105,-76),
	Vector2d(14,-77),
	Vector2d(8,-78),
	Vector2d(0,-71),
	Vector2d(-9,-55),
	Vector2d(-7,-48),
	Vector2d(-2,-40),
	Vector2d(7,-33),
	Vector2d(14,-33),
	Vector2d(14,-24),
	Vector2d(7,-20),
	Vector2d(-12,-26),
	Vector2d(-26,-42),
	Vector2d(-57,-38),
	Vector2d(-103,-15),
	Vector2d(-103,-1)
};
Vector2d lerpship[]=
{
	Vector2d(0,5),
	Vector2d(5,0),
	Vector2d(0,-5),
	Vector2d(-5,0),
	Vector2d(0,5)
};
Vector2d turretpoints[]=
{
	Vector2d(0 , 0),
	Vector2d(0 ,-1),
	Vector2d(3 ,-1),
	Vector2d(3 , 0),
	Vector2d(4 , 0),
	Vector2d(4 ,-3),
	Vector2d(3 ,-3),
	Vector2d(3 ,-2),
	Vector2d(-2,-2),
	Vector2d(-2,-1),
	Vector2d(-2, 2),
	Vector2d(3 , 2),
	Vector2d(3 , 3),
	Vector2d(4 , 3),
	Vector2d(4 , 0),
	Vector2d(3 , 0),
	Vector2d(3 , 1),
	Vector2d(0 , 1),
	Vector2d(0 , 0)
};
Vector2d* t= turretpoints;
int numturlines = (int)(sizeof(turretpoints)/sizeof(*turretpoints))-1;
int numlinesship=sizeof(shipPoints)/sizeof(*shipPoints)-1;
Vector2d* lerpoutline=lerpship;
Lerper lerpee(4,lerpoutline);
Vector2d* p= shipPoints;
Spaceship player(numlinesship,p,Vector2d(1920/2,1080/2));
Turret tur(numturlines,t,player.position);
Planets plan;


  


bool MeUpdateFn(float dt)
{
	_CrtMemCheckpoint(&state);
	state.lCounts[_CLIENT_BLOCK];
	times=(float)(1/myTimer.getElapsedTime());
	myTimer.startTimer();
	if(!setup)
	{
	if(!enemies.checkGame())
	{
	LOG(Info,"Update Function run");
	{
	PROFILE("Ship Update");
	player.Update(dt);
	}
	{
	PROFILE("Lerp Update");
	lerpee.Update(dt);
	}
	{
	PROFILE("turret Update");
	tur.updatepos(dt,player.position);
	}
	
	{
	PROFILE("planets update");
	plan.updateplanets(dt);
	}
	for(int i=0;i<20;i++)
	{
	enemies.update(dt,player.position,tur.GetBulPos(i));
	}
	if(Input::IsPressed(Input::KEY_ESCAPE))
	{
		return true;
	}
	LOG(Info,"Draw Function Complete");
	}
	}
	return false;
}

void MeDrawFn(Core::Graphics& graphics)
{
	if(setup)
	{
		graphics.SetColor(RGB(rands.randomInRange(0,255),rands.randomInRange(0,255),rands.randomInRange(0,255)));
		graphics.DrawString(955,100,"Destroyer!");
		graphics.SetColor(RGB(255,255,255));
		graphics.DrawString(955,520,"Instructions \n W,A,S,D are used to move\n Mouse Aims the turret \n The left click fires bullets\n The object is to stay alive as long as possible\n press the spacebar to continue to the game");
		if(Core::Input::IsPressed(VK_SPACE))
		{
			setup=false;
		}
	}
	if(!setup)
	{
	if(!enemies.checkGame())
	{
	Score+=1;
	std::stringstream ss;
    ss << "Score: " << Score;

	LOG(Info,"Draw Function run");
	profiling::Profiler::getInstance().newFrame();
	char buf[50];
	sprintf_s(buf,"%f",times);
	{
    PROFILE("Ship Draw");
	player.Draw(graphics);
	}
	{
	PROFILE("Lerp Draw");
	lerpee.Draw(graphics);
	}
	{
	PROFILE("Turret Draw");
	tur.Draw(graphics);
	}
	{
	PROFILE("Planets Draw");
	plan.drawplanets(100,Matrix3::translate(1920,1080),graphics);
	}
	graphics.DrawString(1700,10,ss.str().c_str());
	//graphics.DrawString(1710,10,test);
	enemies.draw(graphics);
	LOG(Info,"Draw Function Complete");
	}
	}
	if(enemies.checkGame())
	{
		std::stringstream ss;
        ss << "Your Final Score: " << Score;
		graphics.DrawString(945,520,"You have been destroyed");
		graphics.DrawString(945,530,ss.str().c_str());
	}
}