
#include <Python.h>

static PyObject *
foolib_py_test(PyObject *self, PyObject *args)
{
    printf("TOM: foolib_py_test\n");
    return Py_BuildValue("i", 0);
}

static PyObject *
foolib_py_test1(PyObject *self, PyObject *args)
{
    printf("TOM: foolib_py_test1\n");
    return Py_BuildValue("i", 1);
}

static PyMethodDef FoolibPyMethods[] = {
    {"test", foolib_py_test, METH_VARARGS,
     "Test method."},
    {"test1", foolib_py_test1, METH_VARARGS,
     "Test method returns 1."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initfoolib(void)
{
    (void) Py_InitModule("foolib", FoolibPyMethods);
}

