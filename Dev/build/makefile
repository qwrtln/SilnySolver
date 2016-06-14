# GENERAL DEV MAKEFILE
# Compiler
CXX = g++
# Path to .h files
INC = -I ../inc/ -I ../../Tracing/inc/ -I ../Generators/inc
# Path to .cpp files
SRC = ../src/
GENERATORS_DIR = ../Generators/build/

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
SilnySolver: $(OBJ_FILES) Generators
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) *.o $(GENERATORS_DIR)generators.a -o $@

# Rule for separating executable from build files
dev_archive: $(OBJ_FILES) Generators
	cp $(GENERATORS_DIR)generators.a dev.a
	ar q dev.a $(BUILT_FILES)

Generators:
	$(MAKE) -C $(GENERATORS_DIR)

%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) $(TRACE_FLAGS) $(TRACE_LEVEL) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

# Clean the shit out
.PHONY: clean
clean:
	$(MAKE) -C $(GENERATORS_DIR) clean
	rm -rf *.o *.d SilnySolver dev.a generators.a

-include $(DEP_FILES)

