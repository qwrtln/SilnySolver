# Some variables declarations
# Compiler
CXX = g++
# Path to .h files - both Test and Dev	
INC = -I ../inc/ -I ../../Dev/inc/
# Path to .cpp files
SRC = ../src/
# Paths to dev files
DEVSRC = ../../Dev/src/
# Path to dev binaries
BUILT = $(subst src,build,$(DEVSRC))

# Compiler flags
FLAGS = -Wall -O3

# List of built dev files is generated on .cpp files, not .o files
# This is due to lack of certainty, whether they are actually built
BUILT_FILES := $(subst src,build,$(patsubst %.cpp,%.o,$(wildcard $(DEVSRC)C*.cpp)))
# List of all source files
SRC_FILES := $(wildcard $(SRC)*.cpp)
# List of all binaries
OBJ_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRC_FILES)))
# List of all data blocks
DEP_FILES := $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SRC_FILES)))

SilneTesty: productionCode $(OBJ_FILES) 
	$(CXX) $(FLAGS) $(BUILT_FILES) $(OBJ_FILES) $(INC) -o $@

productionCode: 
	$(MAKE) -C $(BUILT) build

# It's a rule for every single cpp file, this is why we don't use *_FILES var
%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

.PHONY: clean	
clean:
	rm -rf *.o *.d SilneTesty 

-include $(DEP_FILES)

