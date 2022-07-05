
#include<pybind11/pybind11.h>
#include<m3d/Vector.hpp>
#include<m3d/NVec.hpp>
#include<m3d/vector_functions.hpp>

namespace py = pybind11;

void init_py_vector_functions(py::module_& m) {

    using m3d::Vector4lf;
    using m3d::Vector3lf;
    using m3d::Vector2lf;
    using m3d::NVeclf;

    using m3d::distance;
    using m3d::cross;

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

    m.def("cross",
        [] (const Vector3lf& lhs, const Vector3lf& rhs) {return cross(lhs, rhs);},
        "Return the cross product of 2 three dimensional vectors"
    );

    m.def("angle",
        [](const Vector2lf& lhs, const Vector2lf& rhs) {return angle(lhs, rhs);},
        "Returns the angle between 2 2D vectors"
    );
    m.def("angle",
        [](const Vector3lf& lhs, const Vector3lf& rhs) {return angle(lhs, rhs);},
        "Returns the angle between 2 3D vectors"
    );
    m.def("angle",
        [](const Vector4lf& lhs, const Vector4lf& rhs) {return angle(lhs, rhs);},
        "Returns the angle between 2 4D vectors"
    );
    m.def("angle",
        [](const NVeclf& lhs, const NVeclf& rhs) {return angle(lhs, rhs);},
        "Returns the angle between 2 NVecs with the same number of dimensions"
    );
    
    m.def("angle_deg",
        [](const Vector2lf& lhs, const Vector2lf& rhs) {return angle_deg(lhs, rhs);},
        "Returns the angle in degrees between 2 2D vectors"
    );
    m.def("angle_deg",
        [](const Vector3lf& lhs, const Vector3lf& rhs) {return angle_deg(lhs, rhs);},
        "Returns the angle in degrees between 2 3D vectors"
    );
    m.def("angle_deg",
        [](const Vector4lf& lhs, const Vector4lf& rhs) {return angle_deg(lhs, rhs);},
        "Returns the angle in degrees between 2 4D vectors"
    );
    m.def("angle_deg",
        [](const NVeclf& lhs, const NVeclf& rhs) {return angle_deg(lhs, rhs);},
        "Returns the angle in degrees between 2 NVecs with the same number of dimensions"
    );


}
