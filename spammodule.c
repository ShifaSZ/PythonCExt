#include "Python.h"
static PyObject *
spam_system(PyObject *self, PyObject *args);
static PyObject *
http_get(PyObject *self, PyObject *args);
char * http_get_data();

static PyObject *SpamError;

static PyMethodDef SpamMethods[] = {
    {"system",  spam_system, METH_VARARGS,
     "Execute a shell command."},
    {"get", http_get, METH_VARARGS, "Call a Rest API"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initspam(void)
{
    PyObject *m;

    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL)
        return;

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
}

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;

    sts = system(command);

    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }

    return PyLong_FromLong(sts);
}

static PyObject *
http_get(PyObject *self, PyObject *args)
{
    char *rsp = http_get_data();
    PyObject *ret = Py_BuildValue("s", rsp);
    if (NULL != rsp)
        free(rsp);
    return ret;
}

