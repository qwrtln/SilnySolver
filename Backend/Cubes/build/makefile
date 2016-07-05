# MAKEFILE FOR CUBES SOFTWARE UNIT
# Compiler
CXX = g++
# Path to .h files
INC = -I ../inc/ -I ../../inc -I ../../Generators/inc
# Path to .cpp files
SRC = ../src/

# Compiler flags
FLAGS = -Wall -O3 -std=c++11

# variable containing list of all .cpp files in ../src/ folder
SRC_FILES := $(wildcard $(SRC)*.cpp)
# variable containing list of all .o files produced during above .cpp files compilation
OBJ_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRC_FILES)))
# variable containing list of all .d files
DEP_FILES := $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SRC_FILES)))

cubes.a: $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

.PHONY: clean
clean:
	rm -rf *.o *.d cubes.a

-include $(DEP_FILES)

