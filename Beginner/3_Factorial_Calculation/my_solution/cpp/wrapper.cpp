#include <Python.h>
#include "factorial_calculation.hpp"

static PyObject* factorialCalculationCpp(PyObject* self, PyObject* args)
{
    PyObject* pyInt;

    if(!PyArg_ParseTuple(args, "0", &pyInt))
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
        factorialCalculation(PyLong_AsLong(pyInt))
    );
}

// Define methods
static PyMethodDef myMethods[] = {
    {"factorial_calculation", factorialCalculationCpp, METH_VARARGS, "Calc factorial of a number (int)"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "factorial_calculation",
    "Calc factorial of a number (int)",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn3()
{
    return PyModule_Create(&myModule);
}