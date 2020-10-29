#include "solenoid.h"

// constructor which creates an array of rings, takes: the radius of each ring[m], the number of rings, the length of the solenoid[m], the supplied voltage[V]
solenoid::solenoid(float set_radius, float set_ring_count, float set_length, float set_voltage) {
	radius = set_radius;
	ring_count = set_ring_count;
	length = set_length;
	voltage = set_voltage;

	calcResistance();
	calcCurrent();
}	

// returns the total force on a point charge at a given x position[m]
float solenoid::getTotalForce(float test_xpos) {
	return totalForce(float test_xpos);
}

// sets the new voltage through the solenoid as the capacitor discharges, takes: voltage supplied[V]
void solenoid::setVoltage(float new_voltage) {
	voltage = new_voltage;
	calcCurrent();
}

// calculates the resistance of a single ring, and then calculates the total resistance of the circuit
void solenoid::calcResistance() {
	ring_resistance = resistivity * 2 / radius;
	total_resistance = ring_resistance * ring_count;
}

// using the total resistance of the circuit and the supplied voltage, calculates the current through each ring
void solenoid::calcCurrent() {
	current = voltage / total_resistance;
}

// sums the force on the test point from each ring, takes: the xpos of the test point
float solenoid::totalForce(float test_xpos) {
	float total_force;
	for (int i = 0; i < ring_count; i++) {
		float ring_xpos = length * i / ring_count;
		float i_force = ringForce(ring_xpos, test_xpos);
		total_force += i_force;
	}
	return total_force;
}

// returns the total resistance of the solenoid
float solenoid::getResistance() {
	return total_resistance;
}

// calculates the force on the test mass from a single ring in the solenoid, at a given xpos
float solenoid::ringForce(float ring_xpos, float test_xpos) {
	float mu = 1.26E-6; // permability of free space
	float distance = test_xpos - ring_xpos;
	float radius_squared = pow(radius, 2);
	float distance_squared = pow(distance, 2);
	float denominator = pow(radius_squared + distance_squared, 1.5);
	return (mu * current * radius_squared) / (2 * denominator);
}

