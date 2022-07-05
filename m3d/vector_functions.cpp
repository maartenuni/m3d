
#include "vector_functions.hpp"

namespace m3d {

    // distance between Vectors of double 2,3,4

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
    
    // distance between Vectors float 2,3,4
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

    // distance between NVecs of float and double   
    template NVec<double>::value_type distance(
            const NVec<double>&,
            const NVec<double>&
            );
    template NVec<float>::value_type distance(
            const NVec<float>&,
            const NVec<float>&
            );

    // Cross product for Vectors of float and double with length 3
    template Vector<double, 3> cross (
            const Vector<double, 3>& lhs,
            const Vector<double, 3>& rhs
            ) noexcept;
    template Vector<float, 3> cross (
            const Vector<float, 3>& lhs,
            const Vector<float, 3>& rhs
            ) noexcept;

    // Compute angles between Vectors of double 2,3,4
    template Vector<double, 2>::value_type angle(
            const Vector<double, 2>&,
            const Vector<double, 2>&
            ) noexcept;
    template Vector<double, 3>::value_type angle(
            const Vector<double, 3>&,
            const Vector<double, 3>&
            ) noexcept;
    template Vector<double, 4>::value_type angle(
            const Vector<double, 4>&,
            const Vector<double, 4>&
            ) noexcept;
    
    // Compute angles between Vectors of float 2,3,4
    template Vector<float, 2>::value_type angle(
            const Vector<float, 2>&,
            const Vector<float, 2>&
            ) noexcept;
    template Vector<float, 3>::value_type angle(
            const Vector<float, 3>&,
            const Vector<float, 3>&
            ) noexcept;
    template Vector<float, 4>::value_type angle(
            const Vector<float, 4>&,
            const Vector<float, 4>&
            ) noexcept;
    
    // Compute angles in degrees between Vectors of double 2,3,4
    template Vector<double, 2>::value_type angle_deg(
            const Vector<double, 2>&,
            const Vector<double, 2>&
            ) noexcept;
    template Vector<double, 3>::value_type angle_deg(
            const Vector<double, 3>&,
            const Vector<double, 3>&
            ) noexcept;
    template Vector<double, 4>::value_type angle_deg(
            const Vector<double, 4>&,
            const Vector<double, 4>&
            ) noexcept;
    
    
    // Compute angles in degrees between Vectors of float 2,3,4
    template Vector<float, 2>::value_type angle_deg(
            const Vector<float, 2>&,
            const Vector<float, 2>&
            ) noexcept;
    template Vector<float, 3>::value_type angle_deg(
            const Vector<float, 3>&,
            const Vector<float, 3>&
            ) noexcept;
    template Vector<float, 4>::value_type angle_deg(
            const Vector<float, 4>&,
            const Vector<float, 4>&
            ) noexcept;

    // Compute angle of NVec double and float
    template NVec<double>::value_type angle(
            const NVec<double>&,
            const NVec<double>&
            );
    template NVec<float>::value_type angle(
            const NVec<float>&,
            const NVec<float>&
            );
    
    // Compute angle in degrees of NVec double and float
    template NVec<double>::value_type angle_deg(
            const NVec<double>&,
            const NVec<double>&
            );
    template NVec<float>::value_type angle_deg(
            const NVec<float>&,
            const NVec<float>&
            );
}
