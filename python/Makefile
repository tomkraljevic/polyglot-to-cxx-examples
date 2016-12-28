default:	build

build:	clean
	rsync -a ../cxx .
	python setup.py build
	pip install .

test:
	python foolib/tests/test_c.py

clean:
	-pip uninstall --yes foolib
	python setup.py clean
	rm -rf build cxx
	rm -f `find . -name '*.pyc'`
	rm -rf `find . -name __pycache__`

