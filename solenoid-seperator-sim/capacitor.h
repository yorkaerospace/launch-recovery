#ifndef CAPACITOR_H
#define CAPACITOR_H

#include "solenoid.h"

class capacitor
{

private:

	float init_voltage, resistance, current_voltage, capacitance;
	solenoid * solenoid_ptr;


	// calculates the new voltage after a time has passed, takes: time[s]
	void calcVoltage(float);

	// passes the updated voltage to the solenoid
	void getVoltage(void);

public:

	// constructor which sets the initial voltage & capacitance of capacitor, and gets the resistance of the solenoid, takes: initial voltage[V], capacitance[F], solenoid pointer
	capacitor(float, float, solenoid *);

	// updates the voltage of the capacitor bank, takes: time[s]
	void updateVoltage(float);
};

#endif