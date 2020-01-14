/*
 * TEST_VEC3 
 * Unit tests for vec3 class
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>

#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>

// unit(s) under test
#include "vec3.hpp"

#define TEST_EPS 1e-8


TEST_CASE("Test vec3 init", "[classic]")
{
    vec3 test_vec1;
    REQUIRE(test_vec1[0] == Approx(0).margin(TEST_EPS));
    REQUIRE(test_vec1[1] == Approx(0).margin(TEST_EPS));
    REQUIRE(test_vec1[2] == Approx(0).margin(TEST_EPS));

    vec3 test_vec2(1.0f, 2.2f, 2.3f);
    REQUIRE(test_vec2[0] == Approx(1.0).margin(TEST_EPS));
    REQUIRE(test_vec2[1] == Approx(2.2).margin(TEST_EPS));
    REQUIRE(test_vec2[2] == Approx(2.3).margin(TEST_EPS));
}


// Arithmetic tests 

// Test add
TEST_CASE("Test vec3 add", "[classic]")
{
    vec3 v1(0.0, 0.0, 0.1);
    vec3 v2(0.0, 0.0, 0.1);
    vec3 v3;

    REQUIRE(v1[0] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v1[1] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v1[2] == Approx(0.1).margin(TEST_EPS));

    REQUIRE(v3[0] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v3[1] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v2[2] == Approx(0.1).margin(TEST_EPS));

    // Do the add
    v3 = v1 + v2;
    REQUIRE(v3[0] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v3[1] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v3[2] == Approx(0.2).margin(TEST_EPS));
    
}


// Test sub
TEST_CASE("Test vec3 subtract", "[classic]")
{
    vec3 v1(0.0, 0.4, 0.2);
    vec3 v2(0.0, 0.2, 0.1);
    vec3 v3;

    v3 = v1 - v2;
    REQUIRE(v3[0] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v3[1] == Approx(0.2).margin(TEST_EPS));
    REQUIRE(v3[2] == Approx(0.1).margin(TEST_EPS));
}

// Test sub-assign
TEST_CASE("Test vec3 subtract-and-assign", "[classic]")
{
    vec3 v1(0.0, 0.4, 0.2);
    vec3 v2(0.0, 0.2, 0.1);

    v2 -= v1;
    REQUIRE(v2[0] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v2[1] == Approx(-0.2).margin(TEST_EPS));
    REQUIRE(v2[2] == Approx(-0.1).margin(TEST_EPS));
}


// Test mult
TEST_CASE("Test vec3 multiply", "[classic]")
{
    vec3 v1(1.0, 0.4, 0.2);
    vec3 v2(1.0, 0.2, 0.2);
    vec3 v3;

    v3 = v1 * v2;
    REQUIRE(v3[0] == Approx(1.0 ).margin(TEST_EPS));
    REQUIRE(v3[1] == Approx(0.08).margin(TEST_EPS));
    REQUIRE(v3[2] == Approx(0.04).margin(TEST_EPS));
}

// Test mul-assign
TEST_CASE("Test vec3 multiply-assign", "[classic]")
{
    vec3 v1(0.0, 0.4, 0.2);
    vec3 v2(0.0, -0.2, -0.1);

    v2 *= v1;
    REQUIRE(v2[0] == Approx(0.0).margin(TEST_EPS));
    REQUIRE(v2[1] == Approx(-0.08).margin(TEST_EPS));
    REQUIRE(v2[2] == Approx(-0.02).margin(TEST_EPS));
}


// Test div
TEST_CASE("Test vec3 divide", "[classic]")
{
    vec3 v1(1.0, 0.4, 0.2);
    vec3 v2(1.0, 0.2, 0.2);
    vec3 v3;

    v3 = v1 / v2;
    REQUIRE(v3[0] == Approx(1.0).margin(TEST_EPS));
    REQUIRE(v3[1] == Approx(2.0).margin(TEST_EPS));
    REQUIRE(v3[2] == Approx(1.0).margin(TEST_EPS));
}

// Test vec3 div by float
TEST_CASE("Test vec3 divide by float", "[classic]")
{
    vec3 v1(1.0, 0.4, 0.2);
    vec3 v2;
    float t = 2.0f;

    v2 = v1 / t;
    REQUIRE(v2[0] == Approx(0.5 ).margin(TEST_EPS));
    REQUIRE(v2[1] == Approx(0.20).margin(TEST_EPS));
    REQUIRE(v2[2] == Approx(0.10).margin(TEST_EPS));
}

// Test vec3 div-assign
TEST_CASE("Test vec3 divide and assign", "[classic]")
{
    vec3 v1(1.0, 0.4, 0.2);
    vec3 v2(2.0, -0.2, -0.1);

    v2 /= v1;
    REQUIRE(v2[0] == Approx(2.0 ).margin(TEST_EPS));
    REQUIRE(v2[1] == Approx(-0.5).margin(TEST_EPS));
    REQUIRE(v2[2] == Approx(-0.5).margin(TEST_EPS));
}

// Length 
TEST_CASE("Test vec3 length", "[classic]")
{
    vec3 test_vec1(1.0, 1.0, 1.0);
    vec3 test_vec2(2.0, 0.5, 0.2);

    REQUIRE(test_vec1.length() == Approx(1.7320508).margin(TEST_EPS));      // this value is close enough for the test
    REQUIRE(test_vec2.length() == Approx(2.071231517720798).margin(TEST_EPS));
}

// Squared length
TEST_CASE("Test vec3 squared length", "[classic]")
{
    vec3 test_vec1(1.0, 1.0, 1.0);
    vec3 test_vec2(2.0, 0.5, 0.2);

    REQUIRE(test_vec1.squared_length()  == Approx(3.0).margin(TEST_EPS));
    REQUIRE(test_vec2.squared_length() == Approx(4.29).margin(TEST_EPS));
}


// Vector arithmetic 
TEST_CASE("Test vec3 dot product", "[classic]")
{
    vec3 test_vec1(1.0, 1.0, 1.0);
    vec3 test_vec2(1.0, 1.0, 1.0);
    float dot_output;

    dot_output = dot(test_vec1, test_vec2);
    REQUIRE(dot_output == Approx(3.0).margin(TEST_EPS));

    // update vectors
    test_vec1 += vec3(1.0, 0.0, 0.5);
    test_vec2 += vec3(2.0, 2.0, 2.5);
    // check the updates were applied
    REQUIRE(Approx(2.0).margin(TEST_EPS) == test_vec1[0]);
    REQUIRE(Approx(1.0).margin(TEST_EPS) == test_vec1[1]);
    REQUIRE(Approx(1.5).margin(TEST_EPS) == test_vec1[2]);

    REQUIRE(Approx(3.0).margin(TEST_EPS) == test_vec2[0]);
    REQUIRE(Approx(3.0).margin(TEST_EPS) == test_vec2[1]);
    REQUIRE(Approx(3.5).margin(TEST_EPS) == test_vec2[2]);

    dot_output = dot(test_vec1, test_vec2);
    REQUIRE(Approx(14.25).margin(TEST_EPS) == dot_output);
}

// Test vec3 cross product
TEST_CASE("Test vec3 cross product", "[classic]")
{
    vec3 test_vec1(1.0, 1.0, 1.0);
    vec3 test_vec2(1.0, 1.0, 1.0);
    vec3 cross_output;

    cross_output = cross(test_vec1, test_vec2);

    REQUIRE(Approx(0.0 ).margin(TEST_EPS) == cross_output[0]);
    REQUIRE(Approx(-2.0).margin(TEST_EPS) == cross_output[1]);
    REQUIRE(Approx(0.0 ).margin(TEST_EPS) == cross_output[2]);
    
    // update vectors 
    test_vec1 += vec3(1.0, 1.0, 1.0);
    // test_vec1 = (2.0, 2.0, 2.0)
    cross_output = cross(test_vec1, test_vec2);
    REQUIRE(Approx(0.0).margin(TEST_EPS)  == cross_output[0]);
    REQUIRE(Approx(-4.0).margin(TEST_EPS) == cross_output[1]);
    REQUIRE(Approx(0.0).margin(TEST_EPS)  == cross_output[2]);

    // update vectors again
    test_vec2 = vec3(-1.0, -2.0, -3.0);
    // test_vec2 = (-2.0, -3.0, -4.0)
    cross_output = cross(test_vec1, test_vec2);
    REQUIRE(Approx(-2.0).margin(TEST_EPS) == cross_output[0]);
    REQUIRE(Approx(8.0 ).margin(TEST_EPS) == cross_output[1]);
    REQUIRE(Approx(-2.0).margin(TEST_EPS) == cross_output[2]);
}
