
#include <pybind11/pybind11.h>
#include <sstream>

#include "pyvec.hpp"

#include <m3d/NVec.hpp>
#include <m3d/Vector.hpp>

namespace py = pybind11;

typedef m3d::NVec<double> NVec;

PYBIND11_MODULE(vector, m) {

    m.doc() = "A python wrapper for vector like objects, using the m3d library";

    init_py_nvec(m);
    init_py_vector(m);

}
