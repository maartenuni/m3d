
#pragma once

#include <pybind11/pybind11.h>

namespace py = pybind11;

void init_py_nvec(py::module_&);
void init_py_vector(py::module_&);
void init_py_vector_functions(py::module_&);
