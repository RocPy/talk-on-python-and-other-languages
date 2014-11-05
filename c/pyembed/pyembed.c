#include <Python.h>
#include <stdio.h>
#include "spammodule.h"

/* Reference: https://docs.python.org/2/extending/embedding.html */

int main(int argc, char *argv[]) {
    /* Pass argv[0] to the Python interpreter */
    Py_SetProgramName(argv[0]);

    /* Initialize the Python interpreter.  Required. */
    Py_Initialize();

    /* Add a static module */
    initspam();

    PyObject *pName = PyString_FromString("spam");
    PyObject *pModule = PyImport_Import(pName);
    Py_DECREF(pName);

    PyObject *pFunc = PyObject_GetAttrString(pModule, "system");
    Py_DECREF(pModule);
    /* pFunc is a new reference */

    if (pFunc && PyCallable_Check(pFunc)) {
        PyObject *pArgs = PyTuple_New(1);
        PyTuple_SetItem(pArgs, 0, PyString_FromString("echo Hello World"));

        PyObject *res = PyObject_CallObject(pFunc, pArgs);
        if (res != NULL) {
            printf("Result of call: %s\n", PyString_AsString(res));
            Py_DECREF(res);
        }
        Py_DECREF(pFunc);
    }
}
