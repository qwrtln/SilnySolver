SRC = ../src/
INC = ../inc/
FLAGS = -Wall -O3
GCC = g++ $(FLAGS) -I $(INC)

all: SilnySolver

SilnySolver: SilnySolver.o CrazyCubeSolver.o CrazyCube.o CrazyCubeAbstract.o
	$(GCC) SilnySolver.o CrazyCubeSolver.o CrazyCube.o CrazyCubeAbstract.o -o SilnySolver

SilnySolver.o: $(SRC)SilnySolver.cpp
#SilnySolver.o: $(SRC)SilnySolver.cpp  $(INC)CrazyCubeSolver.h $(INC)CrazyCube.h $(INC)CrazyCubeAbstract.h
	$(GCC) -c $(SRC)SilnySolver.cpp

CrazyCubeSolver.o: $(SRC)CrazyCubeSolver.cpp $(INC)CrazyCubeSolver.h
	$(GCC) -c $(SRC)CrazyCubeSolver.cpp

CrazyCube.o: $(SRC)CrazyCube.cpp $(INC)CrazyCube.h
	$(GCC) -c $(SRC)CrazyCube.cpp

CrazyCubeAbstract.o: $(SRC)CrazyCubeAbstract.cpp $(INC)CrazyCubeAbstract.h
	$(GCC) -c $(SRC)CrazyCubeAbstract.cpp

clean:
	rm *o

