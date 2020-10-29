#ifndef SIM_H
#define SIM_H

// custom classes required
#include "solenoid.h"
#include "capacitor.h"
#include "ejectionObject.h"

// standard C++ libraries used
#include <iostream>

/* the main function will accept arguments that define the physical system being simulated. In order:
 * SOLENOID-RADII[m] NUMBER-OF-RINGS SOLENOID-LENGTH[m] CAPACITOR-VOLTAGE[V] CAPACITOR-CAPACITANCE[F] TEST-MASS[kg] TEST-COM[m] TIMESTEP-DURATION[s] TOTAL-TIME[s]
 * all lengths are relative to the end of the solenoid
 */

// this will initialise a solenoid, which includes all the associated rings, takes: solenoid radius[m], number of rings, solenoid length[m]
solenoid * initSolenoid(float, int, float);

// this will initialise a capacitor bank, takes: initial capacitor voltage[V], capacitor capacitance[F]
capacitor * initCapacitors(float, float);

// this will initialise a test object, takes: object mass[kg], object COM[m]
ejectionObject * initEjectionObject(float, float);

// this will update each object every timestep, for the duration of the simulation
void updateSystem(solenoid *, capactitor *, ejectionObject *, float, int);

// this will delete each object from dynamic memory
void cleanUp(solenoid *, capactitor *, ejectionObject *);

#endif