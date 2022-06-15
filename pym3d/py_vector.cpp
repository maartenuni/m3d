
#include <pybind11/pybind11.h>
#include "pybind11/attr.h"
#include "pybind11/cast.h"
#include "pybind11/detail/common.h"
#include "pybind11/pytypes.h"
#include <pybind11/operators.h>
#include <pybind11/stl.h>
#include <sstream>

#include <m3d/Vector.hpp>

namespace py = pybind11;


void init_py_vector(py::module_& m) {

    using m3d::Vector4lf;
    using m3d::Vector3lf;
    using m3d::Vector2lf;

    py::class_<Vector4lf> (m, "Vector4", "A vector with 4 double precision dimensions")
        .def(py::init(
                [](
                    Vector4lf::value_type x,
                    Vector4lf::value_type y,
                    Vector4lf::value_type z,
                    Vector4lf::value_type w
                  ) {
                    Vector4lf ret{x, y, z, w};
                    return ret;
                }
            ),
            py::arg("x_r") = 0,
            py::arg("y_g") = 0,
            py::arg("z_b") = 0,
            py::arg("w_a") = 0
        )
        .def(py::init(
                [](py::list input) {
                    Vector4lf ret{};

                    for (Vector4lf::size_type i = 0; i < std::min(ret.size(), input.size()); i++) {
                        ret[i] = py::cast<Vector4lf::value_type>(input[i]);
                    }
                    return ret;
                })
        )
        .def_property(
                "x",
                [](const Vector4lf& self){return self[0];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[0] = value;}
        )
        .def_property(
                "y",
                [](const Vector4lf& self){return self[1];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[1] = value;}
        )
        .def_property(
                "z",
                [](const Vector4lf& self){return self[3];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[3] = value;}
        )
        .def_property(
                "w",
                [](const Vector4lf& self){return self[3];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[3] = value;}
        )
        .def_property(
                "r",
                [](const Vector4lf& self){return self[0];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[0] = value;}
        )
        .def_property(
                "g",
                [](const Vector4lf& self){return self[1];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[1] = value;}
        )
        .def_property(
                "b",
                [](const Vector4lf& self){return self[3];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[3] = value;}
        )
        .def_property(
                "a",
                [](const Vector4lf& self){return self[3];},
                [](Vector4lf& self, Vector4lf::const_reference value){self[3] = value;}
        )
        .def("__repr__", [](const Vector4lf& self) {
                std::stringstream stream("");
                stream << "Vector4(" << self << ")";
                return stream.str();
            },
            "Return the repr of a Vector4 class"
        )
        .def("magnitude", &Vector4lf::magnitude)
        .def("unit", &Vector4lf::unit)
        // arithmetic operators
        .def(py::self + py::self)
        .def(py::self + Vector4lf::value_type())
        .def(Vector4lf::value_type() + py::self)
        .def(py::self += py::self)
        .def(py::self += Vector4lf::value_type())
        .def(py::self - py::self)
        .def(py::self - Vector4lf::value_type())
        .def(py::self -= py::self)
        .def(py::self -= Vector4lf::value_type())
        .def(py::self * py::self)
        .def(py::self * Vector4lf::value_type())
        .def(py::self / Vector4lf::value_type())
        .def(Vector4lf::value_type() * py::self)
        .def(-py::self)
        // equality operators
        .def(py::self == py::self)
        .def(py::self != py::self)
        // element access operators
        .def("__getitem__",
             [](Vector4lf& vec, Vector4lf::size_type i){return vec.at(i);},
             py::arg("i"),
             py::is_operator()
        )
        .def("__setitem__",
             [](Vector4lf& vec, Vector4lf::size_type i, Vector4lf::value_type val){
                 return vec.at(i) = val;
             },
             py::arg("i"),
             py::arg("value"),
             py::is_operator()
        )
        ;

    py::class_<Vector3lf> (m, "Vector3", "A vector with 3 double precision dimensions")
        .def(py::init(
                [](
                    Vector3lf::value_type x,
                    Vector3lf::value_type y,
                    Vector3lf::value_type z
                  ) {
                    Vector3lf ret{x, y, z};
                    return ret;
                }
            ),
            py::arg("x_r") = 0,
            py::arg("y_g") = 0,
            py::arg("z_b") = 0
        )
        .def(py::init(
                [](py::list input) {
                    Vector3lf ret{};

                    for (Vector3lf::size_type i = 0; i < std::min(ret.size(), input.size()); i++) {
                        ret[i] = py::cast<Vector3lf::value_type>(input[i]);
                    }
                    return ret;
                })
        )
        .def_property(
                "x",
                [](const Vector3lf& self){return self[0];},
                [](Vector3lf& self, Vector3lf::const_reference value){self[0] = value;}
        )
        .def_property(
                "y",
                [](const Vector3lf& self){return self[1];},
                [](Vector3lf& self, Vector3lf::const_reference value){self[1] = value;}
        )
        .def_property(
                "z",
                [](const Vector3lf& self){return self[3];},
                [](Vector3lf& self, Vector3lf::const_reference value){self[3] = value;}
        )
        .def_property(
                "r",
                [](const Vector3lf& self){return self[0];},
                [](Vector3lf& self, Vector3lf::const_reference value){self[0] = value;}
        )
        .def_property(
                "g",
                [](const Vector3lf& self){return self[1];},
                [](Vector3lf& self, Vector3lf::const_reference value){self[1] = value;}
        )
        .def_property(
                "b",
                [](const Vector3lf& self){return self[3];},
                [](Vector3lf& self, Vector3lf::const_reference value){self[3] = value;}
        )
        .def("__repr__", [](const Vector3lf& self) {
                std::stringstream stream("");
                stream << "Vector3(" << self << ")";
                return stream.str();
            },
            "Return the repr of a Vector3 class"
        )
        .def("magnitude", &Vector3lf::magnitude)
        .def("unit", &Vector3lf::unit)
        // arithmetic operators
        .def(py::self + py::self)
        .def(py::self + Vector3lf::value_type())
        .def(Vector3lf::value_type() + py::self)
        .def(py::self += py::self)
        .def(py::self += Vector3lf::value_type())
        .def(py::self - py::self)
        .def(py::self - Vector3lf::value_type())
        .def(py::self -= py::self)
        .def(py::self -= Vector3lf::value_type())
        .def(py::self * py::self)
        .def(py::self * Vector3lf::value_type())
        .def(py::self / Vector3lf::value_type())
        .def(Vector3lf::value_type() * py::self)
        .def(-py::self)
        // equality operators
        .def(py::self == py::self)
        .def(py::self != py::self)
        // element access operators
        .def("__getitem__",
             [](Vector3lf& vec, Vector3lf::size_type i){return vec.at(i);},
             py::arg("i"),
             py::is_operator()
        )
        .def("__setitem__",
             [](Vector3lf& vec, Vector4lf::size_type i, Vector3lf::value_type val){
                 return vec.at(i) = val;
             },
             py::arg("i"),
             py::arg("value"),
             py::is_operator()
        )
        ;
    
    py::class_<Vector2lf> (m, "Vector2", "A vector with 2 double precision dimensions")
        .def(py::init(
                [](
                    Vector2lf::value_type x,
                    Vector2lf::value_type y
                  ) {
                    Vector2lf ret{x, y};
                    return ret;
                }
            ),
            py::arg("x") = 0,
            py::arg("y") = 0
        )
        .def(py::init(
                [](py::list input) {
                    Vector2lf ret{};

                    for (Vector2lf::size_type i = 0; i < std::min(ret.size(), input.size()); i++) {
                        ret[i] = py::cast<Vector2lf::value_type>(input[i]);
                    }
                    return ret;
                })
        )
        .def_property(
                "x",
                [](const Vector2lf& self){return self[0];},
                [](Vector2lf& self, Vector2lf::const_reference value){self[0] = value;}
        )
        .def_property(
                "y",
                [](const Vector2lf& self){return self[1];},
                [](Vector2lf& self, Vector2lf::const_reference value){self[1] = value;}
        )
        .def("__repr__", [](const Vector2lf& self) {
                std::stringstream stream("");
                stream << "Vector2(" << self << ")";
                return stream.str();
            },
            "Return the repr of a Vector2 class"
        )
        .def("magnitude", &Vector2lf::magnitude)
        .def("unit", &Vector2lf::unit)
        // arithmetic operators
        .def(py::self + py::self)
        .def(py::self + Vector2lf::value_type())
        .def(Vector2lf::value_type() + py::self)
        .def(py::self += py::self)
        .def(py::self += Vector2lf::value_type())
        .def(py::self - py::self)
        .def(py::self - Vector2lf::value_type())
        .def(py::self -= py::self)
        .def(py::self -= Vector2lf::value_type())
        .def(py::self * py::self)
        .def(py::self * Vector2lf::value_type())
        .def(py::self / Vector2lf::value_type())
        .def(Vector2lf::value_type() * py::self)
        .def(-py::self)
        // equality operators
        .def(py::self == py::self)
        .def(py::self != py::self)
        // element access operators
        .def("__getitem__",
             [](Vector2lf& vec, Vector2lf::size_type i){return vec.at(i);},
             py::arg("i"),
             py::is_operator()
        )
        .def("__setitem__",
             [](Vector2lf& vec, Vector4lf::size_type i, Vector2lf::value_type val){
                 return vec.at(i) = val;
             },
             py::arg("i"),
             py::arg("value"),
             py::is_operator()
        )
        ;

}
