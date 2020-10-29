#ifndef SOLENOID_H
#define SOLENOID_H

#include <cmath>

class solenoid
{

private:

	float ring_resistance, total_resistance, radius, length, voltage, current;
	int ring_count;
	float resistivity = 1.7E-8;
	float wire_area = 1.26E-7;

	// calculates the resistance of a single ring, and then calculates the total resistance of the circuit
	void calcResistance(void);

	// using the total resistance of the circuit and the supplied voltage, calculates the current through each ring
	void calcCurrent(void);

	// sums the force on the test point from each ring, takes: the xpos of the test point
	float totalForce(float);

	// calculates the force on the test mass from a single ring in the solenoid, at a given xpos
	float ringForce(float, float);

public:

	// constructor which creates a test ring, takes: the radius of each ring[m], the number of rings, the length of the solenoid[m], the supplied voltage[V]
	solenoid(float, float, float, float);

	// returns the total force on a point charge at a given x position[m]
	float getTotalForce(float);

	// sets the new voltage through the solenoid, as the capacitor discharges, takes: voltage supplied[V]
	void setVoltage(float);

	// returns the total resistance of the solenoid
	float getResistance(void);
};

#endif