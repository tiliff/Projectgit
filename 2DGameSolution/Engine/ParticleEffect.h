#pragma once
#include "Particle.h"
#include "particlemath.h"
#include "color.h"

class particleEffect
{
public:
	Particle* particles;
	int numberParticles;
	Vector2d startpos;
	colorness color;
	randomness ryan;
	

	particleEffect(int size,int type,Vector2d origin,int numParticles)
	{
		numberParticles=numParticles;
		startpos=origin;
		particles=new Particle[numberParticles];

		for(int i=0;i<numberParticles;i++)
		{
			particles[i].type=type;
			if(type==1)
			{
				particles[i].position=origin;
				particles[i].velocity=ryan.randomInRange(100,200) * ryan.RandomUnitVector();
				particles[i].color=RGB(ryan.randomInRange(0,255),ryan.randomInRange(0,255),ryan.randomInRange(0,255));
				particles[i].lifetime=ryan.randomInRange(1.0f,2.0f);

			}
			if(type==2)
			{
				particles[i].size=size;
				particles[i].position=Vector2d(ryan.randomInRange(0,1910),ryan.randomInRange(0,1040));
				particles[i].color=RGB(ryan.randomInRange(0,255),ryan.randomInRange(0,255),ryan.randomInRange(0,255));
				particles[i].color=color.brightness(particles[i].color,ryan.randomInRange(0,1));
				particles[i].lifetime=(1.0f,4.0f);

			}
		}
	}
	particleEffect()
	{
	}
	~particleEffect()
	{
		delete [] particles;
	}
	bool update(float dt);
	void draw(Core::Graphics& g);
};