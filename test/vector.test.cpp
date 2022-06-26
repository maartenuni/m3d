
#include <m3d/Vector.hpp>

#include <iostream>


int main() {
    using namespace m3d;
    Vector2lf v1{1, 0};
    Vector2lf v2{2, 2};
    
    Vector4lf v3{2, 2, 8, 9};
    Vector4lf v4{1, 0, -2, -7};

    std::cout << v1 << " * " << v2 << " = " << v1 * v2 << std::endl;
    std::cout << v3 << " * " << v4 << " = " << v3 * v4 << std::endl;
}
