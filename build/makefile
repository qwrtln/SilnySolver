SRC = ../src/
INC = -I ../inc/
GCC = g++ $(INC)

all: SilnySolver

SilnySolver: SilnySolver.o CrazyCubeSolver.o CrazyCube.o CrazyCubeAbstract.o
	$(GCC) SilnySolver.o CrazyCubeSolver.o CrazyCube.o CrazyCubeAbstract.o -o SilnySolver

SilnySolver.o: $(SRC)SilnySolver.cpp
	$(GCC) -c $(SRC)SilnySolver.cpp

CrazyCubeSolver.o: $(SRC)CrazyCubeSolver.cpp
	$(GCC) -c $(SRC)CrazyCubeSolver.cpp

CrazyCube.o: $(SRC)CrazyCube.cpp
	$(GCC) -c $(SRC)CrazyCube.cpp

CrazyCubeAbstract.o: $(SRC)CrazyCubeAbstract.cpp
	$(GCC) -c $(SRC)CrazyCubeAbstract.cpp

clean:
	rm *o

