#!/usr/bin/python

import thing
import time

m = 5000
n = 5000

print "Generating sample data ({}x{} array), in Python...".format(m,n)
data_start = time.time()
data = [[(float(j)/10.0)**4 + (float(k)/20.0)**4 for j in range(0, n)]
        for k in range(0, m)]
data_end = time.time()

print "Performing gradient calculation on data ({}x{} array), with results:".format(m,n)
calc_start = time.time()
fuzzed = thing.del2(data, m, n)
calc_end = time.time()

for i in range(0, min(m, n), 1000):
    print fuzzed[i][i]

print "Summary:"
print "   Data generation code segment (Python) took", data_end-data_start, "seconds"
print "   Gradient calculation code segment (Python) took", calc_end-calc_start, "seconds"
print "   Total time:", (data_end-data_start)+(calc_end-calc_start), "seconds"
