#include "coil.h"

// constructor, takes: the radius of the coil[m], and the x position of the coil[m]
coil::coil(float set_radius, float set_current) {
	current = set_current;
	radius = set_radius;
}

// returns the force acting on a point charge at a given x position[m]
float coil::getForce(float set_xpos, float test_xpos) {
	return force(set_xpos, test_xpos);
}

// updates the current through the coil, as the supply voltage changes
void setCurrent(float new_current) {
	current = new_current;
}

// calculates the force on the x axis at given point from this coil, takes test xpos[m]
float coil::force(float set_xpos, float test_xpos) {
	float mu = 1.26E-6; // permability of free space
	coil_xpos = set_xpos;
	float distance = test_xpos - coil_xpos;
	float radius_squared = pow(radius, 2);
	float distance_squared = pow(distance, 2);
	float denominator = pow(radius_squared + distance_squared, 1.5);
	return (mu * current * radius_squared) / (2 * denominator);
}