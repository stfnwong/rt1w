/*
 * TEST_SPHERE 
 * Unit tests for Sphere .
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
#include "Ray.hpp"
#include "Material.hpp"
#include "Sphere.hpp"


TEST_CASE("test sphere init", "[classic]")
{
    Metal *mat;
    Sphere* sphere_obj;
    vec3 center(0.0, 0.0, -0.1);
    float r = 2.1;

    vec3 metal_albedo(0.8, 0.2, 0.3);
    mat = new Metal(metal_albedo, 0.5);
    sphere_obj = new Sphere(center, r, mat);

    //REQUIRE(sphere_obj->mat

    delete sphere_obj;
}
