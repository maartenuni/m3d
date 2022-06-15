
#include <pybind11/pybind11.h>
#include "pybind11/attr.h"
#include "pybind11/cast.h"
#include "pybind11/detail/common.h"
#include "pybind11/pytypes.h"
#include "pyvec.hpp"
#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <sstream>

#include <m3d/NVec.hpp>
#include <m3d/Vector.hpp>

namespace py = pybind11;

typedef m3d::NVec<double> NVec;

void init_py_nvec(py::module_& m) {

    py::class_<NVec>(m, "NVec", "A dynamic vector of double precision floating point numbers")
        .def(py::init())
        .def(py::init(
                    [](py::list list) {
                        NVec ret;
                        ret.reserve(list.size());
                        for (auto value : list)
                            ret.push_back(py::cast<double>(value));
                        return ret;
                    }
                )
        )
        .def(py::init(
                    [](py::iterable iter) {
                        NVec ret;
                        ret.reserve(py::len(iter));
                        for (auto value :  iter)
                            ret.push_back(py::cast<double>(value));
                        return ret;
                    }
                )
        )
        .def("append",
             py::overload_cast<NVec::const_reference>(&NVec::push_back),
             "append a value to the vector increasing its size"
             )
        .def("__repr__", [](const NVec& self) {
                std::stringstream stream("");
                stream << "NVec(" << self << ")";
                return stream.str();
            },
            "Return the repr of a NVec class"
        )
        .def("magnitude", &NVec::magnitude)
        .def("unit", &NVec::unit)
        .def(py::self + py::self)
        .def(py::self + NVec::value_type())
        .def(NVec::value_type() + py::self)
        .def(py::self += py::self)
        .def(py::self += NVec::value_type())
        .def(py::self - py::self)
        .def(py::self - NVec::value_type())
        .def(py::self -= py::self)
        .def(py::self -= NVec::value_type())
        .def(py::self * py::self)
        .def(py::self * NVec::value_type())
        .def(py::self / NVec::value_type())
        .def(NVec::value_type() * py::self)
        .def(-py::self)
        ;
}
