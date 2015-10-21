SRC = ../src/
INC = -I ../inc/ -I ../../Dev/inc

FLAGS = -Wall -O3
CXX = g++ $(INC)

-include SilneTesty.d BaseTest.d BaseTestFrameworkDefinitions.d CrazyCubeSolver_test.d CrazyCube_test.d SilneTesty.d TestExecuter.d

all: Tests

Tests: SilneTesty.o BaseTest.o BaseTestFrameworkDefinitions.o CrazyCubeSolver_test.o CrazyCube_test.o SilneTesty.o TestExecuter.o prod_code
	$(CXX) $(SRC)SilneTesty.o $(SRC)BaseTest.o $(SRC)BaseTestFrameworkDefinitions.o $(SRC)CrazyCubeSolver_test.o $(SRC)CrazyCube_test.o $(SRC)SilneTesty.o $(SRC)TestExecuter.o -o Tests

SilneTesty.o: $(SRC)SilneTesty.cpp
	$(CXX) -MM $(SRC)SilneTesty.cpp | tee SilneTesty.d
	$(CXX) -c $(SRC)SilneTesty.cpp

BaseTest.o: $(SRC)BaseTest.cpp
	$(CXX) -MM $(SRC)BaseTest.cpp | tee BaseTest.d
	$(CXX) -c $(SRC)BaseTest.cpp

BaseTestFrameworkDefinitions.o: $(SRC)BaseTestFrameworkDefinitions.cpp
	$(CXX) -MM $(SRC)BaseTestFrameworkDefinitions.cpp | tee BaseTestFrameworkDefinitions.d
	$(CXX) -c $(SRC)BaseTestFrameworkDefinitions.cpp

CrazyCubeSolver_test.o: $(SRC)CrazyCubeSolver_test.cpp
	$(CXX) -MM $(SRC)CrazyCubeSolver_test.cpp | tee CrazyCubeSolver_test.d
	$(CXX) -c $(SRC)CrazyCubeSolver_test.cpp

CrazyCube_test.o: $(SRC)CrazyCube_test.cpp
	$(CXX) -MM $(SRC)CrazyCube_test.cpp | tee CrazyCube_test.d
	$(CXX) -c $(SRC)CrazyCube_test.cpp

TestExecuter.o: $(SRC)TestExecuter.cpp
	$(CXX) -MM $(SRC)TestExecuter.cpp | tee TestExecuter.d
	$(CXX) -c $(SRC)TestExecuter.cpp

prod_code: 
	$(MAKE) -C ../../Dev/build

clean:
	rm *.o *.d Tests
