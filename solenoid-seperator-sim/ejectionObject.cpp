#include "ejectionObject.h"

// constructor, takes: object mass[kg], object COM[m] relative to end of solenoid
ejectionObject::ejectionObject(float obj_mass, float obj_com) {
	mass = obj_mass;
	com = obj_com;
	xpos = com;
	velocity = 0;
}

// updates the xpos due to applied force, takes: force[N], timestep[s]
void ejectionObject::setPos(float force, float timestep) {
	calcPos(force, timestep);
}

// calculates the new position of the object due to an applied force, takes: force[N], timestep[s]
void ejectionObject::calcPos(float force, float timestep) {
	velocity = velocity + force * timestep / mass;
	xpos = xpos + velocity * timestep;
}

// updates the sim with the objects new position
float ejectionObject::getPos() {
	return xpos;
}