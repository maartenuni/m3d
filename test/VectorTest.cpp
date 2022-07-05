
#include "doctest.h"
#include "m3d/Vector.hpp"
#include <stdexcept>

using m3d::Vector4lf;

TEST_CASE("Vector construction") {
    const Vector4lf vec = {1,2,3,4};
    REQUIRE(vec == Vector4lf{1,2,3,4});

    SUBCASE ("Check vector elements after construction") {
        CHECK(vec[0] == Vector4lf::value_type(1));
        CHECK(vec[1] == Vector4lf::value_type(2));
        CHECK(vec[2] == Vector4lf::value_type(3));
        CHECK(vec[3] == Vector4lf::value_type(4));
    }

    SUBCASE ("Check size after construction") {
        CHECK(vec.size() == 4);
    }
}

TEST_CASE("Test vector addition") {
    const Vector4lf v1234  = {1,2,3,4};
    const Vector4lf result = v1234 * 2.0;
    const Vector4lf null{0,0,0,0};

    SUBCASE("Test scalar addition") {
        CHECK(Vector4lf{2,3,4,5} == v1234 + 1);
    }
    
    SUBCASE("Test vector addition") {
        CHECK(result == v1234 + v1234);
    }

    SUBCASE ("test vector AdditiveIdentity") {
        CHECK(v1234 == (null + v1234));
        CHECK(v1234 == (v1234 + null));
    }

    SUBCASE("test operator +=") {
        Vector4lf null{0,0,0,0};
        null += v1234;
        CHECK(null == v1234);
    }
}

TEST_CASE ("test vector subtraction")
{
    const Vector4lf v1234 = {1,2,3,4};
    const Vector4lf null{};

    SUBCASE("test inverse additive Identity") {
        CHECK( null ==  v1234 + -v1234);
        CHECK( null == -v1234 + v1234);
    }
}

TEST_CASE ("Test vector scaling") {
    const Vector4lf v1234  = {1,2,3,4};
    const Vector4lf::value_type scalar = 2.0;
    const Vector4lf::value_type minus_one= -1.0;
    const Vector4lf result = {
        v1234[0] * scalar, v1234[1] * scalar, scalar * v1234[2], scalar * v1234[3]
    };
    const Vector4lf negative1234 = -v1234; 

    SUBCASE("Test scaling by 2") {
        CHECK(result == v1234 * scalar);
        CHECK(result == scalar * v1234);
        CHECK(v1234.magnitude() * scalar == (v1234 * scalar).magnitude());
    }
    SUBCASE("Test whether scaling by -1 equals negating a Vector") {
        CHECK(negative1234 == v1234 * minus_one);
        CHECK(v1234.magnitude() == (v1234 * minus_one).magnitude());
    }
}

TEST_CASE("Test Vector dot product") {
    using m3d::Vector2lf;
    const Vector2lf v10  {1, 0};
    const Vector2lf v01  {0, 1};
    const Vector2lf v11  {1, 1};
    const Vector2lf vneg {-1, -1};

    const Vector4lf v1234{1,2,3,4};
    const Vector4lf v1111{1,1,1,1};

    SUBCASE("Test dot product on perpendicular vectors") {
        CHECK(v10 * v01 == doctest::Approx(0.0));
        CHECK(v01 * v10 == doctest::Approx(0.0));
    }
    SUBCASE("Test dot product on acute angle") {
        CHECK(v11 * v10 > 0.0 );
        CHECK(v01 * v11 > 0.0);
    }
    SUBCASE("Test dot product on obtuse angle") {
        CHECK(vneg * v10 < 0.0);
        CHECK(v01 * vneg < 0.0);
    }
    SUBCASE("Test dot product is commutative") {
        CHECK(v10 * v01 == v01 * v10);
        CHECK(v10 * vneg == vneg * v10);
    }
    SUBCASE("Test dot product is acurate") {
        CHECK(v1234 * v1111 == 10.0);
    }
}



TEST_CASE ("Test vector scalar division") {
    const Vector4lf v1234  = {1,2,3,4};
    const Vector4lf::value_type scalar = 2.0;
    const Vector4lf result = {
        v1234[0] / scalar, v1234[1] / scalar, v1234[2] / scalar, v1234[3] / scalar
    };

    SUBCASE("Test scalar division by 2") {
        CHECK(result == v1234 / scalar);
        CHECK(v1234.magnitude() / scalar == (v1234 / scalar).magnitude());
    }
    SUBCASE("Test whether dividing by x is equal to multiplying with its inverse") {
        CHECK(v1234 / scalar == v1234 *(1/scalar));
    }
}

TEST_CASE("Test vector logical operators") {
    const Vector4lf v1234{1,2,3,4};
    const Vector4lf v5432{5,4,3,2};
    const Vector4lf v1copy = v1234;
    const Vector4lf v2copy{5,4,3,2};

    SUBCASE("Check equality operators") {
        CHECK(v1234 == v1234);
        CHECK(v1234 == v1copy);
        CHECK(!(v1234 == v5432));
    }
    SUBCASE("Check inequality operators") {
        CHECK(v1234 != v2copy);
        CHECK(!(v1234 != v1234));
        CHECK(v1234 != v5432);
    }
}

TEST_CASE("Test vector element access") {

    Vector4lf v1{1,2,3,4};
    CHECK(v1[0] == 1);
    CHECK(v1[1] == 2);
    CHECK(v1[2] == 3);
    CHECK(v1[3] == 4);
    CHECK(v1.at(0) == 1);
    CHECK(v1.at(1) == 2);
    CHECK(v1.at(2) == 3);
    CHECK(v1.at(3) == 4);

    v1[0] = 0;
    v1[1] = 0;
    v1.at(2) = 0;
    v1.at(3) = 0;

    CHECK(v1 == Vector4lf{});
    CHECK_THROWS_AS(v1.at(4), std::out_of_range);
    CHECK_THROWS_AS(v1.at(-1), std::out_of_range);
}

TEST_CASE("Test vector element access") {
    Vector4lf v1{1,2,3,4};
    Vector4lf v2 = v1 * 2.0;
    Vector4lf unit = v1.unit();

    SUBCASE("unitvector is of unit length") {
        CHECK(unit.magnitude() == doctest::Approx(1.0));
    }

    SUBCASE("Check if a scaled array has the same direction") {
        CHECK(v2.unit() == unit);
    }
}


