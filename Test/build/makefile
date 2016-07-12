# Some variables declarations
# Path to .h files - both Test and Backend
INC = -I ../inc/ -I ../../Backend/inc/ -I ../mock/ -I ../../Backend/Generators/inc/ -I ../../Backend/FileIO/inc/ -I ../../Backend/Cubes/inc/ -I ../../Backend/Containers/inc/
# Path to .cpp files
SRC_SUITE = ../src/suites/
# Paths to dev files
DEV_LIB = ../../Backend/build/
# Path to dev binaries
#BUILT = $(subst src,build,$(DEVSRC))
#Path to lib source files
LIB = ../lib/
# Path to lib.cpp files
SRC = ../src/

BACKEND_CIRCULAR_DEPS = $(DEV_LIB)containers.a $(DEV_LIB)cubes.a $(DEV_LIB)generators.a


# List of built dev files is generated on .cpp files, not .o files
# This is due to lack of certainty, whether they are actually built
BUILT_FILES := $(subst src,build,$(patsubst %.cpp,%.o,$(wildcard $(DEVSRC)*.cpp)))
BUILT_FILES := $(filter-out ../../Backend/build/SilnySolver.o, $(BUILT_FILES))

#List of all lib .o files
SLIB_FILES := $(SRC)BaseTest.cpp $(SRC)SilneTesty.cpp $(SRC)TestExecuter.cpp
# List of all source files
SRC_FILES := $(wildcard $(SRC_SUITE)*.cpp)
# List of all binaries
OBJ_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC_SUITE),,$(SRC_FILES)))
# List of all lib binaries
OLIB_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SLIB_FILES)))
# List of all data blocks
DEP_FILES := $(patsubst %.cpp,%.d,$(subst $(SRC_SUITE),,$(SRC_FILES)))
DEP_FILES += $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SLIB_FILES)))

# A separate rule for delivery checking purposes
MemoryCheck: FLAGS += -D MEMORY_CHECK
MemoryCheck: productionCode $(OBJ_FILES) testLib
	$(CXX) $(FLAGS) $(OBJ_FILES) $(DEV_LIB)dev.a testLib.a $(BACKEND_CIRCULAR_DEPS) $(INC) -o SilneTesty

SilneTesty: productionCode $(OBJ_FILES) testLib
	$(CXX) $(FLAGS) *.o $(DEV_LIB)dev.a testLib.a $(BACKEND_CIRCULAR_DEPS) $(INC) -o $@

productionCode:
	$(MAKE) -C $(DEV_LIB) dev_archive

testLib: $(OLIB_FILES)
	ar rcs testLib.a $(OLIB_FILES)

# It's a rule for every single cpp file, this is why we don't use *_FILES var
%.o: $(SRC_SUITE)%.cpp
	$(CXX) $(FLAGS) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

.PHONY: clean
clean:
	rm -rf *.o *.d SilneTesty

-include $(DEP_FILES)

