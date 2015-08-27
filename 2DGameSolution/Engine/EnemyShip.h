#pragma once
#include "Vector2d.h"
#include "Core.h"
#include "particlemath.h"
#include "Particlesystem.h"

static const int NUM_ENEMIES=15;
static float spawnrate=50.0f;
class EnemyShip
{
public:
	Vector2d position;
	Vector2d velocity;
	Vector2d newvelocity;
	Vector2d newposition;
	bool gameOver;
	bool hit;
	bool dead;
	float angle;
	EnemyShip();
	void draw(Core::Graphics& g);
	void update(float dt,Vector2d shippos,Vector2d bulletpos);
	bool CheckGame();
};
