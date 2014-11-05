/* Normally, I would include Python.h here. */

/* Function Prototypes */
PyObject *thing_del2(PyObject *self, PyObject *args);
PyMODINIT_FUNC initthing(void);

static PyMethodDef ThingMethods[] = {
    {"del2", thing_del2, METH_VARARGS, "Do a sample 2D gradient calculation"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
