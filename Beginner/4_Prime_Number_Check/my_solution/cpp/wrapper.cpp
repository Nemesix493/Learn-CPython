#include <Python.h>
#include "prime_number_check.hpp"

static PyObject* primeNumberCheckCpp(PyObject* self, PyObject* args)
{
    PyObject* pyInt;

    if(!PyArg_ParseTuple(args, "O", &pyInt))
    {
        // Raise exception if no arguments
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }

    // check pyInt is a int
    if(!PyLong_Check(pyInt))
    {
        // raise exception if pyInt is not a int
        PyErr_SetString(PyExc_TypeError, "Argument must be a int");
        return nullptr;
    }
    
    if(primeNumberCheck(PyLong_AsLong(pyInt)))
    {
        return Py_True;
    }
    else
    {
        return Py_False;
    }
}

// Define methods
static PyMethodDef myMethods[] = {
    {"prime_number_check", primeNumberCheckCpp, METH_VARARGS, "Calc check if a numbber is a prime number (int)"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "prime_number_check",
    "Calc check if a numbber is a prime number (int)",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn4()
{
    return PyModule_Create(&myModule);
}
