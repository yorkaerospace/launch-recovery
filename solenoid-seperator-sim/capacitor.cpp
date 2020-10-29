#include "capacitor.h"
#include <cmath>

// constructor which sets the initial voltage of the capacitor bank, takes: initial voltage[V]
capacitor::capacitor(float start_voltage, float caps, solenoid * sole) {
	init_voltage = start_voltage;
	capacitance = caps;
	resistance = sole.getResistance();
	solenoid_ptr = sole;
}

// updates the voltage of the capacitor bank, takes: time[s]
void capacitor::updateVoltage(float time) {
	calcVoltage(time);
	getVoltage();
}

// calculates the new voltage after a time has passed, takes: time[s]
void capacitor::calcVoltage(float time) {
	float e = 2.71828;
	float modifier = pow(e, time * -1 / (resistance * capacitance));
	current_voltage = init_voltage * modifier;
}

// passes the updated voltage to the solenoid
void capacitor::getVoltage() {
	solenoid_ptr.setVoltage(current_voltage);
}