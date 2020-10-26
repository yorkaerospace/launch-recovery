=-=-=-=
README
=-=-=-=

This will be a small project, simulating a solenoid that could be used to seperate the SAC rocket.
This simulation will model the solenoid as a series of coils, each acting on an aluminium rod.
The coil parameters will be varied, to optimise the performance of the seperator.
Obviously, the solenoid will be constrained by weight and size, both of the coil and its supplying capacitors.
The results from this simulation will then be incorporated into a physical prototype for verification.
This design will then be refined for deployment inside the rocket.


As such, this simulation must:
1. Accurately calculate the force between each coil and the bar
2. Allow the coil parameters to be varied (diameter, supplied voltage, etc)
3. Allow the number and density of coils to be varied
4. Allow the number of capactitors used to supply to be varied
5. Approximate the temperature increase due to the voltage discharge through the coils
6. Constrain the above-mentioned variables to realistic approximations of the constraints due to the rockets size and shape
