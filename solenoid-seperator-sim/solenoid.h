#ifndef SOLENOID_H
#define COIL_H

#include "coil.h"

class solenoid
{

private:

	float coil_resistance, total_resistance, radius, length, voltage;
	int coil_count;
	float resistivity = 1.7E-8;
	float wire_area = 1.26E-7;

	// calculates the resistance of a single coil, and then calculates the total resistance of the circuit
	void calcResistance(void);

	// using the total resistance of the circuit and the supplied voltage, calculates the current through each coil
	void calcCurrent(void);

	// sums the force on the test point from each coil, takes: the xpos of the test point
	float totalForce(float);

public:

	// constructor which creates a test coil, takes: the radius of each coil[m], the number of coils, the length of the solenoid[m], the supplied voltage[V]
	solenoid(float, float, float, float);

	// destructor, which deletes the allocated memory for the coil
	~solenoid();

	// returns the total force on a point charge at a given x position[m]
	float getTotalForce(float);

	// sets the new voltage through the solenoid, as the capacitor discharges, takes: voltage supplied[V]
	void setVoltage(float);

	// returns the total resistance of the solenoid
	float getResistance(void);
};

#endif