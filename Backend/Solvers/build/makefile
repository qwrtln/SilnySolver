# MAKEFILE FOR SOLVERS SOFTWARE UNIT
include ../../build/makefile.defs

INC := $(subst ../,../../,$(INC))
INC += -I ../inc/

# variable containing list of all .cpp files in ../src/ folder
SRC_FILES := $(wildcard $(SRC)*.cpp)
# variable containing list of all .o files produced during above .cpp files compilation
OBJ_FILES := $(patsubst %.cpp,%.o,$(subst $(SRC),,$(SRC_FILES)))
# variable containing list of all .d files
DEP_FILES := $(patsubst %.cpp,%.d,$(subst $(SRC),,$(SRC_FILES)))

solvers.a: $(OBJ_FILES)
	ar rcs $@ $(OBJ_FILES)

%.o: $(SRC)%.cpp
	$(CXX) $(FLAGS) -c $< $(INC) -o $@
	$(CXX) -MM $< $(INC) > $(@:.o=.d)

.PHONY: clean
clean:
	rm -rf *.o *.d solvers.a

-include $(DEP_FILES)

