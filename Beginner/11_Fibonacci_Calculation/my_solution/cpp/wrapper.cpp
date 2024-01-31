#include <Python.h>
#include "fibonacci_calculation.hpp"

static PyObject* fibonacciCalculationCpp(PyObject* self, PyObject* args){
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
    
    return PyLong_FromLong(
        fibonacciCalculation(PyLong_AsLong(pyInt))
    );
}

// Define methods
static PyMethodDef myMethods[] = {
    {"fibonacci_calculation", fibonacciCalculationCpp, METH_VARARGS, "Calculate the fibonacci for an index"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "fibonacci_calculation",
    "Calculate the fibonacci for an index",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn11()
{
    return PyModule_Create(&myModule);
}
