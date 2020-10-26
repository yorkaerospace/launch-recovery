#ifndef EJECTIONOBJECT_H
#define EJECTIONOBJECT_H

class ejectionObject
{

private:

	float mass, com, xpos, velocity;
	float magnitivity = 0.1; 		// FIND A NUMBER FOR THIS

	// calculates the new position of the object due to an applied force, takes: force[N], timestep[s]
	void calcPos(float, float);

	// updates the sim with the objects new position
	float getPos(void);


public:

	// constructor, takes: object mass[kg], object COM[m] relative to end of solenoid
	ejectionObject(float, float);

	// updates the xpos due to applied force, takes: force[N], timestep[s]
	void setPos(float, float);

};

#endif