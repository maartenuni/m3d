
#pragma once

#include <stdexcept>
#include <cmath>
#include <string>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <exception>
#include <iostream>

namespace m3d {

    template<typename T, size_t length>
    struct Vector;

    template <typename T, size_t length>
    Vector<T, length> operator+(T lhs, const Vector<T, length>& rhs) noexcept;
    
    template <typename T, size_t length>
    Vector<T, length> operator-(T lhs, const Vector<T, length>& rhs) noexcept;


    /**
     * VectorLike class with an arbitrary number of dimensions which
     * is allowed to grow dynamically.
     */
    template<class numtype, size_t n>
    struct Vector {

            std::array<numtype, n> m_data;

            typedef typename std::array<numtype, n>::value_type       value_type;

            typedef typename std::array<numtype, n>::pointer          pointer;
            typedef typename std::array<numtype, n>::const_pointer    const_pointer;

            typedef typename std::array<numtype, n>::iterator         iterator;
            typedef typename std::array<numtype, n>::const_iterator   const_iterator;

            typedef typename std::array<numtype, n>::reference        reference;
            typedef typename std::array<numtype, n>::const_reference  const_reference;

            typedef typename std::array<numtype, n>::size_type        size_type;
            typedef typename std::array<numtype, n>::difference_type  difference_type;

            iterator        begin()         {return m_data.begin();}
            iterator        end()           {return m_data.end();}
            const_iterator  cbegin() const  {return m_data.begin();}
            const_iterator  cend()   const  {return m_data.end();}

            constexpr size_type size() const noexcept
            {
                return n;
            }

            /* support for overloading aritmetic operators */

            template<class T>
            friend Vector<value_type, n> operator+(value_type, const Vector<value_type, n>&) noexcept;
            template<class T>
            friend Vector<value_type, n> operator*(value_type, const Vector<value_type, n>&) noexcept;
            
            Vector<value_type, n> operator+(const Vector<value_type, n>& rhs) const
            {
                Vector<value_type, n> retval;
                std::transform(cbegin(), cend(),
                        rhs.cbegin(),
                        retval.begin(),
                        std::plus<value_type>()
                    );
                return retval;
            }
            
            Vector<value_type, n> operator+(value_type rhs) const noexcept
            {
                Vector<value_type, n> retval;
                std::transform(
                        cbegin(), cend(),
                        retval.begin(),
                        [rhs](value_type val){return val + rhs;}
                    );
                return retval;
            }

            Vector<value_type, n>& operator += (const Vector<value_type, n>& rhs) 
            {
                std::transform(
                        cbegin(), cend(),
                        rhs.cbegin(),
                        begin(),
                        std::plus<value_type>()
                        );
                return *this;
            }

            Vector<value_type, n>& operator += (const_reference rhs) noexcept
            {
                for (auto& value : *this)
                    value += rhs;
                return *this;
            }
            
            Vector<value_type, n> operator-(const Vector<value_type, n>& rhs) const
            {
                Vector<value_type, n> retval;
                std::transform(cbegin(), cend(),
                        rhs.cbegin(),
                        retval.begin(),
                        std::minus<value_type>()
                    );
                return retval;
            }
            
            Vector<value_type, n> operator-(value_type rhs) const noexcept
            {
                Vector<value_type, n> retval;
                std::transform(
                        cbegin(), cend(),
                        retval.begin(),
                        [rhs](value_type val){return val - rhs;}
                    );
                return retval;
            }

            Vector<value_type, n>& operator-= (const Vector<value_type, n>& rhs)
            {
                std::transform(
                        cbegin(), cend(),
                        rhs.cbegin(),
                        begin(),
                        std::minus<value_type>()
                        );
                return *this;
            }
            
            Vector<value_type, n>& operator-= (value_type rhs) noexcept
            {
                for (auto& value : *this)
                    value -= rhs;
                return *this;
            }
            
