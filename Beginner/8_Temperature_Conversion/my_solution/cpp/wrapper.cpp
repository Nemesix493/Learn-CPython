#include <Python.h>
#include "temperature_conversion.hpp"

static PyObject* temperatureConversionCpp(PyObject* self, PyObject* args)
{
    double celsius_temperature;
    if (!PyArg_ParseTuple(args, "d", &celsius_temperature))
    {
        PyErr_SetString(PyExc_TypeError, "Invalid arguments");
        return nullptr;
    }

    return PyFloat_FromDouble(
        temperatureConversion(celsius_temperature)
    );
}

static PyMethodDef myMethods[] = {
    {"temperature_conversion", temperatureConversionCpp, METH_VARARGS, "Convert Celsius temperature to Fahrenheit temperature !"},
    {NULL, NULL, 0, NULL}
};

static PyModuleDef myModule = {
    PyModuleDef_HEAD_INIT,
    "temperature_conversion",
    "Convert Celsius temperature to Fahrenheit temperature !",
    -1,
    myMethods
};

PyMODINIT_FUNC PyInit_CPythonLearn8()
{
    return PyModule_Create(&myModule);
}