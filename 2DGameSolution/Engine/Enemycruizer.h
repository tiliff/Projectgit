#include "Core.h"
#include "ParticleSystem.h"

class enemyCruizer
{
	public:
	Vector2d position;
	Vector2d velocity;
	Vector2d newvelocity;
	Vector2d newposition;
	bool hit;
	int numTimesHit;
	bool dead;
	float angle;
	int numhitstotake;
	bool shipSpawn;
	bool gameOver;
	enemyCruizer();
	~enemyCruizer()
    { 
	delete this;
    }
	bool CheckGame();
	void draw(Core::Graphics& g);
	void update(float dt,Vector2d shippos,Vector2d bulletpos);
};

