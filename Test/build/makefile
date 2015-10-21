SRC = ../src/
INC = -I ../inc/
CXX = g++ $(INC)

all: Tests

Tests: SilneTesty.o BaseTest.o BaseTestFrameworkDefinitions.o CrazyCubeSolver_test.o CrazyCube_test.o SilneTesty.o TestExecuter.o
	$(CXX) $(SRC)SilneTesty.o $(SRC)BaseTest.o $(SRC)BaseTestFrameworkDefinitions.o $(SRC)CrazyCubeSolver_test.o $(SRC)CrazyCube_test.o $(SRC)SilneTesty.o $(SRC)TestExecuter.o -o Tests

main.o: $(SRC)SilneTesty.cpp
	$(CXX) -c $(SRC)SilneTesty.cpp

BaseTest.o: $(SRC)BaseTest.cpp
	$(CXX) -c $(SRC)BaseTest.cpp

BaseTestFrameworkDefinitions.o: $(SRC)BaseTestFrameworkDefinitions.cpp
	$(CXX) -c $(SRC)BaseTestFrameworkDefinitions.cpp

CrazyCubeSolver_test.o: $(SRC)CrazyCubeSolver_test.cpp
	$(CXX) -c $(SRC)CrazyCubeSolver_test.cpp

CrazyCube_test.o: $(SRC)CrazyCube_test.cpp
	$(CXX) -c $(SRC)CrazyCube_test.cpp

SilneTesty.o: $(SRC)SilneTesty.cpp
	$(CXX) -c $(SRC)SilneTesty.cpp

TestExecuter.o: $(SRC)TestExecuter.cpp
	$(CXX) -c $(SRC)TestExecuter.cpp

clean:
	rm *o
