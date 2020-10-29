#include "sim.h"

int main(int argc, char * argv[]) {

	int num_args = 8;
	if (argc != num_args + 1) {
		std::cout << "Error: Invalid number of simulation arguments. Exiting." << std::endl;
		return 1;
	}

	float solenoid_radii = argv[1];
	int ring_number = argv[2];
	float solenoid_length = argv[3];
	float capactitor_voltage = argv[4];
	float capacitor_capacitance = argv[5];
	float test_mass = argv[6];
	float test_com = argv[7];
	float timestep = argv[8];
	float total_time = argv[9];

	solenoid * sim_solenoid = new solenoid(solenoid_radii, ring_number, solenoid_length, capacitor_voltage);
	capacitor * sim_capacitor = new capacitor(capactitor_voltage, capacitor_capacitance, sim_solenoid);
	ejectionObject * sim_ejectionObject ejectionObject(test_mass, test_com);

	updateSystem(sim_solenoid, sim_capacitor, sim_ejectionObject, timestep, total_time);

	cleanUp(sim_solenoid, sim_capacitor, sim_ejectionObject);

	return 0;
}

void updateSystem(sim_solenoid, sim_capacitor, sim_ejectionObject, timestep, total_time) {
	float force, resistance, xpos;
	for (float time = 0; time < total_time; time+= timestep) {
		xpos = sim_ejectionObject.getPos();
		force = sim_solenoid.getTotalForce(xpos);
		sim_ejectionObject.setPos(force, timestep);
		sim_capacitor.updateVoltage(time);
	}
}

void cleanUp(sim_solenoid, sim_capacitor, sim_ejectionObject) {
	delete sim_solenoid;
	delete sim_capacitor;
	delete sim_ejectionObject;
}