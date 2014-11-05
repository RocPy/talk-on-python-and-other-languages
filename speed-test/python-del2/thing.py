'''thing: (Author: Bob Dowling <rjd4@cam.ac.uk>)
This is an example pure-python module for use in the UCS course on
integrating Fortran and Python.
'''

def del2(array, m, n):
    '''del2(array, m, n):
array is a list (length m) of lists (length n) of numerical values

The function returns an array (list of lists) of the same size where
the boundary elements are all set to 0.0 and the inner elements are
defined by the four point "del squared" transformation of the input
array.

No changes are made to the input array.
'''

    fuzz = [ [ 0.0  for k in range(0,n) ] for j in range(0,m) ]

    for j in range(1,m-1):
        for k in range(1,n-1):
            fuzz[j][k] = 0.5*(
                array[j-1][k] +
                array[j+1][k] +
                array[j][k-1] +
                array[j][k+1] -
                4.0*array[j][k]
                )

    return fuzz
