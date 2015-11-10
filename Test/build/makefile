# Some variables declarations
# compiler
CXX = g++
# path to .h files		
INC =-I ../inc/ -I ../../Dev/inc/
# path to .cpp files
SRC = ../src/
# paths to dev files
DEVSRC = ../../Dev/src/
BUILT = $(subst src,build,$(DEVSRC))

FLAGS = -Wall

BUILT_FILES := $(subst src,build,$(patsubst %.cpp,%.o,$(wildcard $(DEVSRC)C*.cpp)))
SRC_FILES := $(wildcard $(SRC)*.cpp)
OBJ_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRC_FILES)))

Test: SilneTesty

SilneTesty: prodCode $(OBJ_FILES) heheszki
	$(CXX) $(FLAGS) $(BUILT_FILES) $(OBJ_FILES) $(INC) -o Test

prodCode: 
	$(MAKE) -C $(BUILT)

# It's a rule for every single cpp file, this is why we don't use _FILES var
%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) -c $< $(INC) -o $@
	
clean:
	rm *.o Test


