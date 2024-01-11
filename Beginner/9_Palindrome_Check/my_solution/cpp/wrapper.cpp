#include <Python.h>
#include "palindrome_check.hpp"

static PyObject* palindromeCheckCpp(PyObject* self, PyObject* args){
    PyObject* pyString;
    if (!PyArg_ParseTuple(args, "O", &pyString)){
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }
    if(!PyUnicode_Check(pyString)){
        PyErr_SetString(PyExc_TypeError, "Argument must be a string");
        return nullptr;
    }
    std::string palindrom_to_check;
    Py_ssize_t palindrom_to_check_size = PyUnicode_GET_LENGTH(pyString);
    for(Py_ssize_t i = 0; i < palindrom_to_check_size ; i++)
    {
        palindrom_to_check += PyUnicode_READ_CHAR(pyString, i);
    }
    if (palindromeCheck(palindrom_to_check)){
        return Py_True;
    }else{
        return Py_False;
    }

}

// Define methods
static PyMethodDef myMethods[] = {
    {"palindrome_check", palindromeCheckCpp, METH_VARARGS, "Check if a string is a palindrome"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "palindrome_check",
    "Check if a string is a palindrome",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn9()
{
    return PyModule_Create(&myModule);
}
