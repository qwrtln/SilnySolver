# Some variables declarations
# compiler
CXX = g++ -Wall
# path to .h files		
INC=-I ../inc/
# path to .cpp files
SRC= ../src/


# variable containing list of all .cpp files in ../src/ folder
SRCFILES := $(wildcard $(SRC)*.cpp) 
# variable containing list of all .o files produced during above .cpp files compilation
OBJFILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRCFILES)))
# variable containing list of all .d files
DEPFILES := $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SRCFILES)))

$(info $SRCFILES)
# Compilation rules
SilnySolver: $(OBJFILES)
	$(CXX) $^ -o $@

%.o: $(SRC)%.cpp 
	$(CXX) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)
	
# Clean the shit out
.PHONY: clean
clean:
	rm -rf *.o run SilnySolver *.d

-include $(DEPFILES)

