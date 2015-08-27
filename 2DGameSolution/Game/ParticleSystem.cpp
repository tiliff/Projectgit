#include "ParticleSystem.h"


const int MAX_EFFECTS=50;
particleEffect* effectArray[ MAX_EFFECTS ] = {};
unsigned int numActiveEffects = 0;

void ParticleSystem::createEffect(int size,int type,Vector2d origin,int numParticles)
{
if( numActiveEffects < MAX_EFFECTS )
{
particleEffect* pEffect = new particleEffect(size,type,origin,numParticles);
effectArray[ numActiveEffects++ ] = pEffect;
}
}
void ParticleSystem::update(float dt)
{
	for (unsigned int i=0; i<numActiveEffects; i++)
{
	if (effectArray[i] != NULL )
		effectArray[i]->update(dt);
}
}
void ParticleSystem::draw(Core::Graphics& g)
{
	for (unsigned int i=0; i<numActiveEffects; i++)
{
	if (effectArray[i] != NULL )
		effectArray[i]->draw(g);
}
}
void ParticleSystem::deleteparts(float dt)
{
	for (int i=numActiveEffects-1; i>=0; i--)
{
	if (effectArray[i] != NULL )
{
		if ( !effectArray[i]->update(dt) )
		{
			delete effectArray[i];
			for (unsigned j=i; j<numActiveEffects-1; j++)
			{
				effectArray[j] = effectArray[j+1];
			}
			numActiveEffects--;
		}
	}
}

}