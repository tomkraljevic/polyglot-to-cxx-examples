default: build test

build:
	$(MAKE) -C cxx build
	$(MAKE) -C python/foolib build

test:
	python python/test/foolib_test.py
	@echo
	@echo ALL TESTS PASSED

clean:
	$(MAKE) -C cxx clean
	$(MAKE) -C python/foolib clean
