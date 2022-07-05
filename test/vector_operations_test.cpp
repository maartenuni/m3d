
#include "m3d/Vector.hpp"
#include "m3d/vector_functions.hpp"
#include <cmath>
#include <doctest.h>

using m3d::Vector3lf;
using m3d::NVeclf;
using m3d::cross;
using m3d::angle;
using m3d::angle_deg;

TEST_CASE("distance") {
    // cardinal axis
    const Vector3lf xc = {1,0,0};
    const Vector3lf yc = {0,1,0};
    const Vector3lf zc = {0,0,1};

    CHECK(distance(xc, yc) == std::sqrt(1 + 1));
    CHECK(distance(xc, zc) == std::sqrt(1 + 1));
    CHECK(distance(yc, zc) == std::sqrt(1 + 1));

    CHECK(distance(xc, yc) == distance(yc, xc));
    CHECK(distance(xc, zc) == distance(zc, xc));
    CHECK(distance(zc, yc) == distance(yc, zc));
}

TEST_CASE("distance nvec") {
    // cardinal axis
    const NVeclf xc = {1,0,0};
    const NVeclf yc = {0,1,0};
    const NVeclf zc = {0,0,1};

    CHECK(distance(xc, yc) == std::sqrt(1 + 1));
    CHECK(distance(xc, zc) == std::sqrt(1 + 1));
    CHECK(distance(yc, zc) == std::sqrt(1 + 1));

    CHECK(distance(xc, yc) == distance(yc, xc));
    CHECK(distance(xc, zc) == distance(zc, xc));
    CHECK(distance(zc, yc) == distance(yc, zc));
}

TEST_CASE("Vector cross product") {
    // cardinal axis
    const Vector3lf xc = {1,0,0};
    const Vector3lf yc = {0,1,0};
    const Vector3lf zc = {0,0,1};

    CHECK(cross(xc, yc) == zc);
    CHECK(cross(yc, zc) == xc);
    CHECK(cross(zc, xc) == yc);
    
    CHECK(cross(yc, xc) == -zc);
    CHECK(cross(zc, yc) == -xc);
    CHECK(cross(xc, zc) == -yc);
}

TEST_CASE("Vector angle") {
    // cardinal axis
    const Vector3lf xc = {1,0,0};
    const Vector3lf yc = {0,1,0};
    const Vector3lf zc = {0,0,1};
    
    const Vector3lf xy = {1,1,0};

    const Vector3lf::value_type half_pi = M_PI/2;

    CHECK(angle(xc, yc) == doctest::Approx(half_pi));
    CHECK(angle(yc, zc) == doctest::Approx(half_pi));
    CHECK(angle(zc, xc) == doctest::Approx(half_pi));
    
    CHECK(angle(yc, xc) == doctest::Approx(half_pi));
    CHECK(angle(zc, yc) == doctest::Approx(half_pi));
    CHECK(angle(xc, zc) == doctest::Approx(half_pi));

    CHECK(angle(xy, xc) == doctest::Approx(half_pi/2));
}

TEST_CASE("Vector angle degrees") {
    // cardinal axis
    const Vector3lf xc = {1,0,0};
    const Vector3lf yc = {0,1,0};
    const Vector3lf zc = {0,0,1};
    
    const Vector3lf xy = {1,1,0};

    const Vector3lf::value_type ninety = 90;
    const Vector3lf::value_type fortyfive = 45;

    CHECK(angle_deg(xc, yc) == doctest::Approx(ninety));
    CHECK(angle_deg(yc, zc) == doctest::Approx(ninety));
    CHECK(angle_deg(zc, xc) == doctest::Approx(ninety));
    
    CHECK(angle_deg(yc, xc) == doctest::Approx(ninety));
    CHECK(angle_deg(zc, yc) == doctest::Approx(ninety));
    CHECK(angle_deg(xc, zc) == doctest::Approx(ninety));
    
    CHECK(angle_deg(xy, xc) == doctest::Approx(fortyfive));
}

TEST_CASE("NVec angle") {
    // cardinal axis
    const NVeclf xc = {1,0,0};
    const NVeclf yc = {0,1,0};
    const NVeclf zc = {0,0,1};
    
    const NVeclf xy = {1,1,0};

    const NVeclf::value_type half_pi = M_PI/2;
    auto deg = angle(xc, yc);

    CHECK(angle(xc, yc) == doctest::Approx(half_pi));
    CHECK(angle(yc, zc) == doctest::Approx(half_pi));
    CHECK(angle(zc, xc) == doctest::Approx(half_pi));
    
    CHECK(angle(yc, xc) == doctest::Approx(half_pi));
    CHECK(angle(zc, yc) == doctest::Approx(half_pi));
    CHECK(angle(xc, zc) == doctest::Approx(half_pi));

    CHECK(angle(xy, xc) == doctest::Approx(half_pi/2));
}

TEST_CASE("NVec angle degrees") {
    // cardinal axis
    const NVeclf xc = {1,0,0};
    const NVeclf yc = {0,1,0};
    const NVeclf zc = {0,0,1};
    
    const NVeclf xy = {1,1,0};

    const NVeclf::value_type ninety = 90;
    const NVeclf::value_type fortyfive = 45;

    auto deg = angle_deg(xc, yc);

    CHECK(angle_deg(xc, yc) == doctest::Approx(ninety));
    CHECK(angle_deg(yc, zc) == doctest::Approx(ninety));
    CHECK(angle_deg(zc, xc) == doctest::Approx(ninety));
    
    CHECK(angle_deg(yc, xc) == doctest::Approx(ninety));
    CHECK(angle_deg(zc, yc) == doctest::Approx(ninety));
    CHECK(angle_deg(xc, zc) == doctest::Approx(ninety));
    
    CHECK(angle_deg(xy, xc) == doctest::Approx(fortyfive));
}

