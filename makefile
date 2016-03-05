CODE_DIR = Dev/build/
TEST_DIR = Test/build/

# Compiler
CXX = g++
# Compiler flags
FLAGS = -Wall -O3 -std=c++11
export FLAGS

dev: project_code
test: testing_code
memcheck: checking_against_memory_leaks

project_code: 
	$(MAKE) -C $(CODE_DIR) SilnySolver
	cp $(CODE_DIR)SilnySolver .

testing_code: 
	$(MAKE) -C $(TEST_DIR) SilneTesty
	cp $(TEST_DIR)SilneTesty .

checking_against_memory_leaks:
	$(MAKE) -C $(TEST_DIR) MemoryCheck
	cp $(TEST_DIR)SilneTesty .

.PHONY: clean

clean:
	$(MAKE) -C $(CODE_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	rm -rf SilnySolver SilneTesty 

