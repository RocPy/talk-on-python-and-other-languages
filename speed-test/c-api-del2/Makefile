all: clean program

program:
	python setup.py build_ext --include-dirs=${VIRTUAL_ENV}/lib/python2.7/site-packages/numpy/core/include/ --inplace

clean:
	rm -f thing.so
