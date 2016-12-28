#include <Python.h>
#include "foolib/foolib_c.h"

static PyObject *
foolib_py_new(PyObject *self, PyObject *args)
{
    printf("TOM: foolib_py_new\n");
    foolib_object_t object = foolib_new();
    return Py_BuildValue("i", object);
}

static PyObject *
foolib_py_delete(PyObject *self, PyObject *args)
{
    int object;
    foolib_result_t rv;

    printf("TOM: foolib_py_delete\n");
    if (!PyArg_ParseTuple(args, "i", &object)) {
        return NULL;
    }
    rv = foolib_delete(object);
    return Py_BuildValue("i", rv);
}

static PyObject *
foolib_py_operation(PyObject *self, PyObject *args)
{
    int object;
    foolib_result_t rv;

    printf("TOM: foolib_py_operation\n");
    if (!PyArg_ParseTuple(args, "i", &object)) {
        return NULL;
    }
    rv = foolib_operation(object);
    return Py_BuildValue("i", rv);
}

static PyMethodDef FoolibPyMethods[] = {
    {"c_new", foolib_py_new, METH_VARARGS,
     "Create new object."},
    {"c_operation", foolib_py_operation, METH_VARARGS,
     "Operate on object."},
    {"c_delete", foolib_py_delete, METH_VARARGS,
     "Delete object."},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

static PyObject *FoolibError = NULL;

PyMODINIT_FUNC
initfoolib(void)
{
    PyObject *m = NULL;
    foolib_result_t rv;

    printf("TOM: initfoolib\n");
    (void) Py_InitModule("foolib", FoolibPyMethods);
    rv = foolib_g_init();
    if (rv != FOOLIB_RESULT_SUCCESS) {
        printf("initfoolib: foolib_g_init() error\n");
        FoolibError = PyErr_NewException("foolib.error", NULL, NULL);
        Py_INCREF(FoolibError);
        PyModule_AddObject(m, "error", FoolibError);
        return;
    }
}
