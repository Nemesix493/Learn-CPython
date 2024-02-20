#include <Python.h>
#include "password_validation.hpp"

static PyObject* passwordValidationCpp(PyObject* self, PyObject* args){
    PyObject* pyString;
    if (!PyArg_ParseTuple(args, "O", &pyString)){
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }
    if(!PyUnicode_Check(pyString)){
        PyErr_SetString(PyExc_TypeError, "Argument must be a string");
        return nullptr;
    }
    std::string passwordToCheck;
    Py_ssize_t passwordToCheck_size = PyUnicode_GET_LENGTH(pyString);
    for(Py_ssize_t i = 0; i < passwordToCheck_size ; i++)
    {
        passwordToCheck += PyUnicode_READ_CHAR(pyString, i);
    }
    if (passwordValidation(passwordToCheck)){
        return Py_True;
    }else{
        return Py_False;
    }

}

// Define methods
static PyMethodDef myMethods[] = {
    {"password_validation", passwordValidationCpp, METH_VARARGS, "Check if a password is valid !"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "password_validation",
    "Check if a password is valid !",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn12()
{
    return PyModule_Create(&myModule);
}
