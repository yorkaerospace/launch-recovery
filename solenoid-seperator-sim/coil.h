#ifndef COIL_H
#define COIL_H

#include <cmath>

class coil
{
private:

	float current, radius, coil_xpos;
	
	// calculates the force on the x axis at given point from this coil, takes: the xpos of this coil, and the xpos of the test point
	float force(float, float);

public:
	
	// constructor, takes: the radius of the coil[m],  and the current through the coil
	coil(float, float);

	
	// returns the force acting on a point charge, takes: the xpos of this coil, and the xpos of the test point
	float getForce(float, float);

	// updates the current through the coil, as the supply voltage changes
	void setCurrent(float);
};

#endif