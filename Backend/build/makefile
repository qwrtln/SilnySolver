# GENERAL DEV MAKEFILE
# Compiler
CXX = g++
# Path to includes
INC = -I ../inc/ -I ../../Tracing/inc/ -I ../Generators/inc/ -I ../FileIO/inc/ -I ../Cubes/inc/
# Path to .cpp files
SRC = ../src/

# Software Units paths
GENERATORS_DIR = ../Generators/build/
FILE_IO_DIR = ../FileIO/build/
CUBES_DIR = ../Cubes/build/

# Compiler flags
FLAGS = -Wall -O3 -std=c++11

# variable containing list of all .cpp files in ../src/ folder
SRC_FILES := $(wildcard $(SRC)*.cpp)
# variable containing list of all .o files produced during above .cpp files compilation
OBJ_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRC_FILES)))
# variable containing list of all .d files
DEP_FILES := $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SRC_FILES)))

# Variable to exclude SilnySolver.o from archive for tests
BUILT_FILES := $(subst src,build,$(patsubst %.cpp,%.o,$(wildcard $(SRC)*.cpp)))
BUILT_FILES := $(filter-out ../build/SilnySolver.o, $(BUILT_FILES))

# Compilation rules
SilnySolver: $(OBJ_FILES) Generators FileIO Cubes
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) *.o $(GENERATORS_DIR)generators.a $(FILE_IO_DIR)fileio.a $(CUBES_DIR)cubes.a -o $@

# Rule for separating executable from build files
dev_archive: $(OBJ_FILES) Generators FileIO Cubes
	cp $(GENERATORS_DIR)generators.a .
	cp $(FILE_IO_DIR)fileio.a .
	cp $(CUBES_DIR)cubes.a .
	ar rcT dev.a generators.a fileio.a cubes.a $(BUILT_FILES)

Generators:
	$(MAKE) -C $(GENERATORS_DIR)

FileIO:
	$(MAKE) -C $(FILE_IO_DIR)

Cubes:
	$(MAKE) -C $(CUBES_DIR)

%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

# Clean the shit out
.PHONY: clean
clean:
	$(MAKE) -C $(GENERATORS_DIR) clean
	$(MAKE) -C $(FILE_IO_DIR) clean
	$(MAKE) -C $(CUBES_DIR) clean
	rm -rf *.o *.d SilnySolver dev.a generators.a fileio.a cubes.a

-include $(DEP_FILES)

