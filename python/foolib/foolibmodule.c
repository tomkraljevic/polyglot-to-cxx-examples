#include <Python.h>
#include "foolib/foolib_c.h"

static PyObject *
foolib_py_set_verbosity(PyObject *self, PyObject *args)
{
    int v;

    if (!PyArg_ParseTuple(args, "i", &v)) {
        return NULL;
    }

    foolib_g_verbosity = v;
    printf("foolib: verbosity set to %d\n", foolib_g_verbosity);

    return Py_BuildValue("i", FOOLIB_RESULT_SUCCESS);
}

static PyObject *
foolib_py_new(PyObject *self, PyObject *args)
{
    foolib_object_t object = foolib_new();

    if (foolib_g_verbosity > 0) {
        printf("%d = foolib_py_new()\n", object);
    }

    return Py_BuildValue("i", object);
}

static PyObject *
foolib_py_delete(PyObject *self, PyObject *args)
{
    int object;
    foolib_result_t rv;

    if (!PyArg_ParseTuple(args, "i", &object)) {
        return NULL;
    }

    rv = foolib_delete(object);

    if (foolib_g_verbosity > 0) {
        printf("%d = foolib_py_delete(%d)\n", rv, object);
    }

    return Py_BuildValue("i", rv);
}

static PyObject *
foolib_py_operation(PyObject *self, PyObject *args)
{
    int object;
    foolib_result_t rv;

    if (!PyArg_ParseTuple(args, "i", &object)) {
        return NULL;
    }

    rv = foolib_operation(object);

    if (foolib_g_verbosity > 0) {
        printf("%d = foolib_py_operation(%d)\n", rv, object);
    }

    return Py_BuildValue("i", rv);
}

static PyMethodDef FoolibPyMethods[] = {
    {"c_set_verbosity", foolib_py_set_verbosity, METH_VARARGS,
     "Set library verbosity level."},
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
init_foolib(void)
{
    PyObject *m = NULL;
    foolib_result_t rv;

    if (foolib_g_verbosity > 0) {
        printf("init_foolib\n");
    }

    (void) Py_InitModule("_foolib", FoolibPyMethods);
    rv = foolib_g_init();
    if (rv != FOOLIB_RESULT_SUCCESS) {
        if (foolib_g_verbosity > 0) {
            printf("init_foolib: foolib_g_init() error (%d)\n", rv);
        }
        FoolibError = PyErr_NewException("foolib.error", NULL, NULL);
        Py_INCREF(FoolibError);
        PyModule_AddObject(m, "error", FoolibError);
        return;
    }
}
