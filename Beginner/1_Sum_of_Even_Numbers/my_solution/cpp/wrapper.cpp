#include <Python.h>
#include "sum_of_even_numbers.hpp"
#include <vector>

static PyObject* sum_of_even_numbers_cpp(PyObject* self, PyObject* args) {
    PyObject* pyList;
    
    if (!PyArg_ParseTuple(args, "O", &pyList)) {
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }

    if (!PyList_Check(pyList)) {
        PyErr_SetString(PyExc_TypeError, "Argument must be a list");
        return nullptr;
    }

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

    return PyLong_FromLong(sumOfEvenNumbers(int_list));
}

static PyMethodDef myMethods[] = {
    {"sum_of_even_numbers", sum_of_even_numbers_cpp, METH_VARARGS, "Calc sum of even numbers from a list"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "sum_of_even_numbers",
    "Sum of even numbers from a list",
    -1,
    myMethods
};

PyMODINIT_FUNC PyInit_CPythonLearn1()
{
    return PyModule_Create(&myModule);
}
