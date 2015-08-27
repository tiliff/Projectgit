#include "RestingContacts.h"
#include <sstream>

QPushButton* Reset;
void RestingContactsLab::reset()
{
	towerDestroyer.Position = glm::vec3(-4.5f, 2.0f, 0.0f);
	towerDestroyer.Velocity = glm::vec3(5.0f, -0.055f, 0.0f);
	towerDestroyer.clearForces();
	for(int i = 0; i < sizeof(tower)/sizeof(*tower); i++)
	{
		tower[i].Position = glm::vec3(0.0f, (i+.9) * 1.1, 0.0f);
		tower[i].Velocity = glm::vec3(0.0f, 0.0f, 0.0f);
		tower[i].clearForces();
	}
}
RestingContactsLab::RestingContactsLab(QPushButton& reset)
{
	Reset = &reset;
}
void RestingContactsLab::initialize()
{
	GuiBase::initialize(false, true);

	gravity = glm::vec3(0.0f, -3.0f, 0.0f);
	grav = glm::vec3(0.0f,-0.1f,0.0f);
	restitution = 0.9f;


	//Tower Destroyer Particle Graphic
	destroyerGraphic = addVectorGraphic();
	destroyerGraphic->g = 255;
	towerDestroyer.Position = glm::vec3(-4.5f, 2.0f, 0.0f);
	towerDestroyer.Velocity = glm::vec3(5.0f, -0.155f, 0.0f);
	towerDestroyer.mass = 1.0f;
	towerDestroyer.Damper = 1.0f;

	for(int i = 0; i<sizeof(tower)/sizeof(*tower); i++)
	{
		towerGraphs[i] = addVectorGraphic();
		towerGraphs[i]->r = 255;
		tower[i].Position = glm::vec3(0.0f, (i+.9)*1.1, 0.0);
		tower[i].mass = 1.0f;
		tower[i].Damper = 1.0f;
		registry.add(&tower[i], &gravity);
	}
	registry.add(&towerDestroyer, &grav);
}


void RestingContactsLab::newFrame()
{

	if(Reset->isDown())
	{
		reset();
	}
	contact.restitution = restitution;
	floorContact.restitution = restitution;

	for(int i = 0; i < sizeof(tower)/sizeof(*tower); i++)
	{
		float collisionLength = (towerDestroyer.mass * 0.5f + tower[i].mass * 0.5f);
		if(glm::length((tower[i].Position - towerDestroyer.Position)) <= collisionLength)
		{
			ParticleContact ballToTower;
			ballToTower.setParticles(glm::normalize(towerDestroyer.Position - tower[i].Position),restitution,&towerDestroyer,&tower[i]);
			ballToTower.penetration = collisionLength - glm::length(tower[i].Position - towerDestroyer.Position);
			contactVec.push_back(ballToTower);
		}

		int nextTowerPiece = i+1;
		if(nextTowerPiece < sizeof(tower)/sizeof(*tower))
		{
			float collisionLength = (tower[i].mass * 0.5f + tower[nextTowerPiece].mass * 0.5f);
			if(glm::length((tower[nextTowerPiece].Position - tower[i].Position)) <= collisionLength)
			{
				ParticleContact towerToTower;
				towerToTower.setParticles(glm::normalize(tower[i].Position - tower[nextTowerPiece].Position),restitution,&tower[i],&tower[nextTowerPiece]);
				towerToTower.penetration = collisionLength - glm::length(tower[nextTowerPiece].Position - tower[i].Position);
				contactVec.push_back(towerToTower);
			}
		}


		float floorPenPoint = tower[i].mass * 0.5f;

		if(glm::length(tower[i].Position - glm::vec3(tower[i].Position.x, 0.0f, 0.0f)) <= floorPenPoint)
		{
			ParticleContact towerToFloor;
			towerToFloor.setParticles(glm::normalize(tower[i].Position - glm::vec3(tower[i].Position.x, 0.0f, 0.0f)),restitution,&tower[i],NULL);
			towerToFloor.penetration = floorPenPoint - glm::length(tower[i].Position - glm::vec3(tower[i].Position.x, 0.0f, 0.0f));
			contactVec.push_back(towerToFloor);
		}

		tower[i].Acceleration = tower[i].SumofForces / tower[i].mass;
		tower[i].Velocity = (tower[i].Velocity * tower[i].Damper) + tower[i].Acceleration * dt();
		tower[i].Position += tower[i].Velocity * dt();

		sync(towerGraphs[i], tower[i].Position);
		tower[i].clearForces();
	}


	
	float floorPenPoint = towerDestroyer.mass * 0.5;
	if(glm::length(towerDestroyer.Position - glm::vec3(towerDestroyer.Position.x, 0.0f, 0.0f)) <= floorPenPoint)
	{
		ParticleContact destroyerToFloor;
		destroyerToFloor.setParticles(glm::normalize(towerDestroyer.Position - glm::vec3(towerDestroyer.Position.x, 0.0f, 0.0f)),restitution,&towerDestroyer,NULL);
		destroyerToFloor.penetration = floorPenPoint - glm::length(towerDestroyer.Position - glm::vec3(towerDestroyer.Position.x, 0.0f, 0.0f));
		contactVec.push_back(destroyerToFloor);
	}

	towerDestroyer.Acceleration = towerDestroyer.SumofForces / towerDestroyer.mass;
	towerDestroyer.Velocity = (towerDestroyer.Velocity * towerDestroyer.Damper) + towerDestroyer.Acceleration * dt();
	towerDestroyer.Position += towerDestroyer.Velocity * dt();


	registry.updateForces(dt());
	if(contactVec.size() != 0)
	{
		resolver.resolveContacts(&contactVec[0], contactVec.size(), dt());
	}
	contactVec.clear();
	sync(destroyerGraphic, towerDestroyer.Position);
}