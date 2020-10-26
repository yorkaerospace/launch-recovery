#ifndef SIM_H
#define SIM_H

// custom classes required
#include "solenoid.h"
#include "capacitor.h"
#include "ejectionObject.h"

// standard C++ libraries used
#include <iostream>

/* the main function will accept arguments that define the physical system being simulated. In order:
 * SOLENOID-RADII[m] NUMBER-OF-COILS SOLENOID-LENGTH[m] CAPACITOR-VOLTAGE[V] CAPACITOR-CAPACITANCE[F] TEST-MASS[kg] TEST-COM[m]
 * all lengths are relative to the end of the solenoid
 */

// this will initialise a solenoid, which includes all the associated coils, takes: solenoid radius[m], number of coils, solenoid length[m]
solenoid * initSolenoid(float, float, float);

// this will initialise a capacitor bank, takes: initial capacitor voltage[V], capacitor capacitance[F]
capacitor * initCapacitors(float, float);

// this will initialise a test object, takes: object mass[kg], object COM[m]
ejectionObject * initEjectionObject(float, float);

// this will update all the relevent classes every timestep - the simulation itself
void updateSystem(solenoid *, capactitor *, ejectionObject *);

// this will delete each object from dynamic memory
void cleanUp(solenoid *, capactitor *, ejectionObject *);

#endif