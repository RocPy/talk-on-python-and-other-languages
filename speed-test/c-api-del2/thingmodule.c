#define PY_ARRAY_UNIQUE_SYMBOL thing_ARRAY_API
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <numpy/arrayobject.h>
#include "thingmodule.h"

PyObject *thing_del2(PyObject *self, PyObject *args) {
    PyArrayObject *data_pyobj;
    PyArrayObject *fuzz_pyobj;
    double **data;
    double **fuzz;
    int m, n;
    PyArray_Descr *descr;
    npy_intp dims[2];

    if (!PyArg_ParseTuple(args, "O!O!ii", 
                &PyArray_Type, &data_pyobj, 
                &PyArray_Type, &fuzz_pyobj,
                &m, &n)){
        return NULL;
    }

    descr = PyArray_DescrFromType(NPY_DOUBLE);

    if (PyArray_AsCArray((PyObject **) &data_pyobj, (void **)&data, dims, 2, descr) < 0 ||
            PyArray_AsCArray((PyObject **) &fuzz_pyobj, (void **)&fuzz, dims, 2, descr) < 0) {
        PyErr_SetString(PyExc_TypeError, "error converting to c array");
        return NULL;
    }

    int j, k;

    for (j = 0; j < m; j++) {
        fuzz[j][0] = 0.0;
        fuzz[j][n-1] = 0.0;
    }

    for (k = 0; k < n; k++) {
        fuzz[0][k] = 0.0;
        fuzz[m-1][k] = 0.0;
    }

    for (j = 1; j < m -1; j++){
        for (k = 1; k < n - 1; k++) {
            fuzz[j][k] = 0.5*(
                    data[j-1][k] +
                    data[j+1][k] +
                    data[j][k-1] +
                    data[j][k+1] -
                    4.0*data[j][k]);
        }
    }

    return PyArray_Return(fuzz_pyobj);
}

PyMODINIT_FUNC initthing(void) {
        (void) Py_InitModule("thing", ThingMethods);
        import_array();
}
