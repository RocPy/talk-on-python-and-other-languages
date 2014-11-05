#!/usr/bin/python

import thing
import numpy
import time

m = 5000
n = 5000

print "Generating sample data ({}x{} array), in Python...".format(m,n)
data_start = time.time()
data = numpy.ndarray(
    shape=(m, n),
    dtype='d',
    order='Fortran'
    )
fuzzed = numpy.ndarray(
    shape=data.shape,
    dtype=data.dtype,
    order='Fortran'
    )

for j in range(0, m):
    for k in range(0, n):
        data[j, k] = (float(j)/10.0)**4 + (float(k)/20.0)**4
data_end = time.time()

print "Performing gradient calculation on data ({}x{} array), with results:".format(m,n)
calc_start = time.time()
thing.del2(data, fuzzed, m, n)
calc_end = time.time()

for i in range(0, min(m, n), 1000):
    print fuzzed[i][i]

print "Summary:"
print "   Data generation code segment (Python) took", data_end-data_start, "seconds"
print "   Gradient calculation code segment (Fortran) took", calc_end-calc_start, "seconds"
print "   Total time:", (data_end-data_start)+(calc_end-calc_start), "seconds"
