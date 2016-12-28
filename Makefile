default: build

build:
	$(MAKE) -C cxx build
	$(MAKE) -C python/foolib build

clean:
	$(MAKE) -C cxx clean
	$(MAKE) -C python/foolib clean
