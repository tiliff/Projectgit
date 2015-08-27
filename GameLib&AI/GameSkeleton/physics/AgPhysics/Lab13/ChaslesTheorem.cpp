#include "ChaslesTheorem.h"
#include <glm\gtx\perpendicular.hpp>

QPushButton* throwStuff;
QPushButton* ResetStuff;
DebugSlider* StuffRadius;
DebugSlider* ThrowStuffSpeed;
DebugSlider* angvel;
QCheckBox* sameparticles;

ChaslesTheorem::ChaslesTheorem(void)
{
}

ChaslesTheorem::ChaslesTheorem(QPushButton& Throw,QPushButton& reset,DebugSlider& partsRadius,DebugSlider& ThrowSpeed,DebugSlider& angularvelocity,QCheckBox& sameParts)
{
	throwStuff= &Throw;
	ResetStuff= &reset;
	StuffRadius= &partsRadius;
	ThrowStuffSpeed = &ThrowSpeed;
	angvel = &angularvelocity;
	sameparticles = &sameParts;
}

void ChaslesTheorem::initialize()
{
	GuiBase::initialize(false, true);
	systemOrigin = glm::vec3(0.0f, 0.0f, 0.0f);
	systemVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
	radius = 1.5f;
	angularVel = 2.0f;
	sameRadius = true;
	throwSpeed = 0.0f;
	isThrown = false;
	totalInertia = 1.0f;


	/*float angleBetween = 360 / (sizeof(container)/sizeof(*container));*/
	resetSystem();

	for(int i = 0; i < sizeof(container)/sizeof(*container); i++)
	{
		/*container[i].systemParticle.mass = 0.5f;

		container[i].systemParticle.position = glm::rotate(glm::vec3(0.0f, 1.0f, 0.0f), i*angleBetween, glm::vec3(0.0f, 0.0f, 1.0f));
		container[i].radiusPercentage = rand()%3 + 1;*/

		//Particle Graphic
		container[i].ParticleGraphic = addVectorGraphic();
		container[i].ParticleGraphic->b = 255;
		container[i].ParticleGraphic->pointSize = container[i].systemParticle.mass;

		//Blue Vector
		container[i].blueVector = addVectorGraphic();
		container[i].blueVector->b = 255;
		container[i].blueVector->displayStyle = DS_ARROW;

		////Green Vector
		//container[i].greenVector = addVectorGraphic();
		//container[i].greenVector->color = glm::vec3(0.0f, 1.0f, 0.0f);
		//container[i].greenVector->displayStyle = DS_ARROW;

		//Red Vector
		container[i].redVector = addVectorGraphic();
		container[i].redVector->r = 255;
		container[i].redVector->displayStyle = DS_ARROW;

		//container[i].initialParticlePosition = container[i].systemParticle.position;
	}

	//Force Vector
	forceVector = addVectorGraphic();
	forceVector->g = 255;
	forceVector->b = 255;
	forceVector->displayStyle = DS_ARROW;

	//Green Vector
	greenVector = addVectorGraphic();
	greenVector->g = 255;
	greenVector->displayStyle = DS_ARROW;
	
	blackVector = addVectorGraphic();
	blackVector->r = 0;
	blackVector->g = 0;
	blackVector->b = 0;
	blackVector->displayStyle = DS_ARROW;
}

void ChaslesTheorem::updateLever()
{
	if(GetAsyncKeyState(VK_RBUTTON))
	{
		leverPos =  systemVelocity;
		leverForce = glm::vec3(0.0f, 0.0f, 0.0f);
		perpForce = glm::vec3(0.0f, 0.0f, 0.0f);
	}

	if(GetAsyncKeyState(VK_LBUTTON) && leverPos != glm::vec3(0.0f, 0.0f, 0.0f))
	{
		leverForce =  systemVelocity - leverPos;
		perpForce = glm::perp(leverForce, glm::normalize(leverPos));
		torqueMag = glm::length(perpForce);
	}
}

