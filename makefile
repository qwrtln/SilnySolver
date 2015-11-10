CODE_DIR = Dev/build

.PHONY: project_code

project_code:
	$(MAKE) -C $(CODE_DIR)

clean:
	$(MAKE) -C $(CODE_DIR) clean
