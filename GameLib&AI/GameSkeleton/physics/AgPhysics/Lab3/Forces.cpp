#include "Forces.h"
#include <Qt\qdebug.h>
#include "Windows.h"

QPushButton* res;

Forces::Forces(QPushButton &reset){
	res=&reset;
}

void Forces::initialize()
{
	GuiBase::initialize(false, true);
	pg=ParticleGravity(glm::vec3(0.0f,-1.0f,0.0f));
	kweef=KeyForce(glm::vec3(0.0f,2.0f,0.0f));

	grav= addVectorGraphic();
	grav->g=255;
	gravp.Position=glm::vec3(-2.0f,0.0f,0.0f);
	gravp.mass=1.0f;

	keygraphic= addVectorGraphic();
	keygraphic->r=255;
	keygraphic->g=200;
	keyp.Position=glm::vec3(2.0f,0.0f,0.0f);
	keyp.mass=1.0f;

    multiple= addVectorGraphic();
	multiple->b=255;
	multip.Position=glm::vec3(0.0f,0.0f,0.0f);
	multip.mass=1.0f;

	pfr.add(&gravp,&pg);
	pfr.add(&keyp,&kweef);
	pfr.add(&multip,&pg);
	pfr.add(&multip,&kweef);
}
void Forces::newFrame()
{
	pfr.updateForces(dt());

	gravp.Acceleration = gravp.SumofForces/gravp.mass;
	gravp.Velocity += gravp.Acceleration * dt();
	gravp.Position+= gravp.Velocity * dt();
	gravp.clearForces();
    

	multip.Acceleration = multip.SumofForces/multip.mass;
	multip.Velocity += multip.Acceleration * dt();
	multip.Position+= multip.Velocity * dt();
	multip.clearForces();
    

	keyp.Acceleration = keyp.SumofForces/keyp.mass;
	keyp.Velocity += keyp.Acceleration * dt();
	keyp.Position+= keyp.Velocity * dt();
	keyp.clearForces();

	if(res->isDown())
	{
		gravp.Position=glm::vec3(-2.0f,0.0f,0.0f);
		keyp.Position=glm::vec3(2.0f,0.0f,0.0f);
		multip.Position=glm::vec3(0.0f,0.0f,0.0f);
		gravp.Velocity=glm::vec3();
		keyp.Velocity=glm::vec3();
		multip.Velocity=glm::vec3();
		gravp.clearForces();
		keyp.clearForces();
		multip.clearForces();
	}

	sync(grav,gravp.Position);
	sync(multiple,multip.Position);
	sync(keygraphic,keyp.Position);
}

