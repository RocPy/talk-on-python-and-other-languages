/* Normally, I would include Python.h here. */

/* Function Prototypes */
PyObject *spam_system(PyObject *self, PyObject *args);
PyMODINIT_FUNC initspam(void);

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS, "Execute a shell command."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};
