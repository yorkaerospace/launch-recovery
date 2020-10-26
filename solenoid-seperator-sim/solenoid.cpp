#include "solenoid.h"

// constructor which creates an array of coils, takes: the radius of each coil[m], the number of coils, the length of the solenoid[m], the supplied voltage[V]
solenoid::solenoid(float set_radius, float set_coil_count, float set_length, float set_voltage) {
	radius = set_radius;
	coil_count = set_coil_count;
	length = set_length;
	voltage = set_voltage;

	calcResistance();
	calcCurrent();

	// create a coil
	auto test_coil = new coil(radius, current);
}	

// destructor which deletes the allocated memory for the coil
solenoid::~solenoid() {
	delete test_coil;
}

// returns the total force on a point charge at a given x position[m]
float solenoid::getTotalForce(float test_xpos) {
	return totalForce(float test_xpos);
}

// sets the new voltage through the solenoid as the capacitor discharges, takes: voltage supplied[V]
void solenoid::setVoltage(float new_voltage) {
	voltage = new_voltage;
	calcCurrent();
	test_coil.setCurrent(current);
}

// calculates the resistance of a single coil, and then calculates the total resistance of the circuit
void solenoid::calcResistance() {
	coil_resistance = resistivity * 2 / radius;
	total_resistance = coil_resistance * coil_count;
}

// using the total resistance of the circuit and the supplied voltage, calculates the current through each coil
void solenoid::calcCurrent() {
	current = voltage / total_resistance;
}

// sums the force on the test point from each coil, takes: the xpos of the test point
float solenoid::totalForce(float test_xpos) {
	// for each coil in solenoid, sum the force on the test point
	float total_force;
	for (int i = 0; i < coil_count; i++) {
		float coil_xpos = length * i / coil_count;
		float i_force = test_coil.getForce(coil_xpos, test_xpos);
		total_force += i_force;
	}
	return total_force;
}

// returns the total resistance of the solenoid
float solenoid::getResistance() {
	return total_resistance;
}

