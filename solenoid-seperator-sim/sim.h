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

// the main function will also initialise the objects, as an init function for each object was a waste of time

// this will update each object every timestep, for the duration of the simulation
void updateSystem(solenoid *, capacitor *, ejectionObject *, float, float);

// this will delete each object from dynamic memory
void cleanUp(solenoid *, capacitor *, ejectionObject *);

#endif