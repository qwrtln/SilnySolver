CODE_DIR = Backend/main/build/
TEST_DIR = Test/build/

# Compiler
CXX = g++
# Compiler flags
FLAGS = -Wall -O3 -std=c++11
export FLAGS

backend: project_code
test: testing_code
memcheck: checking_against_memory_leaks

project_code: 
	$(MAKE) -C $(CODE_DIR) SilnySolver
	mv $(CODE_DIR)SilnySolver .

testing_code: FLAGS += -D TESTING
testing_code: 
	$(MAKE) -C $(TEST_DIR) SilneTesty
	mv $(TEST_DIR)SilneTesty .

checking_against_memory_leaks:
	$(MAKE) -C $(TEST_DIR) MemoryCheck
	mv $(TEST_DIR)SilneTesty .

.PHONY: clean

clean:
	$(MAKE) -C $(CODE_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	rm -rf SilnySolver SilneTesty 

