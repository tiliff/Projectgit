#include "ParticleContacts.h"

ParticleContactResolver::ParticleContactResolver()
{}

void ParticleContactResolver::resolveContacts(ParticleContact * contactArray, unsigned int numContacts, float duration)
{
	//unsigned int i;
	iterationsUsed = 0;
	iterations = numContacts;
	/*while(iterationsUsed < iterations)
	{
		float max = FLT_MAX;
		unsigned int maxIndex = numContacts;
		for(unsigned int i = 0; i < numContacts; i++)
		{
			float sepVelocity = contactArray[i].calculateSeperatingVelocity();
			if(sepVelocity < max && (sepVelocity < 0 || contactArray[i].penetration > 0))
			{
				max = sepVelocity;
				maxIndex = i;
			}
		}

		if(maxIndex == numContacts) break;

		contactArray[maxIndex].resolve(duration);
		iterationsUsed++;
	}*/

	for(unsigned int i = 0; i < iterations; i++)
	{
		//float sepVelocity = contactArray[i].calculateSeperatingVelocity();
		contactArray[i].resolve(duration);
	}
}