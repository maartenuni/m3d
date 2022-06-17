
#pragma once

#include <stdexcept>
#include <vector>
#include <cmath>
#include <string>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>
#include <exception>

namespace m3d {


    class VectorSizeMismatch : public std::exception {
        public:

            VectorSizeMismatch(size_t size1, size_t size2)
            {
                msg = "NVec size mismatch:";
                msg += "lhs.size() = " + std::to_string(size1) + " and ";
                msg += "rhs.size() = " + std::to_string(size2);
            }

            const char* what() const noexcept
            {
                return msg.c_str();
            }

        private:
            std::string msg;

    };

    template<typename T>
    class NVec;

    template <typename T>
    NVec<T> operator+(T lhs, const NVec<T>& rhs) noexcept;
    
    template <typename T>
    NVec<T> operator-(T lhs, const NVec<T>& rhs) noexcept;


    /**
     * VectorLike class with an arbitrary number of dimensions which
     * is allowed to grow dynamically.
     */
    template<class numtype=double>
    class NVec {

        private:

            std::vector<numtype> m_data;

        public:

            typedef typename std::vector<numtype>::value_type       value_type;

            typedef typename std::vector<numtype>::pointer          pointer;
            typedef typename std::vector<numtype>::const_pointer    const_pointer;

            typedef typename std::vector<numtype>::iterator         iterator;
            typedef typename std::vector<numtype>::const_iterator   const_iterator;

            typedef typename std::vector<numtype>::reference        reference;
            typedef typename std::vector<numtype>::const_reference  const_reference;

            typedef typename std::vector<numtype>::size_type        size_type;
            typedef typename std::vector<numtype>::difference_type  difference_type;

            NVec() = default;

            NVec(size_type n)
                : m_data(n, 0)
            {
            }
            
            NVec(size_type n, value_type val)
                : m_data(n, val)
            {
            }
            
            template<class InputIt>
            NVec(InputIt begin, InputIt end)
                : m_data(begin, end)
            {
            }

            NVec(const std::initializer_list<value_type>& list)
                : m_data{list}
            {
            }

            iterator        begin()         {return m_data.begin();}
            iterator        end()           {return m_data.end();}
            const_iterator  cbegin() const  {return m_data.begin();}
            const_iterator  cend()   const  {return m_data.end();}

            size_type size() const noexcept
            {
                return m_data.size();
            }

            NVec<value_type> operator+(const NVec<value_type>& rhs) const
            {
                check_size(rhs);
                NVec<value_type> retval;
                retval.reserve(size());
                std::transform(cbegin(), cend(),
                        rhs.cbegin(),
                        std::back_inserter(retval),
                        std::plus<value_type>()
                    );
                return retval;
            }

            template<class T>
            friend NVec<value_type> operator+(value_type, const NVec<value_type>) noexcept;
            template<class T>
            friend NVec<value_type> operator*(value_type, const NVec<value_type>) noexcept;
            
            NVec<value_type> operator+(value_type rhs) const noexcept
            {
                NVec<value_type> retval;
                retval.reserve(size());
                std::transform(
                        cbegin(), cend(),
                        std::back_inserter(retval),
                        [rhs](value_type val){return val + rhs;}
                    );
                return retval;
            }

            NVec<value_type>& operator += (const NVec<value_type>& rhs) 
            {
                check_size(rhs);
                std::transform(
                        cbegin(), cend(),
                        rhs.cbegin(),
                        begin(),
                        std::plus<value_type>()
                        );
                return *this;
            }

            NVec<value_type>& operator += (value_type& rhs) noexcept
            {
                for (auto& value : *this)
                    value += rhs;
                return *this;
            }
            
            NVec<value_type> operator-(const NVec<value_type>& rhs) const
            {
                check_size(rhs);
                NVec<value_type> retval;
                retval.reserve(size());
                std::transform(cbegin(), cend(),
                        rhs.cbegin(),
                        std::back_inserter(retval),
                        std::minus<value_type>()
                    );
                return retval;
            }
            
            NVec<value_type> operator-(value_type rhs) const noexcept
            {
                NVec<value_type> retval;
                retval.reserve(size());
                std::transform(
                        cbegin(), cend(),
                        std::back_inserter(retval),
                        [rhs](value_type val){return val - rhs;}
                    );
                return retval;
            }

