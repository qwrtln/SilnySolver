# GENERAL BACKEND MAKEFILE
include makefile.defs

# Software Units paths
GENERATORS_DIR = ../Generators/build/
FILE_IO_DIR = ../FileIO/build/
CUBES_DIR = ../Cubes/build/
CONTAINERS_DIR = ../Containers/build/
SOLVERS_DIR = ../Solvers/build/
BASE_DIR = ../Base/build/

# Compilation rules
SilnySolver: dev_archive
	$(CXX) $(FLAGS) $(INC) -c main/SilnySolver.cpp $(INC) -o SilnySolver.o
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) $(INC) SilnySolver.o dev.a containers.a cubes.a base.a generators.a -o $@ # multiple inclusions due to circular references

# Rule for separating executable from build files
dev_archive: Base Cubes Containers Generators FileIO Solvers
	cp $(BASE_DIR)base.a .
	cp $(CUBES_DIR)cubes.a .
	cp $(CONTAINERS_DIR)containers.a .
	cp $(GENERATORS_DIR)generators.a .
	cp $(FILE_IO_DIR)fileio.a .
	cp $(SOLVERS_DIR)solvers.a .
	ar rcT dev.a generators.a fileio.a cubes.a solvers.a $(BUILT_FILES)

Base:
	$(MAKE) -C $(BASE_DIR)

Cubes:
	$(MAKE) -C $(CUBES_DIR)

Containers:
	$(MAKE) -C $(CONTAINERS_DIR)

Generators:
	$(MAKE) -C $(GENERATORS_DIR)

FileIO:
	$(MAKE) -C $(FILE_IO_DIR)

Solvers:
	$(MAKE) -C $(SOLVERS_DIR)

# Clean the shit out
.PHONY: clean
clean:
	$(MAKE) -C $(GENERATORS_DIR) clean
	$(MAKE) -C $(FILE_IO_DIR) clean
	$(MAKE) -C $(CUBES_DIR) clean
	$(MAKE) -C $(CONTAINERS_DIR) clean
	$(MAKE) -C $(SOLVERS_DIR) clean
	$(MAKE) -C $(BASE_DIR) clean
	rm -rf *.o *.d SilnySolver dev.a generators.a fileio.a cubes.a containers.a solvers.a base.a

