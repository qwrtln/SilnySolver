# Some variables declarations
# Path to .h files - both Test and Dev	
INC = -I ../inc/ -I ../../Dev/inc/
# Path to .cpp files
SRC_SUITE = ../src/suites/
# Paths to dev files
DEVSRC = ../../Dev/src/
# Path to dev binaries
BUILT = $(subst src,build,$(DEVSRC))
#Path to lib source files
LIB = ../lib/
# Path to lib.cpp files
SRC = ../src/

# List of built dev files is generated on .cpp files, not .o files
# This is due to lack of certainty, whether they are actually built
BUILT_FILES := $(subst src,build,$(patsubst %.cpp,%.o,$(wildcard $(DEVSRC)*.cpp)))
BUILT_FILES := $(filter-out ../../Dev/build/SilnySolver.o, $(BUILT_FILES))

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
	$(CXX) $(FLAGS) $(BUILT_FILES) $(OBJ_FILES) testLib.a $(INC) -o SilneTesty

SilneTesty: productionCode  $(OBJ_FILES) testLib 
	$(CXX) $(FLAGS) $(BUILT_FILES) $(OBJ_FILES) testLib.a $(INC) -o $@

productionCode: 
	$(MAKE) -C $(BUILT) binaries

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

