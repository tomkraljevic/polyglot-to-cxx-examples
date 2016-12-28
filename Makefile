default: build test

build:
	$(MAKE) -C cxx build
	$(MAKE) -C python build

test:
	$(MAKE) -C python test
	@echo
	@echo ALL TESTS PASSED

clean:
	$(MAKE) -C cxx clean
	$(MAKE) -C python clean
