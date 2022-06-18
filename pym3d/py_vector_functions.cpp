
#include<pybind11/pybind11.h>
#include<m3d/Vector.hpp>
#include<m3d/NVec.hpp>
#include<m3d/vector_functions.hpp>

namespace py = pybind11;

void init_py_vector_functions(py::module_& m) {

    using m3d::Vector4lf;
    using m3d::Vector3lf;
    using m3d::Vector2lf;

    using m3d::distance;
    using m3d::NVeclf;

    m.def("distance",
        [] (const Vector4lf& lhs, const Vector4lf& rhs) {return distance(lhs, rhs);},
        "A function that calculates the distance between 2 4-dimensional points."
    );
    m.def("distance",
        [] (const Vector3lf& lhs, const Vector3lf& rhs) {return distance(lhs, rhs);},
        "A function that calculates the distance between 2 3-dimensional points."
    );
    m.def("distance",
        [] (const Vector2lf& lhs, const Vector2lf& rhs) {return distance(lhs, rhs);},
        "A function that calculates the distance between 2 2-dimensional points."
    );
    
    m.def("distance",
        [] (const NVeclf& lhs, const NVeclf& rhs) {return distance(lhs, rhs);},
        "A fuction that calculates the distance between two n-dimensional points."
    );

}
