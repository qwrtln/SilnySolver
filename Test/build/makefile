# Some variables declarations
# compiler
CXX = g++
# path to .h files		
INC=-I ../inc/ -I ../../Dev/inc/
# path to .cpp files
SRC= ../src/


# variable containing list of all .cpp files in ../src/ folder
SRCFILES := $(wildcard $(SRC)*.cpp) 
# variable containing list of all .o files produced during above .cpp files compilation
OBJFILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRCFILES)))
# variable containing list of all .d files
DEPFILES := $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SRCFILES)))


# Compilation rules
all: $(OBJFILES) production_code
	$(CXX) $^ -o $@

%.o: $(SRC)%.cpp
	$(CXX) -c $< $(INC) -o $@
	
%.d: $(SRC)%.cpp
	$(CXX) -MM $< $(INC) > $@

# Deal with the production code before
prod_code:
	$(MAKE) -C ../../Dev/build/


# Clean the shit out and run %.d rule in case %.d files are not present anymore because of previous invocation, and delete them again. Because it is funny.
.PHONY: clean
clean:
	rm -rf *.o run all *.d

-include $(DEPFILES)

