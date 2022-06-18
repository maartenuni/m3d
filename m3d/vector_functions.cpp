
#include "vector_functions.hpp"

namespace m3d {
    template Vector<double, 2>::value_type distance(
            const Vector<double, 2>&,
            const Vector<double, 2>&
            ) noexcept;
    template Vector<double, 3>::value_type distance(
            const Vector<double, 3>&,
            const Vector<double, 3>&
            ) noexcept;
    template Vector<double, 4>::value_type distance(
            const Vector<double, 4>&,
            const Vector<double, 4>&
            ) noexcept;
    
    template Vector<float, 2>::value_type distance(
            const Vector<float, 2>&,
            const Vector<float, 2>&
            ) noexcept;
    template Vector<float, 3>::value_type distance(
            const Vector<float, 3>&,
            const Vector<float, 3>&
            ) noexcept;
    template Vector<float, 4>::value_type distance(
            const Vector<float, 4>&,
            const Vector<float, 4>&
            ) noexcept;
    
    template NVec<float>::value_type distance(
            const NVec<float>&,
            const NVec<float>&
            );
    template NVec<double>::value_type distance(
            const NVec<double>&,
            const NVec<double>&
            );
}
