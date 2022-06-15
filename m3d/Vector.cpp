

#include "Vector.hpp"

namespace m3d {

    // template instantiation
    template struct Vector<double, 2>;
    template struct Vector<double, 3>;
    template struct Vector<double, 4>;

    template struct Vector<float, 2>;
    template struct Vector<float, 3>;
    template struct Vector<float, 4>;

}
