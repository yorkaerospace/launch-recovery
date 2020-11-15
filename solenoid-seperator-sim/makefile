CC = g++
CFLAGS = -Wall -g
SIMTARGET = sim.exe
TESTTARGET = test.exe

SRC = solenoid.cpp capacitor.cpp ejectionObject.cpp
SIM = sim.cpp
TEST = test.cpp

#$(TARGET): $(SRC)
#	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

sim: $(SRC) $(SIM)
	$(CC) $(SRC) $(SIM) $(CFLAGS) -o $(SIMTARGET) 

test: $(SRC) $(TEST)
	$(CC) $(SRC) $(TEST) $(CFLAGS) -o $(TESTTARGET) 

.PHONY: clean

clean:
	del *.o $(SIMTARGET) $(TESTTARGET)



