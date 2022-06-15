
#include <m3d/NVec.hpp>
#include <iostream>
#include <iomanip>

int main() {
    m3d::NVec<double> v0(3, 0);
    m3d::NVec<double> range_copy(v0.begin(), v0.end());
    std::cout << v0 << std::endl;
    std::cout << m3d::NVec<double>() << std::endl;

    std::cout << m3d::NVec<>{0,1,3.141592654} << std::endl;

    m3d::NVec<> v1 = {1,2,3};
    m3d::NVec<> v2 = {2,3,4};
    std::cout << v0 << " == " << v0 << " = " << (v0 == v0) << std::endl;
    std::cout << v0 << " == " << v1 << " = " << (v0 == v1) << std::endl;
    std::cout << v0 << " != " << v1 << " = " << (v0 != v1) << std::endl;
    std::cout << v1 << " + " << v2 << " = " << v1 + v2 << std::endl;
    std::cout << v1 << " + " << 2 << " = " << v1 + 2 << std::endl;
    std::cout << v1 << " - " << v2 << " = " << v1 - v2 << std::endl;
    std::cout << v1 << " - " << 2 << " = " << v1 - 2 << std::endl;
    std::cout << v1 << ".magnitude = " << v1.magnitude() << std::endl;
    std::cout << v1 << ".unit = " << v1.unit() << std::endl;
    std::cout << v1 << ".unit.magnitude = " << v1.unit().magnitude() << std::endl;

}

