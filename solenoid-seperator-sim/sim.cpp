#include "sim.h"

int main(int argc, char * argv[]) {

	int num_args = 8;
	if (argc != num_args + 1) {
		std::cout << "Error: Invalid number of simulation arguments. Exiting." << std::endl;
		return 1;
	}

	float solenoid_radii = argv[1];
	int coil_number = argv[2];
	float solenoid_length = argv[3];
	float capactitor_voltage = argv[4];
	float capacitor_capacitance = argv[5];
	float test_mass = argv[6];
	float test_com = argv[7];
	float timestep = argv[8];
	int total_time = argv[9];

	solenoid * sim_solenoid = initSolenoid(solenoid_radii, coil_number, solenoid_length);
	capacitor * sim_capactitor = initCapacitor(capactitor_voltage, capacitor_capacitance);
	ejectionObject * sim_ejectionObject = initEjectionObject(test_mass, test_com);

	updateSystem(sim_solenoid, sim_capacitor, sim_ejectionObject, timestep, total_time);

	cleanUp(sim_solenoid, sim_capacitor, sim_ejectionObject);

	return 0;
}

solenoid * initSolenoid(float radii, coil_number, length) {
	
}