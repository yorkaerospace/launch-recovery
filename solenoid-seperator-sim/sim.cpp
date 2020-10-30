#include "sim.h"

int main(int argc, char * argv[]) {

	int num_args = 8;
	if (argc != num_args + 1) {
		std::cout << "Error: Invalid number of simulation arguments. Exiting." << std::endl;
		return 1;
	}

	float solenoid_radii = atof(argv[1]);
	int ring_number = atof(argv[2]);
	float solenoid_length = atof(argv[3]);
	float capacitor_voltage = atof(argv[4]);
	float capacitor_capacitance = atof(argv[5]);
	float test_mass = atof(argv[6]);
	float test_com = atof(argv[7]);
	float timestep = atof(argv[8]);
	float total_time = atof(argv[9]);

	std::cout << "Variables set, creating objects..." << std::endl;

	solenoid * sim_solenoid = new solenoid(solenoid_radii, ring_number, solenoid_length, capacitor_voltage);
	capacitor * sim_capacitor = new capacitor(capacitor_voltage, capacitor_capacitance, sim_solenoid);
	ejectionObject * sim_ejectionObject = new ejectionObject(test_mass, test_com);

	std::cout << "Objects created, running simulation..." << std::endl;

	updateSystem(sim_solenoid, sim_capacitor, sim_ejectionObject, timestep, total_time);

	std::cout << "Simulation run, cleaning objects..." << std::endl;

	cleanUp(sim_solenoid, sim_capacitor, sim_ejectionObject);

	std::cout << "Objects cleaned, exiting program..." << std::endl;

	return 0;
}

void updateSystem(solenoid * sim_solenoid, capacitor * sim_capacitor, ejectionObject * sim_ejectionObject, float timestep, float total_time) {
	std::cout << "Hello!" << std::endl;
	float force, xpos;
	for (float time = 0; time < total_time; time+= timestep) {
		xpos = sim_ejectionObject->getPos();
		force = sim_solenoid->getTotalForce(xpos);
		sim_ejectionObject->setPos(force, timestep);
		sim_capacitor->updateVoltage(time);
		std::cout << xpos << std::endl;
	}
}

void cleanUp(solenoid * sim_solenoid, capacitor * sim_capacitor, ejectionObject * sim_ejectionObject) {
	delete sim_solenoid;
	delete sim_capacitor;
	delete sim_ejectionObject;
}