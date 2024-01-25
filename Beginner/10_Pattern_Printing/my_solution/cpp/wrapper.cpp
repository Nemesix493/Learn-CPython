#include <Python.h>
#include "get_pattern.hpp"

static PyObject* patternPrintingCpp(PyObject* self, PyObject* args){
    PyObject* python_pattern_name;
    if (!PyArg_ParseTuple(args, "O", &python_pattern_name)){
        PyErr_SetString(PyExc_TypeError, "Invalid argument");
        return nullptr;
    }
    if(!PyUnicode_Check(python_pattern_name)){
        PyErr_SetString(PyExc_TypeError, "Argument must be a string");
        return nullptr;
    }
    std::string pattern_name;
    Py_ssize_t pattern_name_size = PyUnicode_GET_LENGTH(python_pattern_name);
    for(Py_ssize_t i = 0; i < pattern_name_size ; i++)
    {
        pattern_name += PyUnicode_READ_CHAR(python_pattern_name, i);
    }
    try {
        // Call Print function.
        PyObject *builtins_package_name, *builtins_package, *python_print, *print_args, *print_kwargs, *print_value;
        std::string pattern = getPattern(pattern_name);
        print_value = PyUnicode_DecodeUTF8(pattern.c_str(), pattern.size(), "strict");

        // Load the built-in 'builtins' module
        builtins_package_name = PyUnicode_DecodeFSDefault("builtins");
        builtins_package = PyImport_Import(builtins_package_name);
        Py_XDECREF(builtins_package_name);

        // Get a reference to the 'print' function
        python_print = PyObject_GetAttrString(builtins_package, "print");

        // Create arguments for the 'print' function
        print_args = PyTuple_Pack(1, print_value);
        print_kwargs = PyDict_New();
        PyDict_SetItem(print_kwargs, PyUnicode_DecodeFSDefault("end"), PyUnicode_DecodeFSDefault(""));

        // Call the 'print' function 
        PyObject_Call(python_print, print_args, print_kwargs);
        Py_RETURN_NONE;
    } catch (const std::invalid_argument& e) {
        PyErr_SetString(PyExc_ValueError, e.what());
        return nullptr;
    }

}

// Define methods
static PyMethodDef myMethods[] = {
    {"pattern_printing", patternPrintingCpp, METH_VARARGS, "Print a ASCII pattern to drow"},
    {NULL, NULL, 0, NULL}
};

// Define module
static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "pattern_printing",
    "Print a ASCII pattern to drow",
    -1,
    myMethods
};

// Initialize module
PyMODINIT_FUNC PyInit_CPythonLearn10()
{
    return PyModule_Create(&myModule);
}
