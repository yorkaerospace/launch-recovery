EXECUTABLE:simulation.exe 

CC:"c:\MinGW\bin\g++.exe"

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)

all: myprog

myprog: $(obj) $(CC) -o $(EXECUTABLE) $^

.PHONY: clean
clean: del $(obj) $(EXECUTABLE)