            NVec<value_type>& operator-= (const NVec<value_type>& rhs)
            {
                check_size(rhs);
                std::transform(
                        cbegin(), cend(),
                        rhs.cbegin(),
                        begin(),
                        std::minus<value_type>()
                        );
                return *this;
            }
            
            NVec<value_type>& operator-= (value_type rhs) noexcept
            {
                for (auto& value : *this)
                    value -= rhs;
                return *this;
            }
            
            NVec<value_type> operator* (value_type rhs) const noexcept
            {
                NVec ret;
                ret.reserve(size());
                std::transform(
                        cbegin(), cend(),
                        std::back_inserter(ret),
                        [rhs] (value_type val) { return val * rhs;}
                        );

                return ret;
            }

            value_type operator* (const NVec<value_type>& rhs) const
            {
                check_size(rhs);
                NVec temp;
                value_type sum(0);
                temp.reserve(size());
                std::transform (
                        cbegin(), cend(),
                        rhs.cbegin(),
                        std::back_inserter(temp),
                        std::multiplies<value_type>()
                        );
                sum = std::accumulate(temp.begin(), temp.end(), sum);
                return sum;
            }
            
            NVec<value_type> operator/ (value_type rhs) const noexcept
            {
                NVec ret;
                ret.reserve(size());
                std::transform(
                        cbegin(), cend(),
                        std::back_inserter(ret),
                        [rhs] (value_type val) { return val / rhs;}
                        );

                return ret;
            }

            NVec<value_type> operator-()const noexcept
            {
                NVec<value_type> ret;
                ret.reserve(size());
                std::transform(
                        cbegin(), cend(),
                        std::back_inserter(ret),
                        [](const_reference value) {return -value;}
                        );
                return ret;
            }

            reference operator[](size_type i) noexcept {
                return m_data[i];
            }
            
            const_reference operator[](size_type i) const noexcept {
                return m_data[i];
            }
            
            reference at(size_type i) {
                return m_data[i];
            }
            
            const_reference at(size_type i) const {
                return m_data[i];
            }


            bool operator==(const NVec<value_type>& rhs) const noexcept
            {
                return m_data == rhs.m_data;
            }

            bool operator!=(const NVec<value_type>& rhs) const noexcept
            {
                return !(*this == rhs);
            }

            bool operator<(const NVec<value_type>& rhs) const noexcept
            {
                return this->m_data < rhs.m_data;
            }

            bool operator>(const NVec<value_type>& rhs) const noexcept
            {
                return (rhs < *this);
            }

            bool operator <= (const NVec<value_type>& rhs) const noexcept
            {
                return !(rhs < *this);
            }

            bool operator>=(const NVec<value_type>& rhs) const noexcept
            {
                return !(*this < rhs);
            }

            void push_back(const value_type& value) {
                m_data.push_back(value);
            }
            
            void push_back(value_type&& value) {
                m_data.emplace_back(value);
            }

            void reserve(size_type n) {
                m_data.reserve(n);
            }

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

            NVec<value_type> unit() const
            {
                return *this/magnitude();
            }

        protected:

            void check_size (const NVec<value_type>& rhs) const {
                if (size() != rhs.size())
                    throw VectorSizeMismatch(size(), rhs.size());
            }
    };

    template<class numtype>
    std::ostream& operator<< (std::ostream& stream,
                              const NVec<numtype>& vec)
    {
        std::string out("[");
        typename NVec<numtype>::size_type i = 0;
        if (vec.size() != 0) {
            while (i < vec.size() -1) {
                out += std::to_string(vec[i++]) + ", ";
            }
        }
        while (i < vec.size()) {
            out += std::to_string(vec[i++]);
        }
        out += "]";
        return stream << out;
    }

    template<class T>
    NVec<T> operator + (T lhs, const NVec<T>& rhs) noexcept {
        return rhs + lhs;
    }
    
    template<class T>
    NVec<T> operator * (T lhs, const NVec<T>& rhs) noexcept {
        return rhs * lhs;
    }
    

    extern template class NVec<double>;
    extern template class NVec<float>;

    typedef NVec<double> NVeclf;
    typedef NVec<float> NVecf;

}
