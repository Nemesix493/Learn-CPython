#include <Python.h>
#include "average_calculation.hpp"
#include <vector>

static PyObject* averageCalculationCpp(PyObject* self, PyObject* args) {

    PyObject* pyList;
    
    if (!PyArg_ParseTuple(args, "O", &pyList)) {
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }

    if (!PyList_Check(pyList)) {
        PyErr_SetString(PyExc_TypeError, "Argument must be a list");
        return nullptr;
    }

    // Extract integers from pyList to populate an integer vector (int).
    std::vector<int> int_list;
    Py_ssize_t listSize = PyList_Size(pyList);
    for (Py_ssize_t i = 0; i < listSize; ++i) {
        PyObject* item = PyList_GetItem(pyList, i);
        if (PyLong_Check(item)) {
            int value = PyLong_AsLong(item);
            int_list.push_back(value);
        } else {
            PyErr_SetString(PyExc_TypeError, "List must contain integers");
            return nullptr;
        }
    }

    return PyFloat_FromDouble(averageCalculation(int_list));
}

// Define python method
static PyMethodDef myMethods[] = {
    {"average_calculation", averageCalculationCpp, METH_VARARGS, "Calc average of a list of integers"},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "average_calculation",
    "Calc average of a list of integers",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn7()
{
    return PyModule_Create(&myModule);
}