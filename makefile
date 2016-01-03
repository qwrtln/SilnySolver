CODE_DIR = Dev/build/
TEST_DIR = Test/build/

dev: project_code
test: testing_code

project_code:
	$(MAKE) -C $(CODE_DIR) SilnySolver
	cp $(CODE_DIR)SilnySolver .

testing_code:
	$(MAKE) -C $(TEST_DIR)
	cp $(TEST_DIR)SilneTesty .

.PHONY: clean

clean:
	$(MAKE) -C $(CODE_DIR) clean
	$(MAKE) -C $(TEST_DIR) clean
	rm -rf SilnySolver SilneTesty 

