#pragma once
#include "Vector2d.h"
#include "Core.h"
#include "Enemyship.h"
#include "enemyCruizer.h"

class Shipcontroller
{
public:
	EnemyShip* ships;
	enemyCruizer* ship;
	Shipcontroller();
	~Shipcontroller();
	bool gameOver;
	void draw(Core::Graphics& g);
	void update(float dt,Vector2d shippos,Vector2d bulletpos);
	bool checkShips(int numshipcheck);
	void waveSetup(int numshipRevive);
	bool checkGame();
};