
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

}
