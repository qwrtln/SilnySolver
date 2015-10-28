# Some variables declarations
# compiler
CXX = g++
# path to .h files		
INC=-I ../inc/
# path to .cpp files
SRC= ../src/

# variable containing list of all .cpp files in ../src/ folder
SRCFILES := $(wildcard $(SRC)*.cpp) 
# variable containing list of all .o files produced during above .cpp files compilation
OBJFILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRCFILES)))
# variable containing list of all .d files
DEPFILES := $(patsubst %.cpp,%.d,$(SRCFILES))

# Compilation rules
all: $(OBJFILES)
	$(CXX) $^ -o $@
	
%.o: $(SRC)%.cpp
	$(CXX) -c $(SRC)$< $(INC) -o $@
	
%.d: $(SRC)%.cpp
	$(CXX) -MM $(SRC)$< $(INC) > $@


# Clean the shit out
.PHONY : clean

clean:
	rm -rf *.o run *.d


-include $(DEPFILES)
