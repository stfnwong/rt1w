/*
 * TEST_RAY 
 * Unit tests for ray class
 *
 * Stefan Wong 2019
 */

#define CATCH_CONFIG_MAIN
#include "catch/catch.hpp"
//#include <catch2/catch.hpp>

#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
// unit(s) under test
#include "vec3.hpp"
#include "Ray.hpp"


TEST_CASE("test ray initialization", "[classic]")
{
    Ray test_ray;

    REQUIRE(test_ray.A[0] == 0.0);
    REQUIRE(test_ray.A[1] == 0.0);
    REQUIRE(test_ray.A[2] == 0.0);

    REQUIRE(test_ray.B[0] == 0.0);
    REQUIRE(test_ray.B[1] == 0.0);
    REQUIRE(test_ray.B[2] == 0.0);
}