            Vector<value_type, n> operator* (value_type rhs) const noexcept
            {
                Vector ret;
                std::transform(
                        cbegin(), cend(),
                        ret.begin(),
                        [rhs] (value_type val) { return val * rhs;}
                        );

                return ret;
            }

            value_type operator* (const Vector<value_type, n>& rhs) const
            {
                return std::inner_product(
                    cbegin(), cend(),
                    rhs.cbegin(),
                    value_type(0),
                    std::plus<value_type>(),
                    std::multiplies<value_type>()
                );
            }

            Vector<value_type, n> operator/ (value_type rhs) const noexcept
            {
                Vector ret;
                std::transform(
                        cbegin(), cend(),
                        ret.begin(),
                        [rhs] (value_type val) {return val / rhs;}
                        );

                return ret;
            }

            Vector<value_type, n> operator-() const noexcept {
                Vector<value_type, n> ret;
                std::transform(
                        cbegin(), cend(),
                        ret.begin(),
                        [](const_reference value) {return -value;}
                        );
                return ret;
            }

            /* element access */

            reference operator[](size_type i) noexcept {
                return m_data[i];
            }
            
            const_reference operator[](size_type i) const noexcept {
                return m_data[i];
            }

            reference at(size_type i)
            {
                return m_data.at(i);
            }

            const_reference at(size_type i) const
            {
                return m_data.at(i);
            }

            /* object equality */

            bool operator==(const Vector<value_type, n>& rhs) const noexcept
            {
                return m_data == rhs.m_data;
            }

            bool operator!=(const Vector<value_type, n>& rhs) const noexcept
            {
                return !(*this == rhs);
            }

            bool operator<(const Vector<value_type, n>& rhs) const noexcept
            {
                return this->m_data < rhs.m_data;
            }

            bool operator>(const Vector<value_type, n>& rhs) const noexcept
            {
                return (rhs < *this);
            }

            bool operator <= (const Vector<value_type, n>& rhs) const noexcept
            {
                return !(rhs < *this);
            }

            bool operator>=(const Vector<value_type, n>& rhs) const noexcept
            {
                return !(*this < rhs);
            }

            /* Some simple aritmetics on the vector */

            value_type magnitude() const noexcept
            {
                return std::sqrt(
                    std::accumulate(
                        cbegin(), cend(),
                        value_type(0),
                        [](const_reference start, const_reference val) {
                            return start + val*val;
                        }
                    )
                );
            }

            Vector<value_type, n> unit() const
            {
                return *this/magnitude();
            }

    };

    template<class numtype, size_t n>
    std::ostream& operator<< (std::ostream& stream,
                              const Vector<numtype, n>& vec)
    {
        std::string out("[");
        typename Vector<numtype, n>::size_type i;
        static_assert(n > 0, "Empty Vectors are not supported");

        for (i = 0; i < vec.size() - 1; i++)
            out += std::to_string(vec[i]) + ", ";
        for ( ; i < vec.size(); i++)
            out += std::to_string(vec[i]);

        out += "]";
        return stream << out;
    }

    template<class T, size_t n>
    Vector<T, n> operator + (T lhs, const Vector<T, n>& rhs) noexcept {
        return rhs + lhs;
    }
    
    template<class T, size_t n>
    Vector<T, n> operator * (T lhs, const Vector<T, n>& rhs) noexcept {
        return rhs * lhs;
    }

    /*
     * These templates are instantiated in the library
     */
    extern template struct Vector<double, 2>;
    extern template struct Vector<double, 3>;
    extern template struct Vector<double, 4>;

    extern template struct Vector<float, 2>;
    extern template struct Vector<float, 3>;
    extern template struct Vector<float, 4>;

    typedef Vector<double, 2> Vector2lf;
    typedef Vector<double, 3> Vector3lf;
    typedef Vector<double, 4> Vector4lf;

    typedef Vector<float, 2> Vector2f;
    typedef Vector<float, 3> Vector3f;
    typedef Vector<float, 4> Vector4f;

}
