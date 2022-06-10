
#include <vector>
#include <cmath>
#include <string>
#include <ostream>
#include <initializer_list>
#include <algorithm>
#include <iterator>
#include <functional>
#include <numeric>

namespace m3d {

/**
 * Commented away as C++ (11) doesn't allow for abstract return types
 */
//    template <typename numtype>
//    class VectorLike {
//        public:
//            typedef       numtype  value_type;
//            typedef       numtype* pointer;
//            typedef const numtype* const_pointer;
//            typedef       numtype& reference;
//            typedef const numtype& const_reference;
//
//            typedef size_t size_type;
//
//            virtual VectorLike<numtype>     operator+  (const VectorLike& rhs) const = 0;
//            virtual VectorLike<numtype>     operator-  (const VectorLike& rhs) const = 0;
//            virtual VectorLike<numtype>&    operator+= (const VectorLike& rhs) const = 0;
//            virtual VectorLike<numtype>&    operator-= (const VectorLike& rhs) const = 0;
//
//            virtual VectorLike<numtype>     operator*  (numtype) const = 0;
//            virtual VectorLike<numtype>     operator*  (const VectorLike<numtype>& rhs) const = 0;
//            virtual VectorLike<numtype>     operator/  (numtype) const = 0;
//
//            virtual reference               operator[] (size_type i) = 0;
//            virtual const_reference         operator[] (size_type i) const = 0;
//            
//            virtual pointer data() noexcept = 0;
//            virtual const_pointer data() const noexcept = 0;
//
//            virtual numtype magnitude() const noexcept = 0;
//            virtual VectorLike<numtype> normalize() const = 0;
//    };

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
                NVec<value_type> retval;
                retval.reserve(size());
                std::transform(cbegin(), cend(),
                        rhs.cbegin(),
                        std::back_inserter(retval),
                        std::plus<value_type>()
                    );
                return retval;
            }
            
            NVec<value_type> operator+(value_type rhs) const
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
            
            NVec<value_type> operator-(const NVec<value_type>& rhs) const
            {
                NVec<value_type> retval;
                retval.reserve(size());
                std::transform(cbegin(), cend(),
                        rhs.cbegin(),
                        std::back_inserter(retval),
                        std::minus<value_type>()
                    );
                return retval;
            }
            
            NVec<value_type> operator-(value_type rhs) const
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

            reference operator[](size_type i) noexcept {
                return m_data[i];
            }
            
            const_reference operator[](size_type i) const noexcept {
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
            
            void push_back(const value_type&& value) {
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

            NVec<value_type> normalized() const
            {
                NVec<value_type> ret;
                ret.reserve(size());
                value_type mag = magnitude();
                std::transform(
                    cbegin(), cend(),
                    std::back_inserter(ret),
                    [mag](const_reference value) {return value / mag;}
                );
                return ret;
            }
    };

    template<class numtype>
    std::ostream& operator<< (std::ostream& stream,
                              const NVec<numtype>& vec)
    {
        stream << std::string("[");
        auto it = vec.cbegin();
        while (it < vec.cend() -1) {
            stream << *it++ << std::string(", ");
        }
        while (it < vec.cend()) {
            stream << *it++;
        }
        stream << std::string("]");
        return stream;
    }

    extern template class NVec<double>;
    extern template class NVec<float>;

    typedef NVec<double> NVeclf;
    typedef NVec<float> NVecf;

}
