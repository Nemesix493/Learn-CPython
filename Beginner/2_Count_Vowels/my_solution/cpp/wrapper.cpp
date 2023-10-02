#include <Python.h>
#include "count_vowels.hpp"
#include <string>

static PyObject* count_vowels_cpp(PyObject* self, PyObject* args)
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
    std::string string_to_count;
    Py_ssize_t string_to_count_size = PyUnicode_GET_LENGTH(pyString);
    for(Py_ssize_t i = 0; i < string_to_count_size ; i++)
    {
        string_to_count += PyUnicode_READ_CHAR(pyString, i);
    }

    // Return result of c function
    return PyLong_FromLong(countVowels(string_to_count));
}

// Define python method
static PyMethodDef myMethods[] = {
    {"count_vowels", count_vowels_cpp, METH_VARARGS, "Count vowels in a string"},
    {NULL, NULL, 0, NULL}
};

// Define module
static struct PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "count_vowels",
    "Count vowels in a string",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn2()
{
    return PyModule_Create(&myModule);
}
