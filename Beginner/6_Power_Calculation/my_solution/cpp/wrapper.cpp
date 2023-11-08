#include <Python.h>
#include "power_calculation.hpp"

static PyObject* powerCalculationCpp(PyObject* self, PyObject* args)
{
    int base, exponent;

    if(!PyArg_ParseTuple(args, "ii", &base, &exponent))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments");
        return nullptr;
    }
    
    return PyLong_FromLongLong(
        powerCalculation(base, exponent)
    );
}

// Define methods
static PyMethodDef myMethods[] = {
    {"power_calculation", powerCalculationCpp, METH_VARARGS, "Calc the base raised to the power of the exponent"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "power_calculation",
    "Calc the base raised to the power of the exponent",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn6()
{
    return PyModule_Create(&myModule);
}