# GENERAL BACKEND MAKEFILE
include makefile.defs

# Software Units paths
GENERATORS_DIR = ../Generators/build/
FILE_IO_DIR = ../FileIO/build/
CUBES_DIR = ../Cubes/build/
CONTAINERS_DIR = ../Containers/build/

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
SilnySolver: dev_archive
	$(CXX) $(FLAGS) $(INC) -c $(SRC)SilnySolver.cpp $(INC) -o SilnySolver.o
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) $(INC) SilnySolver.o dev.a containers.a cubes.a generators.a -o $@ # multiple inclusions due to circular dependencies

# Rule for separating executable from build files
dev_archive: $(OBJ_FILES) Cubes Containers Generators FileIO
	cp $(CUBES_DIR)cubes.a .
	cp $(CONTAINERS_DIR)containers.a .
	cp $(GENERATORS_DIR)generators.a .
	cp $(FILE_IO_DIR)fileio.a .
	ar rcT dev.a generators.a fileio.a cubes.a $(BUILT_FILES)

Cubes:
	$(MAKE) -C $(CUBES_DIR)

Containers:
	$(MAKE) -C $(CONTAINERS_DIR)

Generators:
	$(MAKE) -C $(GENERATORS_DIR)

FileIO:
	$(MAKE) -C $(FILE_IO_DIR)

%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

# Clean the shit out
.PHONY: clean
clean:
	$(MAKE) -C $(GENERATORS_DIR) clean
	$(MAKE) -C $(FILE_IO_DIR) clean
	$(MAKE) -C $(CUBES_DIR) clean
	$(MAKE) -C $(CONTAINERS_DIR) clean
	rm -rf *.o *.d SilnySolver dev.a generators.a fileio.a cubes.a containers.a

-include $(DEP_FILES)

