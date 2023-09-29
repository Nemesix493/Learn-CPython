#include <Python.h>
#include "sum_of_even_numbers.hpp"
#include <vector>

static PyObject* sum_of_even_numbers_cpp(PyObject* self, PyObject* args) {

    // Extract function argument as pyList
    PyObject* pyList;
    
    if (!PyArg_ParseTuple(args, "O", &pyList)) {
        // Raise exception if no arguments
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }

    // Check pyList is a list
    if (!PyList_Check(pyList)) {
        // Raise exception if pyList is not a list
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

    // Return result of c function
    return PyLong_FromLong(sumOfEvenNumbers(int_list));
}

// Define python method
static PyMethodDef myMethods[] = {
    {"sum_of_even_numbers", sum_of_even_numbers_cpp, METH_VARARGS, "Calc sum of even numbers from a list"},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "sum_of_even_numbers",
    "Sum of even numbers from a list",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn1()
{
    return PyModule_Create(&myModule);
}
