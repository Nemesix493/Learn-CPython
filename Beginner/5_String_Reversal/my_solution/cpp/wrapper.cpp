#include <Python.h>
#include "string_reverse.hpp"
#include <string>

static PyObject* stringReverseCpp(PyObject* self, PyObject* args)
{

    // Extract function argument as pyString
    PyObject* pyString;

    if (!PyArg_ParseTuple(args, "O", &pyString))
    {
        // Raise exception if no arguments
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }

    // Check pyString is a string
    if(!PyUnicode_Check(pyString))
    {
        // Raise exception if pyString is not a string
        PyErr_SetString(PyExc_TypeError, "Argument must be a string");
        return nullptr;
    }
    
    // Extract chars from pyString to populate an string
    std::string original_string;
    Py_ssize_t original_string_size = PyUnicode_GET_LENGTH(pyString);
    for(Py_ssize_t i = 0; i < original_string_size ; i++)
    {
        original_string += PyUnicode_READ_CHAR(pyString, i);
    }

    // Return result of c function
    std::string string_result = stringReverse(original_string);
    return PyUnicode_DecodeUTF8(string_result.c_str(), string_result.size(), "strict");
}

// Define python method
static PyMethodDef myMethods[] = {
    {"string_reverse", stringReverseCpp, METH_VARARGS, "Reverse a string"},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "string_reverse",
    "Reverse a string",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn5()
{
    return PyModule_Create(&myModule);
}