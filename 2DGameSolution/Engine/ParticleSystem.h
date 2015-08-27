#pragma once 
#include <vector>
#include "ParticleEffect.h"
using std::vector;


class ParticleSystem
{
public:
	ParticleSystem()
	{
	}
	void update(float dt);
	void draw(Core::Graphics&);
	void createEffect(int size,int type,Vector2d origin,int numParticles);
	Vector2d GetparticletoExplode();
	void deleteparts(float dt);
};