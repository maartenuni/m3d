
#pragma once

#include "Vector.hpp"
#include "NVec.hpp"

namespace m3d {

    template<typename T, size_t size>
    typename Vector<T, size>::value_type
    distance(const Vector<T, size>& lhs, const Vector<T, size>& rhs) noexcept {
        return (rhs - lhs).magnitude();
    }

    extern template
        Vector<double, 2>::value_type distance(
            const Vector<double, 2>&,
            const Vector<double, 2>&
            ) noexcept;
    extern template
        Vector<double, 3>::value_type distance(
            const Vector<double, 3>&,
            const Vector<double, 3>&
            ) noexcept;
    extern template
        Vector<double, 4>::value_type distance(
            const Vector<double, 4>&,
            const Vector<double, 4>&
            ) noexcept;
    
    extern template
        Vector<float, 2>::value_type distance(
            const Vector<float, 2>&,
            const Vector<float, 2>&
            ) noexcept;
    extern template
        Vector<float, 3>::value_type distance(
            const Vector<float, 3>&,
            const Vector<float, 3>&
            ) noexcept;
    extern template
        Vector<float, 4>::value_type distance(
            const Vector<float, 4>&,
            const Vector<float, 4>&
            ) noexcept;

    template <typename T>
    typename NVec<T>::value_type
    distance(const NVec<T>& lhs, const NVec<T>& rhs)
    {
        if (lhs.size() != rhs.size())
            throw VectorSizeMismatch(lhs.size(), rhs.size());
        return (rhs - lhs).magnitude();
    }

    extern template
        NVec<double>::value_type distance(
            const NVec<double>&,
            const NVec<double>&
            );
    extern template
        NVec<float>::value_type distance(
            const NVec<float>&,
            const NVec<float>&
            );

    template <typename T>
    Vector<T, 3> cross(
            const Vector<T, 3>& lhs,
            const Vector<T, 3>& rhs) noexcept {
        Vector<T, 3> ret;
        ret[0] = lhs[1] * rhs[2] - lhs[2] * rhs[1];
        ret[1] = lhs[2] * rhs[0] - lhs[0] * rhs[2];
        ret[2] = lhs[0] * rhs[1] - lhs[1] * rhs[0];
        return ret;
    }
    
    extern template Vector<double, 3> cross (
            const Vector<double, 3>& lhs,
            const Vector<double, 3>& rhs
            ) noexcept;
    extern template Vector<float, 3> cross (
            const Vector<float, 3>& lhs,
            const Vector<float, 3>& rhs
            ) noexcept;

}