void ChaslesTheorem::newFrame()
{
	updateLever();
	sameRadius = sameparticles->isChecked();
	
	glm::vec3 totalTorque = glm::cross(leverPos, leverForce);
	
	glm::vec3 angularAcceleration = (totalTorque / totalInertia) * dt();
	angularVel += angularAcceleration.z;

	totalInertia = 0.0f;

	systemOrigin += systemVelocity * dt();
	for(int i = 0; i < sizeof(container)/sizeof(*container); i++)
	{
		glm::vec3 diff = container[i].systemParticle.Position - systemOrigin;
		glm::vec3 Rperp = glm::vec3(-diff.y, diff.x, diff.z);
		glm::vec3 newAngularVelocity = angvel->value() * Rperp;
		container[i].systemParticle.Velocity = newAngularVelocity + systemVelocity;
		container[i].systemParticle.Position += container[i].systemParticle.Velocity * dt();
		if(GetAsyncKeyState('w'))
		{
			systemOrigin += systemVelocity * dt();
		}
		if(sameRadius) {
			container[i].systemParticle.Position = (glm::normalize(container[i].systemParticle.Position - systemOrigin) * radius) + systemOrigin;
		} else {
			container[i].systemParticle.Position = (glm::normalize(container[i].systemParticle.Position - systemOrigin) * (radius * container[i].radiusPercentage)) + systemOrigin;
		}

		totalInertia += (glm::dot(container[i].systemParticle.Position, container[i].systemParticle.Position)) * container[i].systemParticle.mass;

		sync(container[i].blueVector, container[i].systemParticle.Position-systemOrigin, systemOrigin);
		sync(container[i].redVector, newAngularVelocity, container[i].systemParticle.Position);
		sync(container[i].ParticleGraphic, container[i].systemParticle.Position);
	}

	
	sync(greenVector, perpForce, leverPos);
	sync(blackVector, systemVelocity, systemOrigin);
	sync(forceVector, leverForce, leverPos);
}

void ChaslesTheorem::resetSystem()
{
	systemOrigin = glm::vec3(0.0f, 0.0f, 0.0f);
	systemVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
	radius = 1.5f;
	angularVel = 2.0f;
	sameRadius = true;
	isThrown = false;
	totalInertia = 1.0f;

	float angleBetween = 360 / (sizeof(container)/sizeof(*container));
	for(int i = 0; i < sizeof(container)/sizeof(*container); i++)
	{
		container[i].systemParticle.mass = 0.5f;

		container[i].systemParticle.Position = glm::rotate(glm::vec3(0.0f, 1.0f, 0.0f), i*angleBetween, glm::vec3(0.0f, 0.0f, 1.0f));
		container[i].radiusPercentage = rand()%3 + 1;
	}

	leverPos = glm::vec3(0.0f, 0.0f, 0.0f);
	leverForce = glm::vec3(0.0f, 0.0f, 0.0f);
	perpForce = glm::vec3(0.0f, 0.0f, 0.0f);
}



int throwDelay = 0;
void ChaslesTheorem::throwSystem()
{
	if(throwDelay <= 0)
	{
		throwDelay = 9;
		isThrown = true;
		throwDirection = rand()%4;
		if(throwDirection == 0)
		{
			systemVelocity = glm::vec3(throwSpeed, throwSpeed, 0.0f);
		}
		if(throwDirection == 1)
		{
			systemVelocity = glm::vec3(-throwSpeed, throwSpeed, 0.0f);
		}
		if(throwDirection == 2)
		{
			systemVelocity = glm::vec3(throwSpeed, -throwSpeed, 0.0f);
		}
		if(throwDirection == 3)
		{
			systemVelocity = glm::vec3(-throwSpeed, -throwSpeed, 0.0f);
		}

		systemVelocity = throwSpeed * glm::normalize(glm::vec3(rand() - RAND_MAX/2, rand() - RAND_MAX/2,0));

		sync(blackVector, systemVelocity, systemOrigin);
	}
	throwDelay--;
}
